/*
 * File:   button.h
 * Author: user
 *
 * Created on 7 November 2020, 14:30
 */

#ifndef LCD_H
#define	LCD_H

/* section: includes */
#include "../../mcal/mcal_gpio.h"

#define CHAR_LCD_MODE 8
/* section: Definitions */
#define CLEAR_LCD 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define CURSOR_ON_BLINK_OFF 0x0E
#define CURSOR_ON_BLINK_ON 0x0F
#define CURSOR_OFF_BLINK_OFF 0x0C
#define DISPLAY_SHIFT_LEFT 0x18
#define DISPLAY_SHIFT_RIGHT 0x1C
#define CURSOR_SHIFT_LEFT 0x10
#define CURSOR_SHIFT_RIGHT 0x14
#define EIGHT_BIT_MODE 0x38
#define FOUR_BIT_MODE 0x28
#define CGRAM_INIT 0x40
#define DDRAM_INIT 0x80

/* section: Data types definitions 
typedef union {
    
     struct {
     unsigned char  data_portname : 4;
     unsigned char  rs_portname   : 4;
     unsigned char  en_portname   : 4;
     unsigned char  rs_pin_num    : 4;
     unsigned char  en_pin_num    : 4;
    }eight_bit; 
    
     struct {
     unsigned char  data_portname   : 4;
     unsigned char  data_pin4       : 4;
     unsigned char  data_pin5       : 4;
     unsigned char  data_pin6       : 4;
     unsigned char  data_pin7       : 4;
     unsigned char  rs_portname     : 4;
     unsigned char  en_portname     : 4;
     unsigned char  rs_pin_num      : 4;
     unsigned char  en_pin_num      : 4;
    }four_bit;
    
}mode_t;*/

typedef struct{
#if CHAR_LCD_MODE == 8
     unsigned char  data_portname : 4;
     unsigned char  rs_portname   : 4;
     unsigned char  en_portname   : 4;
     unsigned char  rs_pin_num    : 4;
     unsigned char  en_pin_num    : 4;
#elif CHAR_LCD_MODE == 4
     unsigned char  data_portname    : 4;
     unsigned char  data_pin4       : 4;
     unsigned char  data_pin5       : 4;
     unsigned char  data_pin6       : 4;
     unsigned char  data_pin7       : 4;
     unsigned char  rs_portname     : 4;
     unsigned char  en_portname     : 4;
     unsigned char  rs_pin_num      : 4;
     unsigned char  en_pin_num      : 4;
#else
#error "LCD Mode not valid !!"
#endif
}char_lcd_t;

/* section: function declarations */
void lcd_init(char_lcd_t *lcd);
void lcd_send_cmd(char_lcd_t *lcd,unsigned char cmd);
void lcd_send_char(char_lcd_t *lcd,unsigned char data);
void lcd_send_char_pos(char_lcd_t *lcd,unsigned char data,unsigned char row,unsigned char coloumn);
void lcd_send_string(char_lcd_t *lcd, char *data);
void lcd_send_string_pos(char_lcd_t *lcd,char *data,unsigned char row,unsigned char coloumn);
void lcd_send_falling_edge(char_lcd_t *lcd);
void go_to_pos(char_lcd_t *lcd,unsigned char row,unsigned char coloumn);
void clear_lcd(char_lcd_t *lcd);
void char_to_string(char num ,char *output);
void short_to_string(short num,char *output);
void int_to_string(int num,char *output);
void lcd_send_custom_char(char_lcd_t *lcd,char arr[],unsigned char row,unsigned char coloumn,unsigned char pos);

#endif	/* LCD_H */
