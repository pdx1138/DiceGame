#pragma once

#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <iostream>

class Symbol {
	public:
		Symbol();
		~Symbol();

		void SetWidth(int w);
		void SetHeight(int h);

	private:
		int* width;
		int* height;
};

#endif // !SYMBOL_H
