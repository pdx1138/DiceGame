#include "Symbol.h"

Symbol::Symbol() {
	this->width = (int*)malloc(sizeof(int));
	this->height = (int*)malloc(sizeof(int));

	*this->width = 0;
	*this->height = 0;
}

Symbol::~Symbol() {
	free(this->width);
	free(this->height);
}

void Symbol::SetWidth(int w) {
	*this->width = w;
}

void Symbol::SetHeight(int h) {
	*this->height = h;
}