#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

void mutableToUpper(char* str) {
	unsigned int i;
	const char LittleBigDiference = 'A' - 'a', LittleA = 'a';
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if (str[i] >= LittleA) {
			str[i] = str[i] + LittleBigDiference;
		}
	}
}

char* immutableToUpper (const char* str) { 
	char* Upstr = (char*)malloc(strlen(str) * sizeof(char));
	const char LittleBigDiference = 'A'-'a', LittleA = 'a';
	const unsigned int length = strlen(str);
	unsigned int i;
	for (i = 0; i < length; i++) {
		if (str[i] >= LittleA) {
			Upstr[i] = str[i] + LittleBigDiference;
		}
	}
	return Upstr;
}

void mutableToLower(char* str) {
	unsigned int i;
	const char BigLittleDiference = 'a' - 'A', BigA = 'A', BigZ = 'Z';
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if ((str[i] >= BigA) && (str[i] <= BigZ)) {
			str[i] = str[i] + BigLittleDiference;
		}
	}
}

char* immutableToLower(const char* str) {
	char* Lowstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i;
	const unsigned int length = strlen(str);
	const char BigLittleDiference = 'a' - 'A', BigA = 'A', BigZ = 'Z';
	for (i = 0; i < length; i++) {
		if ((str[i] >= BigA) && (str[i] <= BigZ)) {
			Lowstr[i] = str[i] + BigLittleDiference;
		}
	}
	return Lowstr;
}

void mutableDeleteSpaces(char* str) {
	unsigned int i, j;
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
	for (i = j = 0; i < length; i++) { 
		if (str[i] != Space) {
			str[j++] = str[i];
		}
	}
	str[j] = Endstr;
}

char* immutableDeleteSpaces(const char* str) {
	char* SpacelessStr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i, j;
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
	for (i = j = 0; i < length; i++) {
		if (str[i] != Space) {
			SpacelessStr[j++] = str[i];
		}
	}
	SpacelessStr[j] = Endstr;
	return SpacelessStr;
}

void mutableStrip(char* str) {
	unsigned int i, j, rightborder = strlen(str);
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
    i = length - 1;
	while (str[i] == ' ') {
		rightborder = i;	
		i = i - 1;
	}
	char firstspace = 0;
	for (i = j = 0; i < rightborder; i++) {
		if ((str[i] == Space) && (firstspace == 0)) {
			++firstspace;
		}
		else {
			str[j++] = str[i];
		}
	}
	str[j] = Endstr;
}

char* immutableStrip(const char* str) {
	char* stripstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i, j, rightborder = strlen(str);
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
    i = length - 1;
	while (str[i] == ' ') {
		rightborder = i;	
		i = i - 1;
	}
	char firstspace = 0;
	for (i = j = 0; i < rightborder; i++) {
		if ((str[i] == Space) && (firstspace == 0)) {
		++firstspace;
		}
		else {
			stripstr[j++] = str[i];
		}
	}
	stripstr[j] = Endstr;
	return stripstr;
}

void mutableGetFilterStr (char* str) {
	unsigned int j, i;
	const unsigned int length = strlen(str);
	for (i = j = 0; i < length; i++) {
		if (((str[i] >= 'a') && (str[i] <= 'z')) 
			|| ((str[i] >= '0') && (str[i] <= '9')) 
			|| (str[i] == ' ') || ((str[i] >= 'A') && (str[i] <= 'Z'))) {
			str[j++] = str[i];
		}
	}
}

char* immutableGetFilterStr (const char* str) {
	char* filterstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int j, i;
	const unsigned int length = strlen(str);
	for (i = j = 0; i < length; i++) {
		if (((str[i] >= 'a') && (str[i] <= 'z')) 
			|| ((str[i] >= '0') && (str[i] <= '9')) 
			|| (str[i] == ' ') || ((str[i] >= 'A') && (str[i] <= 'Z'))) {
			filterstr[j++] = str[i];
		}
	}
	filterstr[j] = '\0';
	return filterstr;
}

unsigned int checkStrtoNumber (char* str) {
	unsigned int i;
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if ((str[i] < '1') || (str[i] > '9')) {
			printf("Not a number\n");
			return 0;
		}
	}
	printf("Number\n");
	return 1;
}

unsigned int checkStrtoLetters (char* str) {
	unsigned int i;
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if ((str[i] < 'A') 
			|| ((str[i] > 'Z') && (str[i] < 'a')) 
			|| (str[i] > 'z')) {
			printf("Not only letters\n");
			return 0;
		}
	}
	printf("Only letters\n");
	return 1;
}