#include "button.h"

/**
 * @breif intialize the pin as input
 * @param but
 * @return void
 */
void button_init(button_t *but)
{
    set_pin_direction(but->port_name,but->pin_num,direction_input);
}

/**
 * @breif read the status of the button
 * @param but
 * @return the status of the button
 */
unsigned char read_button(button_t *but)
{
    unsigned char status;
    status = read_pin(but->port_name,but->pin_num);
    return status;
}