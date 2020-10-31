/* 
 * File:   application.c
 * Author: marsellino medhat
 *
 * Created on 18 October 2020, 12:49
 */

#include "application.h"

void robot_move_forward(void);
void robot_move_backward(void);
void robot_twist_right(void);
void robot_twist_left(void);
void robot_stop(void);

dc_motor_t motor1 = {{.port_name = PORT_A,.pin_num = pin0,.relay_status = relay_off},
                     {.port_name = PORT_A,.pin_num = pin1,.relay_status = relay_off}
                    };
dc_motor_t motor2 = {{.port_name = PORT_A,.pin_num = pin2,.relay_status = relay_off},
                     {.port_name = PORT_A,.pin_num = pin3,.relay_status = relay_off}
                    };
dc_motor_t motor3 = {{.port_name = PORT_B,.pin_num = pin0,.relay_status = relay_off},
                     {.port_name = PORT_B,.pin_num = pin1,.relay_status = relay_off}
                    };
dc_motor_t motor4 = {{.port_name = PORT_B,.pin_num = pin2,.relay_status = relay_off},
                     {.port_name = PORT_B,.pin_num = pin3,.relay_status = relay_off}
                    };

int main() {
    dc_motor_init(&motor1);
    dc_motor_init(&motor2);
    dc_motor_init(&motor3);
    dc_motor_init(&motor4);
    unsigned char x;
    while(1)
    {   
        x = read_port(PORT_C); 
        if(x == 0x01)
        {
            robot_move_forward();
        }
        else if(x == 0x02)
        {
            robot_move_backward();
        }
        else if(x == 0x04)
        {
            robot_twist_right();
        }
        else if(x == 0x08)
        {
            robot_twist_left();
        }
        else
        {
            robot_stop();
        }
        
    }
    return (EXIT_SUCCESS);
}

void robot_move_forward(void)
{
            dc_motor_move_right(&motor1);
            dc_motor_move_right(&motor2);
            dc_motor_move_right(&motor3);
            dc_motor_move_right(&motor4);
}

void robot_move_backward(void)
{
            dc_motor_move_left(&motor1);
            dc_motor_move_left(&motor2);
            dc_motor_move_left(&motor3);
            dc_motor_move_left(&motor4);
}

void robot_twist_right(void)
{
            dc_motor_move_right(&motor1);
            dc_motor_move_right(&motor2);
            dc_motor_move_left(&motor3);
            dc_motor_move_left(&motor4);
}

void robot_twist_left(void)
{
            dc_motor_move_left(&motor1);
            dc_motor_move_left(&motor2);
            dc_motor_move_right(&motor3);
            dc_motor_move_right(&motor4);
}

void robot_stop(void)
{
            dc_motor_stop(&motor1);
            dc_motor_stop(&motor2);
            dc_motor_stop(&motor3);
            dc_motor_stop(&motor4);
}
