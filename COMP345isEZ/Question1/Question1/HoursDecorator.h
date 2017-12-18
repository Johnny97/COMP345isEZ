#pragma once
#include "ObserverDecorator.h"
#include "Observer.h"
#include "ClockTimer.h"
class HoursDecorator :  public ObserverDecorator
{
public:
	HoursDecorator(Observer *decoratedClock) : ObserverDecorator(decoratedClock){}
	void Update();
	void display();
	string constructDisplayString();

private:
	ClockTimer *_subject;
};

