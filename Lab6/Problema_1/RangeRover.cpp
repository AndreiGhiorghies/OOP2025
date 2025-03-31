#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 70;
    fuelConsumption = 12;
    avgSpeedRain = 80;
    avgSpeedSunny = 130;
    avgSpeedSnow = 75;
}

void RangeRover::SetFuelCapacity(double capacity) { fuelCapacity = capacity; }
void RangeRover::SetFuelConsumption(double consumption) { fuelConsumption = consumption; }
void RangeRover::SetAverageSpeed(Weather weather, double speed) {
    if (weather == Weather::Rain) avgSpeedRain = speed / 2;
    else if (weather == Weather::Sunny) avgSpeedSunny = speed;
    else avgSpeedSnow = speed / 3;
}
double RangeRover::GetFuelCapacity() const { return fuelCapacity; }
double RangeRover::GetFuelConsumption() const { return fuelConsumption; }
double RangeRover::GetAverageSpeed(Weather weather) const {
    return (weather == Weather::Rain) ? avgSpeedRain : (weather == Weather::Sunny) ? avgSpeedSunny : avgSpeedSnow;
}
const char* RangeRover::GetName() const { return "Range Rover"; }
