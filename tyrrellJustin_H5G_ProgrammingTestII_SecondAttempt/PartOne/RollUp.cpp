#include "RollUp.h"

RollUp::RollUp() {
	this->type = (ROLLUP_TYPES*)malloc(sizeof(ROLLUP_TYPES));

	*this->type = ROLLUP_TYPES::EMPTY;
}

RollUp::~RollUp() {
	free(this->type);
}

void RollUp::DisplayToScreen() {

}