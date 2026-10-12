#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:
    BMEI2CInterface();

    bool init();

    void update();

    float getTemperature();
private:

   Adafruit_BME280 bme;
   float temperatureC = 0.0f;

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;