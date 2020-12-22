#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EncryptFunction.h"
void mutableDecoderCaesar(char* str, int shift) {
	unsigned int i;
	const unsigned int length = strlen(str);
	const char difference = 'z' - 'a' + 1;
	if (shift) {
		shift = shift + difference * (abs((shift / difference)) + 1);
	}
	const int ShiftModDif = shift % difference;
	for (i = 0; i < length; i++) {
		if ((str[i] <= 'z') && (str[i] >= 'a')) {
			if ((ShiftModDif > 'z' - str[i])) {
				str[i] = str[i] + (ShiftModDif) - difference;
			}
			else {
				str[i] = str[i] + (ShiftModDif);
			}
		}
	}
}

char* immutableDecoderCaesar(const char* str, int shift) {
	char* decstr = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(decstr, str);
	mutableDecoderCaesar(decstr, shift);
	return decstr;
}

void mutableDecoderXor(char* str, const char* password) {
	unsigned int i, j = 0;
	const unsigned int lengthstr = strlen(str), lengthpass = strlen(password);
	for (i = 0; i < lengthstr; i++) {
		str[i] = str[i] ^ password[j];
		++j;
		if (j > lengthpass - 1) {
			j = 0;
		}
	}
}

char* immutableDecoderXor(const char* str, const char* password) {
	char* xorstr = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(xorstr, str);
	mutableDecoderXor(xorstr, password);
	return xorstr;
}