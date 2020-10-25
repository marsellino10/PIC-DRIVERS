/* 
 * File:   application.c
 * Author: marsellino medhat
 *
 * Created on 18 October 2020, 12:49
 */

#include "application.h"

led_t led[] = {
               {.port_name=PORT_C,.pin_num=pin1,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin2,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin3,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin4,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin5,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin6,.led_status=led_off},
               {.port_name=PORT_C,.pin_num=pin7,.led_status=led_off}
               };
led_t led2 = {.port_name=PORT_A,.pin_num=pin0,.led_status=led_off};
button_t button1 = {.port_name=PORT_C,.pin_num=pin0};

void led_seq(led_t *led);

int main() {
     for(int i=0;i<3;i++)
        {
            led_init(&led[i]);
        }
    unsigned char x;
    int counter = 1;
    while(1)
    {   
        x = read_button(&button1);
        if(x == 0x01)
        {
            if(counter == 1)
            {
                    led_switch_on(&led[0]);
                    __delay_ms(250);
                    led_switch_off(&led[0]);
                    __delay_ms(250);
                    counter++;
            }
            else if(counter == 2)
            {
                for(int i=0;i<2;i++)
                {
                    led_switch_on(&led[1]);
                    __delay_ms(250);
                    led_switch_off(&led[1]);
                    __delay_ms(250);
                }  
                    counter++;
            }
            else if(counter == 3)
            {
                     for(int i=0;i<3;i++)
                {
                    led_switch_on(&led[2]);
                    __delay_ms(250);
                    led_switch_off(&led[2]);
                    __delay_ms(250);
                }
                    counter++;
            }
            else if(counter == 4)
            {
                    led_switch_on(&led[0]);
                    led_switch_on(&led[1]);
                    led_switch_on(&led[2]);
                    __delay_ms(500);
                    counter++;
            }
            else if(counter == 5)
            {
                    led_switch_off(&led[0]);
                    led_switch_off(&led[1]);
                    led_switch_off(&led[2]);
                    __delay_ms(500);
                    counter = 1;      
            }
        }
       
       // led_seq(&led);
    }
    return (EXIT_SUCCESS);
}

void led_seq(led_t *led)
{
    for(int i=0;i<8;i++)
        {
            led_init(&led[i]);
        }
        __delay_ms(500);
        for(int i=0;i<4;i++)
        {
            led_switch_on(&led[0+i]);
            led_switch_on(&led[7-i]);
            __delay_ms(500);
        }
        __delay_ms(500);
}
