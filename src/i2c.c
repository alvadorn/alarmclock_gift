#include "i2c.h"


void I2C_initialize() {
    SSPSTAT = 0b10000000;
    SSPCON1 = 0b00100001;
}