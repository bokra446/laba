#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "util.h"
#include "EncryptFunction.h"

int main() {
    const char* allowedFlags[] = {"xor", "caesar"};
    char flag[7];
    char str[80], key[80];
    int shift;
    printf("Выберите способ исходный шифрования (xor или caesar)\n");
    scanf("%s", flag);
    if (!strcmp(allowedFlags[0], flag)) {
        printf("Дешифруемая строка: ");
        scanf(" %99[^\n]", str);
        mutableStrip(str);
        mutableToLower(str);
        printf("Ключ: ");
        scanf(" %99[^\n]", key);
        mutableDecoderXor(str, key);
    }
    else if (!strcmp(allowedFlags[1], flag)) {
        printf("Дешифруемая строка: ");
        scanf(" %99[^\n]", str);
        mutableStrip(str);
        mutableToLower(str);
        printf("Сдвиг (изначальное положительное число): ");
        scanf("%d", &shift);
        mutableDecoderCaesar(str, (shift * (-1)));
    }
    else {
        printf("Неккоректные данные ");
        return 1;;
    }
    puts(str);
    return 0;
}