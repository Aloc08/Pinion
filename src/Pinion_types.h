// Pinion_types.h

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


#ifndef __PINION_TYPES__

#define __PINION_TYPES__

#include <stdint.h>

typedef struct 
{
    volatile uint8_t *port;
    volatile uint8_t *ddr;
    volatile uint8_t *pin;
    uint8_t mask;

} Pinion_pin;


#endif
