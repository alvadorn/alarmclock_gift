#include "settings.h"


inline void configClock() {
    OSCCON = 0b01100010;
}


inline void configVoltage() {
    
}

inline void configPins() {
    // RA4 and RA5 as output
    TRISA = 0b11001111;

    // RB4 and RB6 as output
    TRISB = 0b10101111;

    /**
     * RC0 -> BTN Down IN
     * RC1 -> BTN Left IN
     * RC2 -> BTN Center IN
     * RC3 -> SCLK OUT
     * RC4 -> DC OUT
     * RC5 -> SDIN OUT
     * RC6 -> LED Control OUT
     * RC7 -> DHT in/out
    */
    TRISC = 0x07;
       
}

inline void configInterruptions() {
    
}