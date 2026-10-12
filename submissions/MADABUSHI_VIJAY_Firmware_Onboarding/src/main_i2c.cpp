#include <Arduino.h>
#include "BMEI2CInterface.h"
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
    if (!BMEI2CInterfaceInstance::instance().init()) {
        digitalWrite(BMEConstants::LED_Pin, HIGH);
        while (true) {}
    } else {
        LEDControllerInstance::instance().init();
        BMEI2CInterfaceInstance::instance().update();
        LEDControllerInstance::instance().setFrequency(
            BMEI2CInterfaceInstance::instance().getTemperature());
        lastSensorPollMs = millis();
    }
}

void loop()
{
    const unsigned long now = millis();
    if (now - lastSensorPollMs >= BMEConstants::SENSOR_POLL_INTERVAL_MS) {
        lastSensorPollMs = now;
        BMEI2CInterfaceInstance::instance().update();
        const float temperatureC = BMEI2CInterfaceInstance::instance().getTemperature();
        LEDControllerInstance::instance().setFrequency(temperatureC);
        Serial.print("I2C temperature: ");
        Serial.print(temperatureC);
        Serial.println(" C");
    }
    LEDControllerInstance::instance().update();
}
