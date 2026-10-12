#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController();

    void init();
    void setFrequency(float temperatureC);
    void update();

private:
    bool ledOn = false;
    unsigned long togglePeriod = 100;
    unsigned long lastToggle = 0;
};
using LEDControllerInstance = etl::singleton<LEDController>;
