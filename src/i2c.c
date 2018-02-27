#include "i2c.h"


void SPI_initialize() {
    SSPSTAT = 0xC0;
    SSPCON1 = 0b00100001;
}

void SPI_125khz() {
    SSPCON1bits.SSPM = 2;
}

void SPI_full_speed() {
    SSPCON1bits.SSPM = 0;
}