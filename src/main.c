#include "defs.h"
#include "settings.h"
#include "i2c.h"
#include "5110.h"
#include "dht11.h"
#include <stdio.h>

static inline void config() {
    configClock();

    configPins();

    configInterruptions();

    I2C_initialize();

    N5110_initialize();

    //DHT11_read();
}


static inline void loop() {
    CLRWDT();

    N5110_set_position(0,0);
    char buffer[100];
    switch(DHT11_read()) {
        case OK:
            //sprintf(buffer, "hum: %u, temp: %u", DHT.humidity, DHT.temperature);
            //N5110_write_string(buffer);
            N5110_write_string("OK");
            break;
        case CHECKSUM:
            N5110_write_string("chsum");
            break;
        case TIMEOUT:
            N5110_write_string("timeout");
            break;
        default:
            break;
    }

    //__delay_ms(50);
    N5110_fill(0);
    //__delay_ms(50);



    //SLEEP();
}


int main() {

    config();

    while(1) {
        loop();
    }
    return 0;
}