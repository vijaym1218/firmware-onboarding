#pragma once

#include <Arduino.h>
#include "BMEConstants.h"

class LEDController
{
public:
    void begin();
    void setTemperature(float temperatureC);
    void update(unsigned long now);
    unsigned long blinkIntervalMs() const { return blinkIntervalMs_; }

private:
    unsigned long blinkIntervalMs_ = BMEConstants::MAX_BLINK_INTERVAL_MS;
    unsigned long lastToggleMs_ = 0;
    bool ledOn_ = false;
};
