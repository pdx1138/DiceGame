#include "Spinner.h"

Spinner::Spinner() {
	this->speed = (int*)malloc(sizeof(int));
	this->startBounce = (bool*)malloc(sizeof(bool));
	this->duration = (float*)malloc(sizeof(float));
	//this->direction = (Direction*)malloc(sizeof(Direction));

	*this->speed = 0;
	*this->startBounce = false;
	*this->duration = 0.0f;
	//*this->direction = Direction::NONE;

	this->direction = new Direction();
}

Spinner::~Spinner() {
	free(this->speed);
	free(this->startBounce);
	free(this->duration);
	//free(this->direction);

	delete this->direction;
}

void Spinner::DisplayToScreen() {
	
}

Direction::Direction() {
	this->reel1 = (REEL_DIRECTION*)malloc(sizeof(REEL_DIRECTION));
	this->reel2 = (REEL_DIRECTION*)malloc(sizeof(REEL_DIRECTION));
	this->reel3 = (REEL_DIRECTION*)malloc(sizeof(REEL_DIRECTION));
	this->reel4 = (REEL_DIRECTION*)malloc(sizeof(REEL_DIRECTION));
	this->reel5 = (REEL_DIRECTION*)malloc(sizeof(REEL_DIRECTION));

	*this->reel1 = REEL_DIRECTION::NONE;
	*this->reel2 = REEL_DIRECTION::NONE;
	*this->reel3 = REEL_DIRECTION::NONE;
	*this->reel4 = REEL_DIRECTION::NONE;
	*this->reel5 = REEL_DIRECTION::NONE;
}

Direction::~Direction() {
	free(this->reel1);
	free(this->reel2);
	free(this->reel3);
	free(this->reel4);
	free(this->reel5);
}

void Direction::DisplayToScreen() {
	cout << "stuff";
}