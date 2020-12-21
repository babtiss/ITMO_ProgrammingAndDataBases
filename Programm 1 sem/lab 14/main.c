#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>

int check(int **life, int i, int j, const int hei, const int wid) {
    int count = 0;
    if (i + 1 < hei && j - 1 >= 0 && life[i + 1][j - 1] == 1)
        count++;
    if (i + 1 < hei && life[i + 1][j] == 1)
        count++;
    if (i + 1 < hei && j + 1 < wid && life[i + 1][j + 1] == 1)
        count++;
    if (j - 1 >= 0 && life[i][j - 1] == 1)
        count++;
    if (j + 1 < wid && life[i][j + 1] == 1)
        count++;
    if (i - 1 >= 0 && j - 1 >= 0 && life[i - 1][j - 1] == 1)
        count++;
    if (i - 1 >= 0 && life[i - 1][j] == 1)
        count++;
    if (i - 1 >= 0 && j + 1 < wid && life[i - 1][j + 1] == 1)
        count++;

    return count;
}

void GameLife(int **life, const int hei, const int wid) {

    int** tmp = (int**)malloc(hei * sizeof(int*));
    for (int i = 0; i < hei; i++)
        tmp[i] = (int*)malloc(wid * sizeof(int));

    for (int i = 0; i < hei; i++)
        for (int j = 0; j < wid; j++)
            tmp[i][j] = life[i][j];

    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < wid; j++) {
            int c = check(life, i, j, hei, wid);
            if ((c == 2 || c == 3) && life[i][j] == 1)
                tmp[i][j] == 1;
            else if (c == 3 && life[i][j] == 0)
                tmp[i][j] = 1;
            else
                tmp[i][j] = 0;
        }
    }

    int b = 1;
    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < wid; j++) {
            if (life[i][j] != tmp[i][j]) {
                b = 0;
                break;
            }
        }
    }
    if (b)
        exit(0);

    b = 0;
    for (int i = 0; i < hei; i++) {
        for (int j = 0; j < wid; j++) {
            if (tmp[i][j] == 0)
                b++;
            life[i][j] = tmp[i][j];
        }
    }

    if (b == hei * wid)
        exit(0);
}

struct bmp {
    int Width;
    int Height;
    int Size;
};
int atoi(const char* c){
    int i = 0;
    int ans = 0;
    while (c[i] != '\0'){
        if (c[i] == '0'){
            ans = ans * 10;
        }
        else if (c[i] == '1'){
            ans = ans * 10 + 1;
        }
        else if (c[i] == '2'){
            ans = ans * 10 + 2;
        }
        else if (c[i] == '3'){
            ans = ans * 10 + 3;
        }
        else if (c[i] == '4'){
            ans = ans * 10 + 4;
        }
        else if (c[i] == '5'){
            ans = ans * 10 + 5;
        }
        else if (c[i] == '6'){
            ans = ans * 10 + 6;
        }
        else if (c[i] == '7'){
            ans = ans * 10 + 7;
        }
        else if (c[i] == '8'){
            ans = ans * 10 + 8;
        }
        else if (c[i] == '9'){
            ans = ans * 10 + 9;
        }
        i++;
    }
    return ans;
}


int main(int argc, char *argv[]) {
    struct bmp bmp;
    int MaximumIteration = 50;
    int freq = 1;
    unsigned char header[54];
    char *dirname = NULL;
    _mkdir(dirname);
    FILE* file = NULL;

    if (!strcmp("--input", argv[1])) {
        file = fopen(argv[2], "rb");
    }
    if (!strcmp("--output", argv[3])) {
        dirname = argv[4];
        _mkdir(argv[4]);
    }

    if (file == NULL)
        exit(0);

    for (int i = 1; i < argc; i++) {
        if (!strcmp("--max_iter", argv[i])) {
            MaximumIteration = atoi(argv[i + 1]);
        }
        if (!strcmp("--dump_freq", argv[i])) {
            freq = atoi(argv[i + 1]);
        }
    }

    fread(header, 1, 54, file);
    bmp.Width = header[21] * 256 * 256 * 256 + header[20] * 256 * 256 + header[19] * 256 + header[18];
    bmp.Height = header[25] * 256 * 256 * 256 + header[24] * 256 * 256 + header[23] * 256 + header[22];
    bmp.Size = header[5] * 256 * 256 * 256 + header[4] * 256 * 256 + header[3] * 256 + header[2];
    unsigned char *ImageByte = (unsigned char*)malloc((bmp.Size - 54) * sizeof(unsigned char));
    fread(ImageByte, 1, bmp.Size, file);

    int** ImageArray = (int**)malloc(bmp.Height * sizeof(int*));
    for (int i = 0; i < bmp.Height; i++)
        *(ImageArray + i) = (int*)malloc(bmp.Width * sizeof(int));

    int k = 0;
    for (int i = bmp.Height - 1; i >= 0; i--) {
        for (int j = 0; j < bmp.Width; j++) {
            if (ImageByte[k] == 255)
                ImageArray[i][j] = 0;
            else
                ImageArray[i][j] = 1;
            k += 3;
        }
    }

    for (int l = 0; l <= MaximumIteration; l++) {
        if (l % freq == 0) {
            char filename[10];
            char way[20];
            strcpy(way, dirname);
            strcat(strcat(way, "\\"), strcat(_itoa(l, filename, 10), ".bmp"));
            FILE* life = fopen(way, "w");
            fwrite(header, 1, 54, life);
            int m = 0;

            for (int i = bmp.Height - 1; i >= 0; i--) {
                for (int j = 0; j < bmp.Width; j++) {
                    for (k = 0; k < 3; k++) {
                        if (ImageArray[i][j] == 1)
                            ImageByte[m] = 0;
                        else
                            ImageByte[m] = 255;
                        m++;
                    }
                }
                ImageByte[m] = 0;
            }
            fwrite(ImageByte, 1, bmp.Size, life);
            fclose(life);
        }
        GameLife(ImageArray, bmp.Height, bmp.Width);
    }
    free(ImageArray);
    return 0;
}
//--input c.bmp --output dir --max_iter 10 --dump_freq 1