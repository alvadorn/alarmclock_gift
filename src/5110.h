#ifndef __5110_H__
#define __5110_H__

#include "defs.h"

typedef enum LCD_MODE_t {
    MODE_DATA = 0,
    MODE_CMD
} Lcd_Mode;


extern void N5110_initialize();
extern void N5110_reset();
extern inline void N5110_led(byte);
inline void N5110_set_mode(Lcd_Mode);
void N5110_send(byte, Lcd_Mode);
void N5110_fill(byte);
void N5110_set_position(byte, byte);


#endif