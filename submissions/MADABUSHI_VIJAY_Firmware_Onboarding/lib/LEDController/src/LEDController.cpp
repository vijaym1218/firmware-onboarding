#include "LEDController.h"
#include <math.h>

LEDController::LEDController()
{
}

void LEDController::init()
{
    pinMode(BMEConstants::LED_Pin, OUTPUT);
    digitalWrite(BMEConstants::LED_Pin, LOW);
    lastToggle = millis();
}

void LEDController::setFrequency(float temperatureC)
{
    if (!isfinite(temperatureC)) {
        return;
    }

    const float clampedTemperature = temperatureC < 0.0f
        ? 0.0f
        : (temperatureC > 40.0f ? 40.0f : temperatureC);
    const float temperatureFraction = clampedTemperature / 40.0f;
    const unsigned long intervalRange = BMEConstants::MAX_BLINK_INTERVAL_MS -
                                        BMEConstants::MIN_BLINK_INTERVAL_MS;
    togglePeriod = BMEConstants::MAX_BLINK_INTERVAL_MS -
                   static_cast<unsigned long>(temperatureFraction * intervalRange);
}

void LEDController::update()
{
    unsigned long now = millis();
    if (now - lastToggle >= togglePeriod) {
        lastToggle = now;
        if (ledOn) {
            ledOn = false;
            digitalWrite(BMEConstants::LED_Pin, LOW);
        } else {
            ledOn = true;
            digitalWrite(BMEConstants::LED_Pin, HIGH);
        }
    }

}
