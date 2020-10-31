#include "DC_motor.h"

void dc_motor_init(dc_motor_t *dc_motor)
{
    relay_init(&(dc_motor->relay1));
    relay_init(&(dc_motor->relay2));
}

void dc_motor_move_right(dc_motor_t *dc_motor)
{
    relay_switch_on(&(dc_motor->relay1));
}

void dc_motor_move_left(dc_motor_t *dc_motor)
{
    relay_switch_on(&(dc_motor->relay2));
}

void dc_motor_stop(dc_motor_t *dc_motor)
{
    relay_switch_off(&(dc_motor->relay2));
    relay_switch_off(&(dc_motor->relay1));
}