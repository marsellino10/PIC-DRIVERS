/* 
 * File:   mcal.h
 * Author: MARSELLINO MEDHAT
 *
 * Created on 18 October 2020, 13:34
 */

#ifndef MCAL_H
#define	MCAL_H

/* section: includes */
#include "xc.h"

/* section: defines */
#define PORT_OUTPUT 0x00U
#define PORT_INPUT  0xFFU
#define MAX_PIN_NUMS 7
#define ZERO_INIT 0

/* section: macros functions */
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLR_BIT(reg,bit) (reg&= (~(1<<bit)))
#define TOG_BIT(reg,bit) (reg ^= (1<<bit))
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)

/* section: enums*/

//enum for direction of the pins
typedef enum
{
    direction_output,
    direction_input
    
}direction_t;

//enum for the num of the pins
typedef enum
{
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
            
}pins_num_t;

//enum for the port names
typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E
}port_name_t;   

//enum for the mode of the pin
typedef enum
{
    low,
    high        
}pin_mode_t;

/* section: functions declarations */
void set_pin_direction(port_name_t port_name,pins_num_t pin_num,direction_t direction);
void write_pin(port_name_t port_name,pins_num_t pin_num,pin_mode_t pin_mode);
void toggle_pin(port_name_t port_name,pins_num_t pin_num);
unsigned char read_pin(port_name_t port_name,pins_num_t pin_num);

void set_port_direction(port_name_t port_name,unsigned char direction);
void write_port(port_name_t port_name,unsigned char value);
unsigned char read_port(port_name_t port_name);
void toggle_port(port_name_t port_name);




#endif	/* MCAL_H */

