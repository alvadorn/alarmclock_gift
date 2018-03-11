#include "5110.h"
#include "font.h"

void N5110_initialize() {
    lcd_sce = 0;
    lcd_rst = 1;
    lcd_clk = 0;
    N5110_reset();
    N5110_led(1);

    // advanced features

    N5110_set_mode(MODE_CMD);
    N5110_send(0x21, MODE_CMD); // advanced commands
    N5110_send(0xC0, MODE_CMD); // contrast VOP A4
    N5110_send(0x06, MODE_CMD); // temp coeff
    N5110_send(0x13, MODE_CMD); // LCD bias
    N5110_send(0x20, MODE_CMD); // simple commands
    N5110_send(0x0C, MODE_CMD); // Display mode normal

    // clear RAM
    N5110_fill(0);
}

void N5110_reset() {
    __delay_ms(20);
    lcd_rst = 0;
    __delay_ms(25);
    lcd_rst = 1;
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
}

void N5110_write_string(const char *str) {
    const char *s = str;
    while (*s) {
        for (byte i = 0; i < 5; i++) {
            N5110_send(font[*s - 0x20][i], MODE_DATA);
        }
        s++;
    }
}

void N5110_write_data(byte data) {
    for (byte i = 0; i < 8; i++) {
        //lcd_din &= ((data >> i) & 1);
        if (data & 0x80) {
            lcd_din = 1;
        } else {
            lcd_din = 0;
        }
        data <<= 1;
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
    N5110_set_position(0,0);
    for (short i = 0; i < 504; i++) {
        N5110_send(data, MODE_DATA);
    }
}