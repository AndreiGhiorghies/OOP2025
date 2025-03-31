#pragma once
#include "Car.h"

class Volvo : public Car {
private:
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;

public:
    Volvo();
    void SetFuelCapacity(double capacity) override;
    void SetFuelConsumption(double consumption) override;
    void SetAverageSpeed(Weather weather, double speed) override;
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather weather) const override;
    const char* GetName() const override;
};
