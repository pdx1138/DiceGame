#pragma once

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Background.h"
#include "Symbol.h"

class Interface {
	public:
		Interface();
		~Interface();

		Background* GetBackground();
		Symbol* GetSymbol();

	private:
		Background* bg;
		Symbol* symbol;
};

#endif // !INTERFACE_H
