#include "BMESPIInterface.h"
#include <SPI.h>

BMESPIInterface::BMESPIInterface()
    : sensor_(BMEConstants::SPI_CHIP_SELECT_PIN, &SPI)
{
}

bool BMESPIInterface::begin()
{
    pinMode(BMEConstants::SPI_CHIP_SELECT_PIN, OUTPUT);
    digitalWrite(BMEConstants::SPI_CHIP_SELECT_PIN, HIGH);
    SPI.begin();
    ready_ = sensor_.begin();
    return ready_;
}

bool BMESPIInterface::readTemperature(float &temperatureC)
{
    if (!ready_)
    {
        return false;
    }

    temperatureC = sensor_.readTemperature();
    return !isnan(temperatureC);
}
