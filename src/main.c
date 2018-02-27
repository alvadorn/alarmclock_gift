#include "defs.h"
#include "settings.h"
#include "spi.h"

static inline void config() {
    configClock();

    configPins();

    configInterruptions();

    initializeSPI();
}


static inline void loop() {

}


int main() {

    config();

    while(1) {
        loop();
    }

    return 0;
}