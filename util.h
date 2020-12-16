#ifndef UTIL_H
#define UTIL_H

void mutableToUpper(char* str);

void mutableToLower(char* str);

char* immutableToUpper (const char* str);

char* immutableToLower(const char* str);

void mutableDeleteSpaces(char* str);

char* imutableDeleteSpaces(const char* str);

void mutablestrip(char* str);

char* imutablestrip(const char* str);

void mutablegetfilterStr (char* str);

char* imutablegetfilterStr (const char* str);

unsigned int checkStrtoNumber (char* str);

unsigned int checkStrtoLetters (char* str);

#endif