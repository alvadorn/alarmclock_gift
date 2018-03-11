#ifndef __DEFS_H__
#define __DEFS_H__


#include <xc.h>
#include <pic18f14k50.h>


// CONFIG1L
#pragma config CPUDIV=NOCLKDIV
#pragma config USBDIV=OFF


// CONFIG1H
#pragma config FOSC=IRC

// CONFIG2L
#pragma config BOREN=NOSLP
#pragma config BORV=30

// CONFIG2H
#pragma config WDTEN=ON
#pragma config WDTPS=32768

// CONFIG3H
#pragma config HFOFST=OFF
#pragma config MCLRE=ON



#define _XTAL_FREQ 8000000 // 2 MHz

#define NULL 0
typedef unsigned char byte;


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
#define dht_mode TRISCbits.TRISC7

// buzzer
#define buzzer LATBbits.LB5


#endif