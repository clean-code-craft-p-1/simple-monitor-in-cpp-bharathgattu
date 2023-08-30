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
    if (temperature > 102 || temperature < 95) {
        return true;
    }
    return false;
}

bool isPulseRateWithinRange(float pulseRate) {
    if (pulseRate < 60 || pulseRate > 100) {
        return true;
    }
    return false;
}

bool isSpo2LevelOK(float spo2) {
    if (spo2 < 90) {
        return true;
    }
    return false;
}
int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool result = true;
    if (isTemperatureCritical(temperature) == true) {
        cout << "Temperature critical!\n";
        result = false;
    }
    else if (isPulseRateWithinRange(pulseRate)) {
        cout << "Pulse Rate is out of range!\n";
        result = false;
    }
    else if (isSpo2LevelOK(spo2)) {
        cout << "Oxygen Saturation out of range!\n";
        result = false;
    }
    printPattern();
    return result;
}

int main() {
    assert(!vitalsOk(99, 102, 70));
    assert(vitalsOk(98.1, 70, 98));
    cout << "Done\n";
}
