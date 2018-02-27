#include "defs.h"
#include "settings.h"
#include "spi.h"
#include "5110.h"

static inline void config() {
    configClock();

    configPins();

    configInterruptions();

    initializeSPI();

    N5110_initialize();
}


static inline void loop() {
    CLRWDT();
}


int main() {

    config();

    while(1) {
        loop();
    }

    return 0;
}