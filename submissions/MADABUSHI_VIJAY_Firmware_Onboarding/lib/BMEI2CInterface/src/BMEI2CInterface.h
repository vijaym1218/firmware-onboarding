#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    bool readTemperature(float &temperatureC);
    bool isReady() const { return ready_; }

private:
    Adafruit_BME280 sensor_;
    bool ready_ = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
