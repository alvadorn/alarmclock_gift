#include "defs.h"
#include "settings.h"
#include "i2c.h"
#include "5110.h"

static inline void config() {
    configClock();

    configPins();

    configInterruptions();

    I2C_initialize();

    N5110_initialize();
}


static inline void loop() {
    CLRWDT();

    SLEEP();
}


int main() {

    config();

    while(1) {
        loop();
    }
    return 0;
}