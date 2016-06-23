#pragma once

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Background.h"
#include "Symbol.h"
#include "Display.h"

class Interface : public Display {
	public:
		Interface();
		~Interface();

		Background* GetBackground();
		Symbol* GetSymbol();
		virtual void DisplayToScreen();

	private:
		Background* bg;
		Symbol* symbol;
};

#endif // !INTERFACE_H
