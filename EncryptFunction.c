#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EncryptFunction.h"
void mutableDecoderCaesar(char* str, int shift) {
	unsigned int i;
	const unsigned int length = strlen(str);
	const char difference = 'z' - 'a' + 1;
	const int ShifModDif = shift % difference;
	if (shift) {
		shift = shift + difference * ((shift / difference) + 1);
	}
	for (i = 0; i < length; i++) {
		if ((ShifModDif > 'z' - str[i])) {
            str[i] = str[i] + (ShifModDif) - difference;
		}
		else {
            str[i] = str[i] + (ShifModDif);
		}
	}
}

char* immutableDecoderCaesar(const char* str, int shift) {
	char* decstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i;
	const unsigned int length = strlen(str);
	const char difference = 'z' - 'a' + 1;
	const int ShifModDif = shift % difference;
	if (shift) {
		shift = shift + difference * ((shift / difference) + 1);
	}
	for (i = 0; i < length; i++) {
		if ((ShifModDif > 'z' - str[i])) {
            decstr[i] = str[i] + (ShifModDif) - difference;
		}
		else {
            decstr[i] = str[i] + (ShifModDif);
		}
	}
	decstr[i] = '\0';
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
	unsigned int i, j = 0;
  	const unsigned int lengthstr = strlen(str), lengthpass = strlen(password);
	for (i = 0; i < lengthstr; i++) {
		xorstr[i] = str[i] ^ password[j];
		++j;
		if (j > lengthpass - 1) {
			j = 0;
		}
	}
	xorstr[i] = '\0';
	return xorstr;
}