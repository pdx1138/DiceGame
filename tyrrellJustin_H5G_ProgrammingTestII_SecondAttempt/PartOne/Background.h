#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdlib.h>
#include <iostream>
#include "Display.h"

class Background : public Display {
	public:
		Background();
		~Background();

		void SetX(int x);
		void SetY(int y);
		void SetWidth(int w);
		void SetHeight(int h);
		virtual void DisplayToScreen();

	private:
		int* x;
		int* y;
		int* width;
		int* height;
};

#endif // !BACKGROUND_H
