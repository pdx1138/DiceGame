#include "Background.h"

Background::Background() {
	this->x = (int*)malloc(sizeof(int));
	this->y = (int*)malloc(sizeof(int));
	this->width = (int*)malloc(sizeof(int));
	this->height = (int*)malloc(sizeof(int));

	*this->x = 0;
	*this->y = 0;
	*this->width = 0;
	*this->height = 0;
}

Background::~Background() {
	free(this->x);
	free(this->y);
	free(this->width);
	free(this->height);
}

void Background::SetX(int x) {
	*this->x = x;
}

void Background::SetY(int y) {
	*this->y = y;
}

void Background::SetWidth(int w) {
	*this->width = w;
}

void Background::SetHeight(int h) {
	*this->height = h;
}

void Background::DisplayToScreen() {

}