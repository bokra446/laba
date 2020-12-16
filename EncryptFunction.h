#ifndef ENCRYPTFUNCTION_H
#define ENCRYPTFUNCTION_H

void mutabledecoderCaesar(char* str, unsigned int shift);

char* immutabledecoderCaesar(const char* str, unsigned int shift);

void mutabledecoderXor(char* str, const char* password);

char* immutabledecoderXor(const char* str, const char* password);
#endif