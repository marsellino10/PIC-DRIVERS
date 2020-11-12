#include "lcd.h"

/**
 * @breif initialize the mode of the lcd
 * @param lcd
 */
void lcd_init(char_lcd_t *lcd)
{
#if CHAR_LCD_MODE == 8
        set_port_direction(lcd->data_portname,0x00);
        write_port(lcd->data_portname,0x00);
        set_pin_direction(lcd->en_portname,lcd->en_pin_num,direction_output);
        write_pin(lcd->en_portname,lcd->en_pin_num,low);
        set_pin_direction(lcd->rs_portname,lcd->rs_pin_num,direction_output);
        write_pin(lcd->rs_portname,lcd->rs_pin_num,low);
        
            lcd_send_cmd(lcd, CLEAR_LCD);
            lcd_send_cmd(lcd, RETURN_HOME);
            lcd_send_cmd(lcd, CURSOR_ON_BLINK_OFF);
            lcd_send_cmd(lcd, EIGHT_BIT_MODE);
            lcd_send_cmd(lcd, DDRAM_INIT);
        
  #elif CHAR_LCD_MODE == 4
            set_pin_direction(lcd->data_portname,lcd->data_pin4,direction_output);
            write_pin(lcd->data_portname,lcd->data_pin4,low);
            set_pin_direction(lcd->data_portname,lcd->data_pin5,direction_output); 
            write_pin(lcd->data_portname,lcd->data_pin5,low);
            set_pin_direction(lcd->data_portname,lcd->data_pin6,direction_output);
            write_pin(lcd->data_portname,lcd->data_pin6,low);
            set_pin_direction(lcd->data_portname,lcd->data_pin7,direction_output);
            write_pin(lcd->data_portname,lcd->data_pin7,low);
            set_pin_direction(lcd->en_portname,lcd->en_pin_num,direction_output);
            write_pin(lcd->en_portname,lcd->en_pin_num,low);
            set_pin_direction(lcd->rs_portname,lcd->rs_pin_num,direction_output);
            write_pin(lcd->rs_portname,lcd->rs_pin_num,low);
            
            lcd_send_cmd(lcd, CLEAR_LCD);
            lcd_send_cmd(lcd, RETURN_HOME);
            lcd_send_cmd(lcd, CURSOR_ON_BLINK_OFF);
            lcd_send_cmd(lcd, FOUR_BIT_MODE);
            lcd_send_cmd(lcd, DDRAM_INIT);
            
#endif
       
}

/**
 * @brief send commands to lcd
 * @param lcd
 * @param cmd
 */
void lcd_send_cmd(char_lcd_t *lcd,unsigned char cmd)
{
    #if CHAR_LCD_MODE == 8
            write_pin(lcd->rs_portname,lcd->rs_pin_num,low);
            write_port(lcd->data_portname,cmd);
            lcd_send_falling_edge(lcd);
            __delay_ms(1);
    #elif CHAR_LCD_MODE==4
            write_pin(lcd->rs_portname,lcd->rs_pin_num,low);
            write_pin(lcd->data_portname,lcd->data_pin4,(cmd>>4)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin5,(cmd>>5)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin6,(cmd>>6)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin7,(cmd>>7)&0x01);
            lcd_send_falling_edge(lcd);
            write_pin(lcd->rs_portname,lcd->rs_pin_num,low);
            write_pin(lcd->data_portname,lcd->data_pin4,(cmd>>0)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin5,(cmd>>1)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin6,(cmd>>2)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin7,(cmd>>3)&0x01);
            lcd_send_falling_edge(lcd);
            __delay_ms(1);
#endif
}


/**
 * @brief send data to the lcd
 * @param lcd
 * @param data
 */
