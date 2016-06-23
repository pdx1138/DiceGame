#pragma once

#ifndef SPINNER_H
#define SPINNER_H

#include <stdlib.h>
#include "Display.h"

enum REEL_DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};

class Direction : public Display {
	public:
		Direction();
		~Direction();

		virtual void DisplayToScreen();

	private:
		REEL_DIRECTION* reel1;
		REEL_DIRECTION* reel2;
		REEL_DIRECTION* reel3;
		REEL_DIRECTION* reel4;
		REEL_DIRECTION* reel5;
};

class Spinner : public Display {
	public:
		Spinner();
		~Spinner();

		virtual void DisplayToScreen();

	private:
		int* speed;
		bool* startBounce;
		float* duration;
		Direction* direction;
};

#endif // !SPINNER_H
