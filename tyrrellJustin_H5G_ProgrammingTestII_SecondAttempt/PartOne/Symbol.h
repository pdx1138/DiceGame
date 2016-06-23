#pragma once

#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <iostream>
#include "Display.h"

class Symbol : public Display {
	public:
		Symbol();
		~Symbol();

		void SetWidth(int w);
		void SetHeight(int h);
		virtual void DisplayToScreen();

	private:
		int* width;
		int* height;
};

#endif // !SYMBOL_H
