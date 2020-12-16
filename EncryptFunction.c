#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mutabledecoderCaesar(char* str, unsigned int shift) {
	unsigned int i;
	const unsigned int length = strlen(str);
	const char difference = 'z' - 'a' + 1;
	for (i = 0; i < length; i++) {
		if ((shift % difference > 'z' - str[i])) {
            str[i] = str[i] + (shift % difference) - difference;
		}
		else {
            str[i] = str[i] + (shift % difference);
		}
	}
}

char* immutabledecoderCaesar(const char* str, unsigned int shift) {
	char* decstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i;
	const unsigned int length = strlen(str);
	const char difference = 'z' - 'a' + 1;
	for (i = 0; i < length; i++) {
		if ((shift % difference > 'z' - str[i])) {
            decstr[i] = str[i] + (shift % difference) - difference;
		}
		else {
            decstr[i] = str[i] + (shift % difference);
		}
	}
	decstr[i] = '\0';
	return decstr;
}

void mutabledecoderXor(char* str, const char* password) {
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

char* immutabledecoderXor(const char* str, const char* password) {
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