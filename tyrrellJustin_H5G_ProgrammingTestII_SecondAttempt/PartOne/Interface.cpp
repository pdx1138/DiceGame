#include "Interface.h"

Interface::Interface() {
	this->bg = new Background();
	this->symbol = new Symbol();
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

void Interface::DisplayToScreen() {

}