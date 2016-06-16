#include "Interface.h"

Interface::Interface() {
	this->bg = new Background();
	this->symbol = new Symbol();

	/*memset(this->bg, 0, sizeof(Background));
	memset(this->symbol, 0, sizeof(Symbol));*/
}

Interface::~Interface() {
	delete this->bg;
	delete this->symbol;
}

Background* Interface::GetBackground() {
	return this->bg;
}

Symbol* Interface::GetSymbol() {
	return this->symbol;
}