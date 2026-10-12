#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() : bme(BMEConstants::CS_Pin)
{
}

bool BMESPIInterface::init()
{
    return bme.begin();
}

void BMESPIInterface::update()
{
    temperatureC = bme.readTemperature();
}

float BMESPIInterface::getTemperature()
{
    return temperatureC;
}