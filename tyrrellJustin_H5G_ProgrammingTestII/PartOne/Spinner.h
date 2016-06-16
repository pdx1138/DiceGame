#pragma once

#ifndef SPINNER_H
#define SPINNER_H

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Spinner {
	public:
		Spinner();
		~Spinner();

	private:
		int* speed;
		bool* startBounce;
		float* duration;
		DIRECTION* direction;
};

#endif // !SPINNER_H
