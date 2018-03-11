#include "dht11.h"

DHT11_status DHT11_read() {
    byte buffer[5] = {0};

    DHT11_as_output();
    dht_write = 0;
    __delay_ms(18);
    dht_write = 1;
    __delay_us(20);
    DHT11_as_input();

    unsigned short loop = 10000;
    while(dht_read == 0)
        if(loop-- == 0) return TIMEOUT;

    loop = 10000;
    while(dht_read == 1)
        if (loop-- == 0) return TIMEOUT;

    byte count = 0;
    byte index = 0;

    for (byte i = 0; i < 40; i++) {
        loop = 10000;
        while(dht_read == 0)
            if(loop-- == 0) return TIMEOUT;
        
        TMR2 = 0;
        T2CONbits.TMR2ON = 1;
        while(dht_read == 1)
            if(loop-- == 0) return TIMEOUT;
        T2CONbits.TMR2ON = 0;
        if (TMR2 > 40) buffer[index] |= (1 << (7-count));
        if (count == 0) {
            count = 7;
            index++;
        } else {
            count--;
        }
    }

    DHT.humidity = buffer[0];
    DHT.temperature = buffer[1];

    byte sum = buffer[0] + buffer[1] + buffer[2] + buffer[3];
    if (sum != buffer[4]) return CHECKSUM;
    return OK;
}

inline void DHT11_as_output() {
    dht_mode = 0;
}

inline void DHT11_as_input() {
    dht_mode = 1;
}

