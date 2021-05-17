#include <iostream>
#include <vector>
#include "template.h"

int main() {
    std::vector<int> arr{1, 10, 1};
    const auto &compare = [](int x, int y) { return x >= y; };
    const auto &palindrome_compare = [](int x, int y) { return x == y; };
    const auto &pred = [](int x) { return x < 10; };

    std::cout << "1) " << allOf(&arr[0], &arr[arr.size() - 1], pred) << std::endl;
    std::cout << "2) " << anyOf(&arr[0], &arr[arr.size() - 1], pred) << std::endl;
    std::cout << "3) " << noneOf(&arr[0], &arr[arr.size() - 1], pred) << std::endl;
    std::cout << "4) " << oneOf(&arr[0], &arr[arr.size() - 1], pred) << std::endl;
    std::cout << "5) " << isSorted(&arr[0], &arr[arr.size() - 1]) << std::endl;
    std::cout << "6) " << isSorted(&arr[0], &arr[arr.size() - 1], compare) << std::endl;
    std::cout << "7) " << isPartitioned(&arr[0], &arr[arr.size() - 1], pred) << std::endl;
    std::cout << "8) " << *findNot(&arr[0], &arr[arr.size() - 1], 10) << std::endl;
    std::cout << "9) " << *findBackward(&arr[0], &arr[arr.size() - 1], 10) << std::endl;
    std::cout << "10) " << isPalindrome(&arr[0], &arr[arr.size() - 1], palindrome_compare) << std::endl;
    return 0;
}
