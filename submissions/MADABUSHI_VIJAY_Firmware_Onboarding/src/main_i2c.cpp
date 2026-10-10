#include <Arduino.h>
#include "BMEConstants.h"
#include "BMEI2CInterface.h"
#include "LEDController.h"

namespace
{
LEDController ledController;
unsigned long lastSensorPollMs = 0;
}

void setup()
{
    Serial.begin(115200);
    ledController.begin();
    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 I2C initialization failed; check wiring/address.");
    }
}

void loop()
{
    const unsigned long now = millis();
    float temperatureC;
    if (now - lastSensorPollMs >= BMEConstants::SENSOR_POLL_INTERVAL_MS)
    {
        lastSensorPollMs = now;
        if (BMEI2CInterfaceInstance::instance().readTemperature(temperatureC))
        {
            ledController.setTemperature(temperatureC);
            Serial.print("I2C temperature: ");
            Serial.print(temperatureC);
            Serial.println(" C");
        }
        else
        {
            Serial.println("BME280 I2C temperature read failed.");
        }
    }
    ledController.update(now);
}
