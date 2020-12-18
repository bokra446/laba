#ifndef ENCRYPTFUNCTION_H
#define ENCRYPTFUNCTION_H

void mutableDecoderCaesar(char* str, int shift);

char* immutableDecoderCaesar(const char* str, int shift);

void mutableDecoderXor(char* str, const char* password);

char* immutableDecoderXor(const char* str, const char* password);
#endif