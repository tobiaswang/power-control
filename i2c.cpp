#include "i2c.hpp"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <phosphor-logging/elog-errors.hpp>
#include <xyz/openbmc_project/Common/error.hpp>

int i2cSet(uint32_t bus, uint32_t slaveAddr, uint32_t regAddr, uint32_t value)
{
    return 0;
}

int i2cGet(uint32_t bus, uint32_t slaveAddr, uint32_t regAddr)
{
    return 0;
}
