/*
 * File:   led.h
 * Author: user
 *
 * Created on 19 October 2020, 13:29
 */

#ifndef LED_H
#define	LED_H

/* section: includes */
#include "../../mcal/mcal_gpio.h"

/* section: Data types definitions */
typedef enum
{
    led_off,
    led_on
}led_status_t;

typedef struct
{
    unsigned char port_name : 3;
    unsigned char pin_num : 3;
    unsigned char led_status : 2;
}led_t;

/* section: function declarations */
void led_init(led_t *led);
void led_switch_on(led_t *led);
void led_switch_off(led_t *led);
void led_toggle(led_t *led);


#endif	/* LED_H */

