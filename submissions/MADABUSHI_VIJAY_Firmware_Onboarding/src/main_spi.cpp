#include <Arduino.h>
#include "BMESPIInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

namespace
{
unsigned long lastSensorPollMs = 0;
}

void setup()
{
    Serial.begin(115200);
    pinMode(BMEConstants::LED_Pin, OUTPUT);
    if (!BMESPIInterfaceInstance::instance().init()) {
        digitalWrite(BMEConstants::LED_Pin, HIGH);
        while (true) {}
    } else {
        LEDControllerInstance::instance().init();
        BMESPIInterfaceInstance::instance().update();
        LEDControllerInstance::instance().setFrequency(
            BMESPIInterfaceInstance::instance().getTemperature());
        lastSensorPollMs = millis();
    }
}

void loop()
{
    const unsigned long now = millis();
    if (now - lastSensorPollMs >= BMEConstants::SENSOR_POLL_INTERVAL_MS) {
        lastSensorPollMs = now;
        BMESPIInterfaceInstance::instance().update();
        const float temperatureC = BMESPIInterfaceInstance::instance().getTemperature();
        LEDControllerInstance::instance().setFrequency(temperatureC);
        Serial.print("SPI temperature: ");
        Serial.print(temperatureC);
        Serial.println(" C");
    }
    LEDControllerInstance::instance().update();
}
