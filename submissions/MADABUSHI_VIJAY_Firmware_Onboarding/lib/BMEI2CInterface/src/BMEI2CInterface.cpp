#include "BMEI2CInterface.h"

BMEI2CInterface::BMEI2CInterface() : bme()
{
}

bool BMEI2CInterface::init()
{
    return bme.begin(BMEConstants::I2C_ADDRESS) ||
           bme.begin(BMEConstants::I2C_ALTERNATE_ADDRESS);
}

void BMEI2CInterface::update()
{
    temperatureC = bme.readTemperature();
}

float BMEI2CInterface::getTemperature()
{
    return temperatureC;
}
