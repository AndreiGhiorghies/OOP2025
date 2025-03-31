#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 50;
    fuelConsumption = 6.5;
    avgSpeedRain = 85;
    avgSpeedSunny = 110;
    avgSpeedSnow = 70;
}

void Seat::SetFuelCapacity(double capacity) { fuelCapacity = capacity; }
void Seat::SetFuelConsumption(double consumption) { fuelConsumption = consumption; }
void Seat::SetAverageSpeed(Weather weather, double speed) {
    if (weather == Weather::Rain) avgSpeedRain = speed / 2;
    else if (weather == Weather::Sunny) avgSpeedSunny = speed;
    else avgSpeedSnow = speed / 3;
}
double Seat::GetFuelCapacity() const { return fuelCapacity; }
double Seat::GetFuelConsumption() const { return fuelConsumption; }
double Seat::GetAverageSpeed(Weather weather) const {
    return (weather == Weather::Rain) ? avgSpeedRain : (weather == Weather::Sunny) ? avgSpeedSunny : avgSpeedSnow;
}
const char* Seat::GetName() const { return "Seat"; }
