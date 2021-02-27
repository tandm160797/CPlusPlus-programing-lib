#ifndef String_hpp
#define String_hpp

#include <cmath>
#include <iostream>
using namespace std;

namespace prm{
	int strlen(char *s);
	int strcmp(char *s1, char *s2);
	int stricmp(char *s1, char *s2);
	int strncmp(char *s1, char *s2, int n);
	int strnicmp(char *s1, char *s2, int n);
	char *strcpy(char *s1, char *s2);
	char *strncpy(char *s1, char *s2, int n);
	char *strdup(char *s);
	char *strcat(char *s1, char *s2);
	char *strncat(char *s1, char *s2, int n);
	char *strstd(char *s);
	char *strnstd(char *s);
	char *strlwr(char *s);
	char *strupr(char *s);
	char *strchr(char *s, int ch);
	char *strrchr(char *s, int ch);
	char *strstr(char *s1, char *s2);
	char *strrev(char *s);
	//
	char *strInsert(char *s, int index, char ch);
	char *strInsertHead(char *s, char ch);
	char *strInsertTail(char *s, char ch);
	char *strErase(char *s, int index);
	char *strEraseHead(char *s);
	char *strEraseTail(char *s);
	char *strUpdate(char *s, int index, char ch);
	char *strUpdateHead(char *s, char ch);
	char *strUpdateTail(char *s, char ch);
	void strSwap(char &ch1, char &ch2);
	//
	char *itos(int i);
	int stoi(char *s);
}

#endif //String.hpp