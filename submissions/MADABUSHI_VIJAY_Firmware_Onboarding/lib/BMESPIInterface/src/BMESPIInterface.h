#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:
    BMESPIInterface();

    bool init();

    void update();

    float getTemperature();
private:

   Adafruit_BME280 bme;
   float temperatureC = 0.0f;

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;