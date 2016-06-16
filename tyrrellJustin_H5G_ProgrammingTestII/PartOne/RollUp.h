#pragma once

#ifndef ROLLUP_H
#define ROLLUP_H

enum ROLLUP_TYPES {
	H5G
};

class RollUp {
	public:
		RollUp();
		~RollUp();

	private:
		ROLLUP_TYPES* type;
};

#endif // !ROLLUP_H
