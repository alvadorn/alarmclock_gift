#ifndef __DEFS_H__
#define __DEFS_H__


#include <xc.h>
#include <pic18f14k50.h>

#define _XTAL_FREQ 8000000 // 2 MHz


// pins
// lcd pins
#define lcd_clk LATCbits.LC3
#define lcd_dc LATCbits.LC4
#define lcd_din LATCbits.LC5
#define lcd_led LATCbits.LC6 
#define lcd_sce LATAbits.LA4
#define lcd_rst LATAbits.LA5

// button pins
#define btn_up PORTAbits.RA0 
#define btn_right PORTAbits.RA1 
#define btn_down PORTCbits.RC0
#define btn_left PORTCbits.RC1
#define btn_center PORTCbits.RC2

// DHT pins
#define dht_read PORTCbits.RC7
#define dht_write LATCbits.LC7

// buzzer
#define buzzer LATBbits.LB5


#endif