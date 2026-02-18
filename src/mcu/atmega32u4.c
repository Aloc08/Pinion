// atmega32u4.h

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
 *  - APIs / Libs:    avr/io.h
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


#include "pinion_mcu_dispatcher.h"

#ifdef PINION_MCU_ATMEGA32U4


#include <avr/io.h>
#include "../Pinion_types.h"

/*
Arduino Leonardo / Micro
-----------------------
Digital pins 0–13
Analog pins A0–A5 (mapped 18–23)
*/

#ifndef A0
#define A0  18
#define A1  19
#define A2  20
#define A3  21
#define A4  22
#define A5  23
#endif

/* Tabella pinion_pins */
const Pinion_pin pinion_pins[] = {
    /* Digital 0–7 -> PORTD */
    { &PORTD, &DDRD, &PIND, (1 << 2) }, // D0 (RX)
    { &PORTD, &DDRD, &PIND, (1 << 3) }, // D1 (TX)
    { &PORTD, &DDRD, &PIND, (1 << 0) }, // D2
    { &PORTD, &DDRD, &PIND, (1 << 1) }, // D3
    { &PORTD, &DDRD, &PIND, (1 << 4) }, // D4
    { &PORTC, &DDRC, &PINC, (1 << 6) }, // D5
    { &PORTD, &DDRD, &PIND, (1 << 7) }, // D6
    { &PORTB, &DDRB, &PINB, (1 << 4) }, // D7

    /* Digital 8–13 -> PORTB/PORTF */
    { &PORTB, &DDRB, &PINB, (1 << 5) }, // D8
    { &PORTB, &DDRB, &PINB, (1 << 6) }, // D9
    { &PORTB, &DDRB, &PINB, (1 << 7) }, // D10
    { &PORTF, &DDRF, &PINF, (1 << 7) }, // D11
    { &PORTF, &DDRF, &PINF, (1 << 6) }, // D12
    { &PORTF, &DDRF, &PINF, (1 << 5) }, // D13

    /* Analog pins A0–A5 -> mapped 18–23 -> PORTF */
    { &PORTF, &DDRF, &PINF, (1 << 0) }, // A0 / 18
    { &PORTF, &DDRF, &PINF, (1 << 1) }, // A1
    { &PORTF, &DDRF, &PINF, (1 << 2) }, // A2
    { &PORTF, &DDRF, &PINF, (1 << 3) }, // A3
    { &PORTF, &DDRF, &PINF, (1 << 4) }, // A4
    { &PORTF, &DDRF, &PINF, (1 << 5) }  // A5 / 23
};


const uint8_t PINION_PIN_COUNT = sizeof(pinion_pins) / sizeof(pinion_pins[0]);


#endif


