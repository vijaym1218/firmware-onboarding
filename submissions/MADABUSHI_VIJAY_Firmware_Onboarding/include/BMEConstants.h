#pragma once

#include <Arduino.h>

namespace BMEConstants
{
constexpr uint8_t LED_PIN = 8;
constexpr uint8_t I2C_ADDRESS = 0x76;
constexpr uint8_t SPI_CHIP_SELECT_PIN = 10;
constexpr unsigned long SENSOR_POLL_INTERVAL_MS = 1000;
constexpr float MIN_TEMPERATURE_C = 0.0f;
constexpr float MAX_TEMPERATURE_C = 40.0f;
constexpr unsigned long MIN_BLINK_INTERVAL_MS = 100;
constexpr unsigned long MAX_BLINK_INTERVAL_MS = 1000;
}
