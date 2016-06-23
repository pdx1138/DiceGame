// Display.h
//
// Base Virtual Class Definition for a Disaplayable Object
////////////////////////////////////////////////////////////////////

#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>
#include <iostream>

using namespace std;

class Display {
	public:
		Display() {
			// No Op
		}

		~Display() {
			// No Op
		}

		virtual void DisplayToScreen() = 0;
};

#endif // !DISPLAY_H
