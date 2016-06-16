#include "StringRotate.h"
//#include <string.h>

void rotate(char* s, int n) {
	/*unsigned int size = sizeof(s) + 1;
	if (n > size)return;*/

	/*char* newstring = new char(sizeof(char) * n);

	for (int i = 0; i < n; ++i) {
		newstring[i] = s[i];
	}*/
	int progress = 0;
	while(progress < n) {
		for (int i = 1; s[i] != NULL; ++i) {
			char temp = s[i - 1];
			char temptwo = s[i];
			*(s + (i - 1)) = temptwo;
			*(s + i) = temp;
			/*swap(s[i - 1], s[i]);*/
		}
		++progress;
	}
}