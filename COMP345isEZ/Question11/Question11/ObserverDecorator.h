#pragma once
#include "DigitalClockObserver.h"
#include "Observer.h"
#include <iostream>
#include <string>
class ObserverDecorator : public Observer

{
protected:
	Observer *decoratedClock;

public:
	ObserverDecorator(Observer *decoratedClock) {
		this->decoratedClock = decoratedClock;
	}
	
	void Update() {
		cout << "Louis us fuck as fuck" << endl;
		return decoratedClock->Update();
	}

};

