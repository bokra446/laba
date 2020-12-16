#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mutableToUpper(char* str) {
	unsigned int i;
	const char LittleBigDif = 'A' - 'a', LittleA = 'a';
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if (str[i] >= LittleA) {
			str[i] = str[i] + LittleBigDif;
		}
	}
}

char* immutableToUpper (const char* str) { 
	char* Upstr = (char*)malloc(strlen(str) * sizeof(char));
	const char LittleBigDif = 'A'-'a', LittleA = 'a';
	const unsigned int length = strlen(str);
	unsigned int i;
	for (i = 0; i < length; i++) {
		if (str[i] >= LittleA) {
			Upstr[i] = str[i] + LittleBigDif;
		}
	}
	return Upstr;
}

void mutableToLower(char* str) {
	unsigned int i;
	const char BigLittleDif = 'a' - 'A', BigA = 'A', BigZ = 'Z';
	const unsigned int length = strlen(str);
	for (i = 0; i < length; i++) {
		if ((str[i] >= BigA) && (str[i] <= BigZ)) {
			str[i] = str[i] + BigLittleDif;
		}
	}
}

char* immutableToLower(const char* str) {
	char* Lowstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i;
	const unsigned int length = strlen(str);
	const char BigLittleDif = 'a' - 'A', BigA = 'A', BigZ = 'Z';
	for (i = 0; i < length; i++) {
		if ((str[i] >= BigA) && (str[i] <= BigZ)) {
			Lowstr[i] = str[i] + BigLittleDif;
		}
	}
	return q;
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

char* imutableDeleteSpaces(const char* str) {
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

void mutablestrip(char* str) {
	unsigned int i, j, rightborder;
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
    i = length - 1;
	while (str[i] == ' ') {
		rightborder = i;	
		i = i - 1;
	}
	for (i = j = 0; i < rightborder; i++) {
		if ((str[i] == Space) && (j == 0)) {
			continue;
		}
		else {
			str[j++] = str[i];
		}
	}
	str[j] = Endstr;
}

char* imutablestrip(const char* str) {
	char* stripstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int i, j, rightborder;
	const char Space = ' ', Endstr = '\0';
	const unsigned int length = strlen(str);
    i = length - 1;
	while (str[i] == ' ') {
		rightborder = i;	
		i = i - 1;
	}
	for (i = j = 0; i < rightborder; i++) {
		if ((str[i] == Space) && (j == 0)) {
			continue;
		}
		else {
			stripstr[j++] = str[i];
		}
	}
	stripstr[j] = Endstr;
	return stripstr;
}



void mutablegetfilterStr (char* str) {
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

char* imutablegetfilterStr (const char* str) {
	char* filterstr = (char*)malloc(strlen(str) * sizeof(char));
	unsigned int j, i;
	const unsigned int length = strlen(str);
	for (i = j = 0; i < length; i++) {
		if (((str[i]> = 'a') && (str[i] <= 'z')) 
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