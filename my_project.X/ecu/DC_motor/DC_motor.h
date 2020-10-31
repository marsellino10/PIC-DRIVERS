#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

#include "../relay/relay.h"

typedef struct
{
    relay_t relay1; 
    relay_t relay2;
}dc_motor_t;


void dc_motor_init(dc_motor_t *dc_motor);
void dc_motor_move_right(dc_motor_t *dc_motor);
void dc_motor_move_left(dc_motor_t *dc_motor);
void dc_motor_stop(dc_motor_t *dc_motor);

#endif	/* DC_MOTOR_H */