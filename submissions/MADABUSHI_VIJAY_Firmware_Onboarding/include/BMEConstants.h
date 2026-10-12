#pragma once

#include <Arduino.h>


namespace BMEConstants
{
    constexpr uint8_t I2C_ADDRESS = 0x76;
    constexpr uint8_t I2C_ALTERNATE_ADDRESS = 0x77;
    constexpr uint8_t CS_Pin = 10;
    constexpr uint8_t LED_Pin = 8;
    constexpr unsigned long SENSOR_POLL_INTERVAL_MS = 1000;
    constexpr unsigned long MIN_BLINK_INTERVAL_MS = 100;
    constexpr unsigned long MAX_BLINK_INTERVAL_MS = 1000;
}
