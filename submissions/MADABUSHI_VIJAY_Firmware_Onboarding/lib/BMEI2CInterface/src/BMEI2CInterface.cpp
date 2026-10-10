#include "BMEI2CInterface.h"
#include <Wire.h>

bool BMEI2CInterface::begin()
{
    Wire.begin();
    ready_ = sensor_.begin(BMEConstants::I2C_ADDRESS, &Wire);
    return ready_;
}

bool BMEI2CInterface::readTemperature(float &temperatureC)
{
    if (!ready_)
    {
        return false;
    }

    temperatureC = sensor_.readTemperature();
    return !isnan(temperatureC);
}
