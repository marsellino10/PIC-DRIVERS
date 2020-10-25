#include "led.h"

/**
 * @brief initialize the pin of the led as output
 * @param port_name
 * @param pin_num
 */
void led_init(led_t *led)
{
    set_pin_direction(led->port_name,led->pin_num,direction_output);
    write_pin(led->port_name,led->pin_num,low);
}

/**
 * @brief switch on the led
 * @param port_name
 * @param pin_num
 */
void led_switch_on(led_t *led)
{
    write_pin(led->port_name,led->pin_num,high);
}

/**
 * @brief switch off the led
 * @param port_name
 * @param pin_num
 */
void led_switch_off(led_t *led)
{
    write_pin(led->port_name,led->pin_num,low);
}

/**
 * @brief toggle the led
 * @param port_name
 * @param pin_num
 */
void led_toggle(led_t *led)
{
    toggle_pin(led->port_name,led->pin_num);
}