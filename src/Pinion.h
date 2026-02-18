// Pinion.h

/*  ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄
 *                                                                      
 *  Pinion                                             
 *  AVR GPIO HAL                                
 *                                                                  
 *  Version:         1.0.0                                                    
 *  Date:            2026/02/18                                               
 *  Author:          Alessio Occulto (Aloc08)                                         
 *  
 * ----------------------------------------------------------------------------
 *  DESCRIPTION:
 *  This driver is an HAL for AVR's GPIOs.
 *
 * ----------------------------------------------------------------------------
 *  SOFTWARE:
 *  - Language:       C
 *  - APIs / Libs:    stdint
 *
 * ----------------------------------------------------------------------------
 *  CREDITS:
 *  Alessio Occulto
 *  2026. Licensed Under Apache 2.0 License.
 *  ______________________________________
 *  Contacts: 
 *    -E-Mail: alessio.occulto.dev@gmail.com
 *
 * ----------------------------------------------------------------------------
 *  NOTES:
 *  - Tested on: Arduino Uno
 *  - Modifications should be performed carefully to ensure hardware compatibility.
 *
 * ----------------------------------------------------------------------------
 *  ⚠ WARNING:
 *  These Pinion GPIO functions are ISR-unsafe.
 *  Do NOT call them on pins shared with interrupts,
 *  or race conditions may occur.
 *
 *  ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄
 */


#ifndef __PINION__

#define __PINION__

#include <stdint.h>
#include "Pinion_types.h"
#include "mcu/pinion_mcu_dispatcher.h"

/* modes */
typedef enum 
{
    PINION_INPUT = 0,
    PINION_OUTPUT,
    PINION_INPUT_PULLUP
} Pinion_mode;


/* levels */
#define PINION_LOW   0
#define PINION_HIGH  1


/* Implementation */
extern const Pinion_pin pinion_pins[];
extern const uint8_t PINION_PIN_COUNT;


/* Pin Mode */
static inline void 
Pinion_pinMode(uint8_t pin, Pinion_mode mode)
{
    if (pin >= PINION_PIN_COUNT) return;

    const Pinion_pin *p = &pinion_pins[pin];

    switch (mode)
    {
        case PINION_OUTPUT:
            *p->ddr |= p->mask;
        break;

        case PINION_INPUT:
            *p->ddr &= ~p->mask;
            *p->port &= ~p->mask;
        break;

        case PINION_INPUT_PULLUP:
            *p->ddr &= ~p->mask;
            *p->port |= p->mask;
        break;
        
        default:
            return;
    }
}


/* Digital Write */
static inline void 
Pinion_digitalWrite(uint8_t pin, uint8_t value)
{
    if (pin >= PINION_PIN_COUNT) return;

    const Pinion_pin *p = &pinion_pins[pin];

    if (value == PINION_HIGH)
        *p->port |= p->mask;
    else
        *p->port &= ~p->mask;
}


/* Digital Read */
static inline uint8_t 
Pinion_digitalRead(uint8_t pin)
{
    if (pin >= PINION_PIN_COUNT) return PINION_LOW;

    const Pinion_pin *p = &pinion_pins[pin];
    return (*p->pin & p->mask) ? PINION_HIGH : PINION_LOW;
}


/* Digital Toggle */
static inline void 
Pinion_digitalToggle(uint8_t pin)
{
    if (pin >= PINION_PIN_COUNT) return;

    const Pinion_pin *p = &pinion_pins[pin];

    *p->pin = p->mask;
}


#endif


