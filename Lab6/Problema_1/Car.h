#pragma once
#include "Weather.h"

class Car {
public:
    virtual void SetFuelCapacity(double capacity) = 0;
    virtual void SetFuelConsumption(double consumption) = 0;
    virtual void SetAverageSpeed(Weather weather, double speed) = 0;
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather weather) const = 0;
    virtual const char* GetName() const = 0;
};