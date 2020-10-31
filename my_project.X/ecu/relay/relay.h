#ifndef RELAY_H
#define	RELAY_H

#include "../../mcal/mcal_gpio.h"

typedef enum
{
    relay_off,
    relay_on
}relay_status_t;

typedef struct
{
    unsigned char port_name : 3;
    unsigned char pin_num : 3;
    unsigned char relay_status : 2;
}relay_t;

void relay_init(relay_t *relay);
void relay_switch_on(relay_t *relay);
void relay_switch_off(relay_t *relay);

#endif	/* RELAY_H */