#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "util.h"
#include "EncryptFunction.h"

int main (const int argc, char* argv[]) {
    const char* ConsoleAllowedFlags[]={"--xor", "--caesar"};
    const char* allowedFlags[] = {"xor", "caesar"};
    char flag[7];
    char str[80], key[80];
    unsigned int shift;
    if (argc == 4) {
	    if (strcmp(argv[1], ConsoleAllowedFlags[0]) == 0) {
		    mutableDecoderXor(argv[2], argv[3]);
	    }
	    else if (strcmp(argv[1], ConsoleAllowedFlags[1]) == 0) {
		    mutableDecoderCaesar(argv[2], atoi(argv[3]));
	    }
		printf("%s\n", argv[2]);
    }
	else if (argc == 1) {
		printf("Выберите способ шифрования (xor или caesar)\n");
		scanf("%s", flag);
		if (!strcmp(allowedFlags[0], flag)) {
			printf("Шифруемая строка: ");
			scanf(" %99[^\n]", str);
			if (!checkStrtoLetters (str)) {
				return 0;
			}
			mutableStrip(str);
			mutableToLower(str);
			printf("Ключ: ");
			scanf(" %99[^\n]", key);
			mutableDecoderXor(str, key);
		}
		else if (!strcmp(allowedFlags[1], flag)) {
			printf("Шифруемая строка: ");
			scanf(" %99[^\n]", str);
			if (!checkStrtoLetters (str)) {
				return 0;
			}
			mutableStrip(str);
			mutableToLower(str);
			printf("Сдвиг: ");
			scanf("%d", &shift);
			mutableDecoderCaesar(str, shift);
		}
		else {
			printf("Неккоректные данные \n");
			return 1;
		}
		puts(str);
    }
    else{
		printf("Неккоректные данные\n");
    }
    return 0;
}