void lcd_send_char(char_lcd_t *lcd,unsigned char data)
{
    #if CHAR_LCD_MODE == 8
            write_pin(lcd->rs_portname,lcd->rs_pin_num,high);
            write_port(lcd->data_portname,data);
            lcd_send_falling_edge(lcd);
    #elif CHAR_LCD_MODE==4
            write_pin(lcd->rs_portname,lcd->rs_pin_num,1);
            write_pin(lcd->data_portname,lcd->data_pin4,(data>>4)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin5,(data>>5)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin6,(data>>6)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin7,(data>>7)&0x01);
            lcd_send_falling_edge(lcd);
            write_pin(lcd->rs_portname,lcd->rs_pin_num,1);
            write_pin(lcd->data_portname,lcd->data_pin4,(data>>0)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin5,(data>>1)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin6,(data>>2)&0x01);
            write_pin(lcd->data_portname,lcd->data_pin7,(data>>3)&0x01);
            lcd_send_falling_edge(lcd);
            //__delay_ms(1);
#endif
}


/**
 * @brief send data to the lcd in a certain position
 * @param lcd
 * @param data
 * @param row
 * @param coloumn
 */
void lcd_send_char_pos(char_lcd_t *lcd,unsigned char data,unsigned char row,unsigned char coloumn)
{
    go_to_pos(lcd,row,coloumn);
    lcd_send_char(lcd,data);
}

/**
 * @breif send string to the lcd
 * @param lcd
 * @param data
 */
void lcd_send_string(char_lcd_t *lcd, char *data)
{
    while(*data != '\0')
    {
        lcd_send_char(lcd,*data);
        data++;
    }
}

/**
 * @breif send string to the lcd in a certain position
 * @param lcd
 * @param data
 * @param row
 * @param coloumn
 */
void lcd_send_string_pos(char_lcd_t *lcd,char *data,unsigned char row,unsigned char coloumn)
{
    go_to_pos(lcd,row,coloumn);
    lcd_send_string(lcd,data);
}

/**
 * @breif set cursor in a certain position
 * @param lcd
 * @param row
 * @param coloumn
 */
void go_to_pos(char_lcd_t *lcd,unsigned char row,unsigned char coloumn)
{
    coloumn--;
    if(row == 1)
        lcd_send_cmd(lcd,(0x80+coloumn));
    else if(row == 2)
        lcd_send_cmd(lcd,(0xC0+coloumn));
    else if(row == 4)
        lcd_send_cmd(lcd,(0xE0+coloumn));
}

/**
 * @breif send falling edge for the enable pin in the lcd
 * @param lcd
 */
void lcd_send_falling_edge(char_lcd_t *lcd)
{
    #if CHAR_LCD_MODE == 8
    write_pin(lcd->en_portname,lcd->en_pin_num,high);
    __delay_us(200);
    write_pin(lcd->en_portname, lcd->en_pin_num, low);
#elif CHAR_LCD_MODE==4
    write_pin(lcd->en_portname,lcd->en_pin_num, high);
    __delay_us(200);
    write_pin(lcd->en_portname, lcd->en_pin_num, low);
#endif
    
}

/**
 * @breif clear the lcd
 * @param lcd
 */
void clear_lcd(char_lcd_t *lcd)
{
    lcd_send_cmd( lcd, CLEAR_LCD);  
}

void char_to_string(char num,char *output)
{
    sprintf(output,"%i",num);
}

void short_to_string(short num,char *output)
{
    sprintf(output,"%i",num);
}

void int_to_string(int num,char *output)
{
    sprintf(output,"%i",num);
}

void lcd_send_custom_char(char_lcd_t *lcd,char arr[],unsigned char row,unsigned char coloumn,unsigned char pos)
{
    lcd_send_cmd(lcd,CGRAM_INIT + (pos * 8));
    for(unsigned char i=0;i<8;i++)
    {
        lcd_send_char(lcd,arr[i]);
    }
    lcd_send_cmd(lcd,RETURN_HOME);
    lcd_send_char_pos(lcd,pos,row,coloumn);
}