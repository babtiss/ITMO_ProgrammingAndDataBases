


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int Reverse(unsigned int Size) { // Парсим по маске
    return ((Size >> 24) & 0x000000ff) | ((Size >> 8) & 0x0000ff00) | ((Size << 8) & 0x00ff0000) | ((Size << 24) & 0xff000000);
}

typedef union Tag {
    char Buffer[12];
    struct TagData{
        unsigned short int Empty;
        unsigned char Version[3];
        unsigned char Version_1;
        unsigned char Version_2;
        unsigned char Flags;
        unsigned int Size;
    } TagData;
} TagTag;

typedef union Frame {
    char Buffer[10];
    struct FrameData{
        unsigned char Name[4];
        unsigned int Size;
        unsigned short int Flags;
    } FrameData;
} FrameTag;

void Copy(FILE *Input, FILE *Output) {
    int Char;
    while ((Char = getc(Input)) != EOF) {
        putc(Char, Output);
    }
}
void Show(char *FileName) {
    FILE* File = fopen(FileName, "rb");
    fseek(File, 0, 0);
    TagTag Tag;
    fread(Tag.Buffer + 2, sizeof(char), 10, File);
    unsigned int TagSize = Reverse(Tag.TagData.Size);
    printf("%sv%d.%d\n", Tag.TagData.Version, Tag.TagData.Version_1, Tag.TagData.Version_2);
    while (ftell(File) < TagSize + 10) {
        FrameTag Frame;
        fread(Frame.Buffer, sizeof(char), 10, File);
        if (Frame.FrameData.Name[0] == 0) {
            break;
        }
        printf("%s: ", Frame.FrameData.Name);
        unsigned int FrameSize = Reverse(Frame.FrameData.Size);
        unsigned char* FrameContent = malloc(sizeof(char) *FrameSize);
        fread(FrameContent, sizeof(char), FrameSize, File);
        for (int i = 0; i < FrameSize; ++i) {
            printf("%c", FrameContent[i]);
        }
        printf("\n");
        free(FrameContent);
    }
    fclose(File);
}

void Get(char *FileName, char FrameName[4]) {
    FILE* File = fopen(FileName, "rb");
    TagTag Tag;
    fread(Tag.Buffer + 2, sizeof(char), 10, File);
    unsigned int TagSize = Reverse(Tag.TagData.Size);
    while (ftell(File) < TagSize + 10) {
        FrameTag Frame;
        fread(Frame.Buffer, sizeof(char), 10, File);
        unsigned int FrameSize = Reverse(Frame.FrameData.Size);
        if (strcmp((char*)Frame.FrameData.Name, FrameName) == 0) {
            printf("%s: ", Frame.FrameData.Name);
            unsigned char *FrameContent = malloc(sizeof(char) *FrameSize);
            fread(FrameContent, sizeof(char), FrameSize, File);
            for (int i = 0; i < FrameSize; ++i) {
                printf("%c", FrameContent[i]);
            }
            printf("\n");
            free(FrameContent);
            fclose(File);
            return;
        }
        fseek(File, FrameSize, 1);
    }
    fclose(File);
}

void Set(char *FileName, char FrameName[4], char *FrameValue) {
    FILE* File = fopen(FileName, "rb");
    TagTag Tag;
    fread(Tag.Buffer + 2, sizeof(char), 10, File);
    unsigned int TagSize = Reverse(Tag.TagData.Size), OldFramePosition = 0, OldFrameSize = 0;
    while (ftell(File) < TagSize + 10) {
        FrameTag Frame;
        fread(Frame.Buffer, sizeof(char), 10, File);
        unsigned int FrameSize = Reverse(Frame.FrameData.Size);
        if (strcmp((char*)Frame.FrameData.Name, FrameName) == 0) {
            OldFramePosition = (unsigned int)ftell(File) - 10;
            OldFrameSize = FrameSize;
            break;
        }
        fseek(File, FrameSize, 1);
    }
    unsigned int ValueSize = (unsigned int)strlen(FrameValue), NewTagSize = TagSize - OldFrameSize + ValueSize + 10 * (OldFramePosition != 0); // просто новые переменные
    if (OldFramePosition == 0) {
        OldFramePosition = (unsigned int)ftell(File);
    }
    if (ValueSize == 0) {
        NewTagSize -= 10;
    }
    FILE* FileCopy = fopen("t.mp3", "wb");
    fseek(File, 0, 0);
    fseek(FileCopy, 0, 0);
    Copy(File, FileCopy);
    fclose(File);
    fclose(FileCopy);
    FileCopy = fopen("t.mp3", "rb");
    File = fopen(FileName, "wb");
    Tag.TagData.Size = Reverse(NewTagSize);
    fwrite(Tag.Buffer + 2, sizeof(char), 10, File);
    fseek(FileCopy, 10, 0);
    for (int i = 0; i < OldFramePosition - 10; ++i) {
        int Char = getc(FileCopy);
        putc(Char, File);
    }
    if (ValueSize > 0) {
        FrameTag Frame;
        for (int i = 0; i < 4; ++i)
            Frame.FrameData.Name[i] = FrameName[i];
        Frame.FrameData.Size = Reverse(ValueSize);
        Frame.FrameData.Flags = 0;
        fwrite(Frame.Buffer, sizeof(char), 10, File);
    }
    fwrite(FrameValue, sizeof(char), ValueSize, File);
    fseek(FileCopy, OldFramePosition + 10 + OldFrameSize, 0);
    for (int i = (int)ftell(File); i < NewTagSize; ++i) {
        int Char = getc(FileCopy);
        putc(Char, File);
    }
    printf("Новое значение для %s: %s\n", FrameName, FrameValue);
    Copy(FileCopy, File);
    fclose(File);
    fclose(FileCopy);
    remove("t.mp3");
}

int main(int argc, char *argv[]) {
    char *FileName = NULL, *FrameName = NULL, *Value = NULL, ShowFlag = 0, SetFlag = 0, GetFlag = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--show") == 0) {
            ShowFlag = 1;
            continue;
        }
        if (argv[i][2] == 'f') {
            FileName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 'g') {
            GetFlag = 1;
            FrameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 's') {
            SetFlag = 1;
            FrameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 'v') {
            Value = strpbrk(argv[i], "=") + 1;
            continue;
        }
    }
    if (ShowFlag) {
        Show(FileName);
    }
    if (GetFlag) {
        Get(FileName, FrameName);
    }
    if (SetFlag) {
        Set(FileName, FrameName, Value);
    }
}
/*
 --show - отображение всей метаинформации в виде таблицы
 --set=prop_name --value=prop_value — выставляет значение определенного поля метаинформации с именем prop_name в значение prop_value
 --get=prop_name - вывести определенное поле метаинформации с именем prop_name
    13lab.exe --filepath="b.mp3" --show
 */