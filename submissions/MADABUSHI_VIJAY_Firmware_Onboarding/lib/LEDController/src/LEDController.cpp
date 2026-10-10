#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
    lastToggleMs_ = millis();
}

void LEDController::setTemperature(float temperatureC)
{
    const float clamped = constrain(temperatureC,
                                    BMEConstants::MIN_TEMPERATURE_C,
                                    BMEConstants::MAX_TEMPERATURE_C);
    const float fraction = (clamped - BMEConstants::MIN_TEMPERATURE_C) /
                           (BMEConstants::MAX_TEMPERATURE_C - BMEConstants::MIN_TEMPERATURE_C);
    blinkIntervalMs_ = BMEConstants::MAX_BLINK_INTERVAL_MS -
                       static_cast<unsigned long>(fraction *
                           (BMEConstants::MAX_BLINK_INTERVAL_MS - BMEConstants::MIN_BLINK_INTERVAL_MS));
}

void LEDController::update(unsigned long now)
{
    if (now - lastToggleMs_ >= blinkIntervalMs_)
    {
        lastToggleMs_ = now;
        ledOn_ = !ledOn_;
        digitalWrite(BMEConstants::LED_PIN, ledOn_ ? HIGH : LOW);
    }
}
