#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;

void printPattern() {
    for (int i = 0; i < 6; i++)
    {
        cout << "\r* " << flush;
         sleep(1);
         cout << "\r *" << flush;
         sleep(1);
    }
}

bool isTemperatureCritical(float temperature) {
    bool result = false;
    result = temperature > 102 || temperature < 95;
    if (result == true) {
        cout << "Temperature critical!\n";
        printPattern();
    }

    return result;
}

bool isPulseRateWithinRange(float pulseRate) {
    bool result = false;
    result = pulseRate < 60 || pulseRate > 100;

    if (result == true) {
        cout << "Pulse Rate is out of range!\n";
        printPattern();
    }

    return result;
}

bool isSpo2LevelOK(float spo2) {
    bool result = false;
    result = spo2 < 90;
    if (result == true) {
        cout << "Oxygen Saturation out of range!\n";
        printPattern();
    }

    return result;
}
bool vitalsOk(float temperature, float pulseRate, float spo2) {
    return  !(isTemperatureCritical(temperature) || isPulseRateWithinRange(pulseRate) || isSpo2LevelOK(spo2));
}

int main() {
    assert(!vitalsOk(99, 102, 70));
    assert(vitalsOk(98.1, 70, 98));
    cout << "Done\n";
}
