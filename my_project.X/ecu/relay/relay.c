#include "relay.h"

void relay_init(relay_t *relay)
{
    set_pin_direction(relay->port_name,relay->pin_num,direction_output);
    write_pin(relay->port_name,relay->pin_num,low);
}

void relay_switch_on(relay_t *relay)
{
    write_pin(relay->port_name,relay->pin_num,high);
}

void relay_switch_off(relay_t *relay)
{
    write_pin(relay->port_name,relay->pin_num,low);
}