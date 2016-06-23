#pragma once

#ifndef ROLLUP_H
#define ROLLUP_H

#include "Display.h"

enum ROLLUP_TYPES {
	H5G,
	EMPTY
};

class RollUp : public Display{
	public:
		RollUp();
		~RollUp();

		virtual void DisplayToScreen();

	private:
		ROLLUP_TYPES* type;
};

#endif // !ROLLUP_H
