#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit() : length(0), weather(Weather::Sunny), carCount(0) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = nullptr;
        times[i] = 0;
        finished[i] = false;
    }
}

Circuit::~Circuit() {
    for (int i = 0; i < carCount; i++) {
        delete cars[i];
    }
}

void Circuit::SetLength(double len) {
    length = len;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    if (carCount < MAX_CARS) {
        cars[carCount] = car;
        carCount++;
    }
    else {
        printf("Circuit is full! Cannot add more cars.\n");
    }
}

void Circuit::Race() {
    for (int i = 0; i < carCount; i++) {
        double speed = cars[i]->GetAverageSpeed(weather);
        double fuelNeeded = (length / 100) * cars[i]->GetFuelConsumption();

        if (fuelNeeded <= cars[i]->GetFuelCapacity()) {
            times[i] = length / speed;
            finished[i] = true;
        }
        else {
            times[i] = -1;
            finished[i] = false;
        }
    }

    for (int i = 0; i < carCount - 1; i++) {
        for (int j = 0; j < carCount - i - 1; j++) {
            if (finished[j] && finished[j + 1] && times[j] > times[j + 1]) {

                double tempTime = times[j];
                times[j] = times[j + 1];
                times[j + 1] = tempTime;

                bool tempFinished = finished[j];
                finished[j] = finished[j + 1];
                finished[j + 1] = tempFinished;

                Car* tempCar = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = tempCar;
            }
        }
    }
}

void Circuit::ShowFinalRanks() {
    printf("Final Rankings:\n");
    for (int i = 0; i < carCount; i++) {
        if (finished[i]) {
            printf("%s finished in %.2f hours.\n", cars[i]->GetName(), times[i]);
        }
    }
}

void Circuit::ShowWhoDidNotFinish() {
    printf("Did not finish:\n");
    for (int i = 0; i < carCount; i++) {
        if (!finished[i]) {
            printf("%s did not have enough fuel.\n", cars[i]->GetName());
        }
    }
}
