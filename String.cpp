#include "String.hpp"

namespace prm{
	int strlen(char *s){
		int i = 0;
		while (s[i] != '\0'){
			i++;
		}
		return i;
	}
	int strcmp(char *s1, char *s2){
		int lengthS1, lengthS2;
		lengthS1 = strlen(s1);
		lengthS2 = strlen(s2);
		int minLength = lengthS1 < lengthS2 ? lengthS1 : lengthS2;
		for (int i = 0; i < minLength; i++){
			if (s1[i] < s2[i]){
				return -1;
			}
			else if (s1[i] > s2[i]){
				return 1;
			}
		}
		if (lengthS1 < lengthS2){
			return -1;
		}
		else if (lengthS1 > lengthS2){
			return 1;
		}
		return 0;
	}
	int stricmp(char *s1, char *s2){
		int result;
		char *tempS1, *tempS2;
		tempS1 = strdup(s1);
		tempS2 = strdup(s2);
		strlwr(tempS1);
		strlwr(tempS2);
		result = strcmp(tempS1, tempS2);
		tempS1 = nullptr;
		tempS2 = nullptr;
		delete[] tempS1;
		delete[] tempS2;
		return result;
	}
	int strncmp(char *s1, char *s2, int n){
		int lengthS1, lengthS2;
		lengthS1 = strlen(s1);
		lengthS2 = strlen(s2);
		int minLength = lengthS1 < lengthS2 ? lengthS1 : lengthS2;
		if ((n >= 0) && (n <= minLength)){
			for (int i = 0; i < n; i++){
				if (s1[i] < s2[i]){
					return -1;
				}
				else if (s1[i] > s2[i]){
					return 1;
				}
			}
			if (strlen(s1) < strlen(s2)){
				return -1;
			}
			else if (strlen(s1) > strlen(s2)){
				return 1;
			}
			return 0;
		}
		return strcmp(s1, s2);
	}
	int strnicmp(char *s1, char *s2, int n){
		int result;
		char *tempS1, *tempS2;
		tempS1 = strdup(s1);
		tempS2 = strdup(s2);
		strlwr(tempS1);
		strlwr(tempS2);
		result = strncmp(tempS1, tempS2, n);
		tempS1 = nullptr;
		tempS2 = nullptr;
		delete[] tempS1;
		delete[] tempS2;
		return result;
	}
	char *strcpy(char *s1, char *s2){
		char *result;
		int length = strlen(s2) + 1;
		for (int i = 0; i < (length - 1); i++){
			s1[i] = s2[i];
		}
		s1[(length - 1)] = '\0';
		result = s1;
		return result;
	}
	char *strncpy(char *s1, char *s2, int n){
		char *result;
		if ((n >= 0) && (n <= strlen(s2))){
			int length = n + 1;
			for (int i = 0; i < (length - 1); i++){
				s1[i] = s2[i];
			}
			s1[(length - 1)] = '\0';
		}
		else{
			strcpy(s1, s2);
		}
		result = s1;
		return result;
	}
	char *strdup(char *s){
		int length = strlen(s) + 1;
		char *result = new char[length];
		for (int i = 0; i < (length - 1); i++){
			result[i] = s[i];
		}
		result[(length - 1)] = '\0';
		return result;
	}
	char *strcat(char *s1, char *s2){
		{
			char *result;
			int length = strlen(s1) + strlen(s2) + 1, j = 0;
			for (int i = strlen(s1); i < (length - 1); i++){
				s1[i] = s2[j];
				j++;
			}
			s1[(length - 1)] = '\0';
			result = s1;
			return result;
		}
	}
	char *strncat(char *s1, char *s2, int n){
		char *result;
		if ((n >= 0) && (n <= strlen(s2))){
			int length = strlen(s1) + n + 1, j = 0;
			for (int i = strlen(s1); i < (length - 1); i++){
				s1[i] = s2[j];
				j++;
			}
			s1[(length - 1)] = '\0';
		}
		else{
			strcat(s1, s2);
		}
		result = s1;
		return result;
	}
	char *strstd(char *s){
		char *result;
		int i = 1;
		while (s[0] == ' '){
			strEraseHead(s);
		}
		while (s[(strlen(s) - 1)] == ' '){
			strEraseTail(s);
		}
		if (strlen(s) >= 4){
			while (i != (strlen(s) - 1)){
				if ((s[i] == ' ') && (s[(i + 1)] == ' ')){
					strErase(s, (i + 1));
				}
				else{
					i++;
				}
			}
		}
		result = s;
		return result;
	}
	char *strnstd(char *s){
		char *result;
		int i = 2;
		strlwr(s);
		strstd(s);
		if ((s[0] >= 'a') && (s[0] <= 'z')){
			s[0] -= 32;
		}
		while (i <= (strlen(s) - 1)){
			if ((s[(i - 1)] == ' ') && ((s[i] >= 'a') && (s[i] <= 'z'))){
				s[i] -= 32;
			}
			i++;
		}
		result = s;
		return result;
	}
	char *strlwr(char *s){
		char *result;
		for (int i = 0; i < strlen(s); i++){
			if ((s[i] >= 'A') && (s[i] <= 'Z')){
				s[i] += 32;
			}
		}
		result = s;
		return result;
	}
	char *strupr(char *s){
		char *result;
		for (int i = 0; i < strlen(s); i++){
			if ((s[i] >= 'a') && (s[i] <= 'z'))			{
				s[i] -= 32;
			}
		}
		result = s;
		return result;
	}
	char *strchr(char *s, int ch){
		char *result = nullptr;
		for (int i = 0; i < strlen(s); i++){
			if (s[i] == ch){
				result = &s[i];
				break;
			}
		}
		return result;
	}
	char *strrchr(char *s, int ch){
		char *result = nullptr;
		for (int i = strlen(s); i >= 0; i--){
			if (s[i] == ch)
			{
				result = &s[i];
				break;
			}
		}
		return result;
	}
	char *strstr(char *s1, char *s2){
		char* result = nullptr;
		bool flag;
		int k;
		for (int i = 0; i < strlen(s1); i++){
			flag = true;
			k = i;
			for (int j = 0; j < strlen(s2); j++){
				if (s1[k] != s2[j]){
					flag = false;
					break;
				}
				k++;
			}
			if (flag){
				result = &s1[i];
			}
		}
		return result;
	}
	char *strrev(char *s){
		char *result;
		int length = strlen(s);
		for (int i = 0; i < (length / 2); i++){
			strSwap(s[i], s[(length - 1 - i)]);
		}
		result = s;
		return result;
	}
	//
	char *strInsert(char *s, int index, char ch){
		char *result;
		int length = strlen(s) + 1 + 1;
		for (int i = (length - 1 - 1); i > index; i--){
			s[i] = s[(i - 1)];
		}
		s[index] = ch;
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strInsertHead(char *s, char ch){
		char *result;
		int length = strlen(s) + 1 + 1;
		for (int i = (length - 1 - 1); i > 0; i--){
			s[i] = s[(i - 1)];
		}
		s[0] = ch;
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strInsertTail(char *s, char ch){
		char *result;
		int length = strlen(s) + 1 + 1;
		s[(length - 1 - 1)] = ch;
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strErase(char *s, int index){
		char *result;
		int length = strlen(s) + 1 - 1;
		for (int i = index; i < (length - 1); i++){
			s[i] = s[i + 1];
		}
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strEraseHead(char *s){
		char *result;
		int length = strlen(s) + 1 - 1;
		for (int i = 0; i < (length - 1); i++){
			s[i] = s[i + 1];
		}
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strEraseTail(char *s){
		char *result;
		int length = strlen(s) + 1 - 1;
		s[(length - 1)] = '\0';
		result = s;
		return result;
	}
	char *strUpdate(char *s, int index, char ch){
		char *result;
		s[index] = ch;
		result = s;
		return result;
	}
	char *strUpdateHead(char *s, char ch){
		char *result;
		s[0] = ch;
		result = s;
		return result;
	}
	char *strUpdateTail(char *s, char ch){
		char *result;
		s[(strlen(s) + 1 - 1 - 1)] = ch;
		result = s;
		return result;
	}
	void strSwap(char &ch1, char &ch2){
		char temp = ch1;
		ch1 = ch2;
		ch2 = temp;
	}
	//
	char *itos(int i){
		char *result;
		int count = 0, temp = i, length;
		while (temp != 0){
			temp /= 10;
			count++;
		}
		length = count + 1;
		result = new char[length];
		temp = i;
		for (int i = (length - 1 - 1); i >= 0; i--){
			result[i] = (temp % 10) + 48;
			temp /= 10;
		}
		result[(length - 1)] = '\0';
		return result;
	}
	int stoi(char *s){
		int result = 0, j = 0;
		for (int i = (strlen(s) - 1); i >= 0; i--){
			result += (s[i] - 48) * pow(10, j);
			j++;
		}
		return result;
	}
}