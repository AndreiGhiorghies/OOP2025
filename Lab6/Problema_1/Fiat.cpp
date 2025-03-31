#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 45;
    fuelConsumption = 6;
    avgSpeedRain = 80;
    avgSpeedSunny = 105;
    avgSpeedSnow = 65;
}

void Fiat::SetFuelCapacity(double capacity) { fuelCapacity = capacity; }
void Fiat::SetFuelConsumption(double consumption) { fuelConsumption = consumption; }
void Fiat::SetAverageSpeed(Weather weather, double speed) {
    if (weather == Weather::Rain) avgSpeedRain = speed / 2;
    else if (weather == Weather::Sunny) avgSpeedSunny = speed;
    else avgSpeedSnow = speed / 3;
}
double Fiat::GetFuelCapacity() const { return fuelCapacity; }
double Fiat::GetFuelConsumption() const { return fuelConsumption; }
double Fiat::GetAverageSpeed(Weather weather) const {
    return (weather == Weather::Rain) ? avgSpeedRain : (weather == Weather::Sunny) ? avgSpeedSunny : avgSpeedSnow;
}
const char* Fiat::GetName() const { return "Fiat"; }

