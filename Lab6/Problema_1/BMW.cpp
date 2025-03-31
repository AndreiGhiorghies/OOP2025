#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 10;
    fuelConsumption = 100;
    avgSpeedRain = 100;
    avgSpeedSunny = 140;
    avgSpeedSnow = 85;
}

void BMW::SetFuelCapacity(double capacity) { fuelCapacity = capacity; }
void BMW::SetFuelConsumption(double consumption) { fuelConsumption = consumption; }
void BMW::SetAverageSpeed(Weather weather, double speed) {
    if (weather == Weather::Rain) avgSpeedRain = speed / 2;
    else if (weather == Weather::Sunny) avgSpeedSunny = speed;
    else avgSpeedSnow = speed / 3;
}
double BMW::GetFuelCapacity() const { return fuelCapacity; }
double BMW::GetFuelConsumption() const { return fuelConsumption; }
double BMW::GetAverageSpeed(Weather weather) const {
    return (weather == Weather::Rain) ? avgSpeedRain : (weather == Weather::Sunny) ? avgSpeedSunny : avgSpeedSnow;
}
const char* BMW::GetName() const { return "BMW"; }
