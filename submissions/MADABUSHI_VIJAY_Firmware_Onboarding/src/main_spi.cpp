#include <Arduino.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"
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
    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 SPI initialization failed; check wiring/chip select.");
    }
}

void loop()
{
    const unsigned long now = millis();
    float temperatureC;
    if (now - lastSensorPollMs >= BMEConstants::SENSOR_POLL_INTERVAL_MS)
    {
        lastSensorPollMs = now;
        if (BMESPIInterfaceInstance::instance().readTemperature(temperatureC))
        {
            ledController.setTemperature(temperatureC);
            Serial.print("SPI temperature: ");
            Serial.print(temperatureC);
            Serial.println(" C");
        }
        else
        {
            Serial.println("BME280 SPI temperature read failed.");
        }
    }
    ledController.update(now);
}
