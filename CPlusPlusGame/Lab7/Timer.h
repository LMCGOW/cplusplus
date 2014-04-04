#ifndef _TIMER_H
#define _TIMER_H

#include "GameConstants.h"

class Timer{

private:

	__int64 frequency;
	float seconds;

	__int64 currentTime;
	__int64 previousTime;


public:

	Timer();
	~Timer();

	bool TimePassed(float time);

};

#endif