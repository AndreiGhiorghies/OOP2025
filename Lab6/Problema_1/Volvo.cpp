#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    avgSpeedRain = 90;
    avgSpeedSunny = 120;
    avgSpeedSnow = 80;
}

void Volvo::SetFuelCapacity(double capacity) { 
    fuelCapacity = capacity; 
}

void Volvo::SetFuelConsumption(double consumption) { 
    fuelConsumption = consumption; 
}

void Volvo::SetAverageSpeed(Weather weather, double speed) {
    if (weather == Weather::Rain) avgSpeedRain = speed / 2;
    else if (weather == Weather::Sunny) avgSpeedSunny = speed;
    else avgSpeedSnow = speed / 3;
}

double Volvo::GetFuelCapacity() const { 
    return fuelCapacity; 

}

double Volvo::GetFuelConsumption() const { 
    return fuelConsumption; 
}

double Volvo::GetAverageSpeed(Weather weather) const {
    return (weather == Weather::Rain) ? avgSpeedRain : (weather == Weather::Sunny) ? avgSpeedSunny : avgSpeedSnow;
}

const char* Volvo::GetName() const { 
    return "Volvo"; 
}

