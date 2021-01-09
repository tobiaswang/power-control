#pragma once
#include <cstdint>

extern "C" {
#include <i2c/smbus.h>
#include <linux/i2c-dev.h>
}

int i2cSet(uint32_t bus, uint32_t slaveAddr, uint32_t regAddr, uint32_t value);
int i2cGet(uint32_t bus, uint32_t slaveAddr, uint32_t regAddr);
