#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdlib.h>
#include <iostream>

class Background {
public:
	Background();
	~Background();

	void SetX(int x);
	void SetY(int y);
	void SetWidth(int w);
	void SetHeight(int h);

private:
	int* x;
	int* y;
	int* width;
	int* height;
};

#endif // !BACKGROUND_H
