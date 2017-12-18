#pragma once
#include "ObserverDecorator.h"
#include "Observer.h"
#include "ClockTimer.h"
#include <string>
#include <iostream>

class MinutesDecorator : public ObserverDecorator
{
public:
	
	MinutesDecorator(Observer *decoratedClock) : ObserverDecorator(decoratedClock){}
	
	void Update() {
		return ObserverDecorator::Update();
}
	string constructDisplayString() {
		string toMinDisplay;
		toMinDisplay = std::to_string(_subjectMin->getMinute()) + " Minutes ";
		return (toMinDisplay);
	}

private:
	ClockTimer *_subjectMin;
};