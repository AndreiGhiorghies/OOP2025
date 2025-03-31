#pragma once
#include "Car.h"

#define MAX_CARS 10

class Circuit {
private:
    double length;
    Weather weather;
    Car* cars[MAX_CARS];
    double times[MAX_CARS];
    bool finished[MAX_CARS];
    int carCount;

public:
    Circuit();
    ~Circuit();
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
