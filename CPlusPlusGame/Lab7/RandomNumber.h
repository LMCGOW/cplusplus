#ifndef _RANDOMNUMBER_H
#define _RANDOMNUMBER_H

#include "GameConstants.h"

class RandomNumber{

private:
	static RandomNumber* instance;

public:

	RandomNumber();
	static RandomNumber* GetInstance();

	int seedUnique;
	int seedUnique2;
	int seedUnique3;

	int seedUniqueMultiplier;
	int seedUniqueDivisor;
	int seedUniqueModulus;

	int GenerateRandomNumber(int dampener);

};

#endif