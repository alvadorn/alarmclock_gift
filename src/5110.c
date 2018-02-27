#include "5110.h"

void N5110_initialize() {
    lcd_sce = 0;
    lcd_rst = 1;
    lcd_clk = 0;
    N5110_reset();
    N5110_led(1);

    // advanced features

    N5110_set_mode(MODE_CMD);
    N5110_send(0x21, MODE_CMD); // advanced commands
    N5110_send(0xA4, MODE_CMD); // contrast VOP
    N5110_send(0xB2, MODE_CMD); // normal contrast
    N5110_send(0x04, MODE_CMD); // temp coeff
    N5110_send(0x14, MODE_CMD); // LCD bias
    N5110_send(0x20, MODE_CMD); // simple commands
    N5110_send(0x0C, MODE_CMD); // Display mode normal

    // clear RAM
    N5110_fill(0);
}

void N5110_reset() {
    __delay_ms(25);
    lcd_rst = 0;
    N5110_clock();
    __delay_ms(50);
    lcd_rst = 1;
    N5110_clock();
}

inline void N5110_clock() {
    lcd_clk = 1;
    lcd_clk = 0; 
}

inline void N5110_led(byte state) {
    lcd_led = state;
}

inline void N5110_set_mode(Lcd_Mode mode) {
    lcd_dc = mode;
    N5110_clock();
}

void N5110_write_data(volatile byte data) {
    for (byte i = 7; i > 0; i--) {
        //lcd_din = (data >> i) & 1;
        data <<= 1;
        if (STATUSbits.C) {
            lcd_din |= 1;
        } else {
            lcd_din &= 0;
        }

        N5110_clock();
    }
}

void N5110_send(byte data, Lcd_Mode mode) {
    N5110_set_mode(mode);
    N5110_write_data(data);
}

void N5110_set_position(byte x, byte y) {
    N5110_send(0x20, MODE_CMD); // simple cmds
    N5110_send((0x40 | y), MODE_CMD); // set y
    N5110_send((0x80 | x), MODE_CMD); // set x
}

void N5110_fill(byte data) {
    for (byte i = 0;  i < 6; i++) {
        N5110_set_position(0, i);
        for (byte j = 0; j < 84; j++) {
            N5110_send(data, MODE_DATA);
        }
    }
}