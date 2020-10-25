/*
 * File:   button.h
 * Author: user
 *
 * Created on 25 October 2020, 15:04
 */

#ifndef BUTTON_H
#define	BUTTON_H

/* section: includes */
#include "../../mcal/mcal_gpio.h"

/* section: Data types definitions */
typedef enum
{
    button_not_pressed,
    button_pressed
}button_status_t;

typedef struct
{
    unsigned char port_name : 3;
    unsigned char pin_num : 3;
    unsigned char button_status : 2;
}button_t;

/* section: function declarations */
void button_init(button_t *but);
unsigned char read_button(button_t *but);
#endif	/* BUTTON_H */

