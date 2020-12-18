#ifndef UTIL_H
#define UTIL_H

void mutableToUpper(char* str);

void mutableToLower(char* str);

char* immutableToUpper (const char* str);

char* immutableToLower(const char* str);

void mutableDeleteSpaces(char* str);

char* immutableDeleteSpaces(const char* str);

void mutableStrip(char* str);

char* immutableStrip(const char* str);

void mutablegetfilterStr (char* str);

char* immutablegetfilterStr (const char* str);

unsigned int checkStrtoNumber (char* str);

unsigned int checkStrtoLetters (char* str);

#endif