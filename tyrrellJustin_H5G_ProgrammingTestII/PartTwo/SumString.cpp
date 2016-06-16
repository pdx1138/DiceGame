#include "SumString.h"

void sum_str(char* a, char const* b, char const* c) {
	unsigned int bNum = atoi(b);
	unsigned int cNum = atoi(c);

	unsigned int aNum = bNum + cNum;

	//char* buff = (char*)malloc(sizeof(char) * STRING_SIZE);

	itoa(aNum, a, 10);

	//free(buff);
}