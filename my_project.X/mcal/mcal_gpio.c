
#include "mcal_gpio.h"

static volatile unsigned char *tris_reg[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
static volatile unsigned char *lat_reg[]={&LATA,&LATB,&LATC,&LATD,&LATE};
static volatile unsigned char *port_reg[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * @brief initialize the direction of pins
 * @param port_name
 * @param pin_num
 * @param direction
 * @return void
 */
void set_pin_direction(port_name_t port_name,pins_num_t pin_num,direction_t direction)
{ 
    switch(direction)
    {
        case direction_output:
            CLR_BIT(*tris_reg[port_name],pin_num);
            break;
        case direction_input:
            SET_BIT(*tris_reg[port_name],pin_num);
            break;
        default:
            break;
    }
}

/**
 * @breif write the value in the pin
 * @param port_name
 * @param pin_num
 * @param pin_mode
 * @return void
 */
void write_pin(port_name_t port_name,pins_num_t pin_num,pin_mode_t pin_mode)
{
    switch(pin_mode)
    {
        case low:
            CLR_BIT(*lat_reg[port_name],pin_num);
            break;
        case high:
            SET_BIT(*lat_reg[port_name],pin_num);
            break;
        default :
            break;
    }
}

/**
 * @breif toggle the pin
 * @param port_name
 * @param pin_num
 * @return void
 */
void toggle_pin(port_name_t port_name,pins_num_t pin_num)
{
    TOG_BIT(*lat_reg[port_name],pin_num);
}

/**
 * @breif read the logic on the pin
 * @param port_name
 * @param pin_num
 * @return mode of the pin
 */
unsigned char read_pin(port_name_t port_name,pins_num_t pin_num)
{
    unsigned char val;
    val = READ_BIT(*port_reg[port_name],pin_num);
    return val;
}

/**
 * @brief set the direction of the whole port
 * @param port_name
 * @param direction
 * @return void
 */
void set_port_direction(port_name_t port_name,unsigned char direction)
{
    *tris_reg[port_name] = direction;
}

/**
 * @brief write the value of the whole port
 * @param port_name
 * @param value
 * @return void
 */
void write_port(port_name_t port_name,unsigned char value)
{
    *lat_reg[port_name] = value;
}

/**
 * @brief read the value of the port
 * @param port_name
 * @return the value of the port
 */
unsigned char read_port(port_name_t port_name)
{
    unsigned char value;
    value = *port_reg[port_name];
    return value;
}

/**
 * @brief toggle the value of the port
 * @param port_name
 * @return void
 */
void toggle_port(port_name_t port_name)
{
    *lat_reg[port_name] ^=  0xFF;
}