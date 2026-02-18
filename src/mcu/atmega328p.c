// atmega328p.h

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

#ifdef PINION_MCU_ATMEGA328P

#include <avr/io.h>
#include "../Pinion_types.h"

/*
 Arduino Uno / Nano
 ------------------
 D0  -> PD0
 D1  -> PD1
 D2  -> PD2
 D3  -> PD3
 D4  -> PD4
 D5  -> PD5
 D6  -> PD6
 D7  -> PD7
 D8  -> PB0
 D9  -> PB1
 D10 -> PB2
 D11 -> PB3
 D12 -> PB4
 D13 -> PB5
 A0  -> PC0 (14)
 A1  -> PC1 (15)
 A2  -> PC2 (16)
 A3  -> PC3 (17)
 A4  -> PC4 (18)
 A5  -> PC5 (19)
*/

#ifndef A0
#define A0  14
#define A1  15
#define A2  16
#define A3  17
#define A4  18
#define A5  19
#endif

const Pinion_pin pinion_pins[] = 
{
    { &PORTD, &DDRD, &PIND, (1 << 0) }, // D0
    { &PORTD, &DDRD, &PIND, (1 << 1) }, // D1
    { &PORTD, &DDRD, &PIND, (1 << 2) }, // D2
    { &PORTD, &DDRD, &PIND, (1 << 3) }, // D3
    { &PORTD, &DDRD, &PIND, (1 << 4) }, // D4
    { &PORTD, &DDRD, &PIND, (1 << 5) }, // D5
    { &PORTD, &DDRD, &PIND, (1 << 6) }, // D6
    { &PORTD, &DDRD, &PIND, (1 << 7) }, // D7

    { &PORTB, &DDRB, &PINB, (1 << 0) }, // D8
    { &PORTB, &DDRB, &PINB, (1 << 1) }, // D9
    { &PORTB, &DDRB, &PINB, (1 << 2) }, // D10
    { &PORTB, &DDRB, &PINB, (1 << 3) }, // D11
    { &PORTB, &DDRB, &PINB, (1 << 4) }, // D12
    { &PORTB, &DDRB, &PINB, (1 << 5) }, // D13

    { &PORTC, &DDRC, &PINC, (1 << 0) }, // A0 (14)
    { &PORTC, &DDRC, &PINC, (1 << 1) }, // A1
    { &PORTC, &DDRC, &PINC, (1 << 2) }, // A2
    { &PORTC, &DDRC, &PINC, (1 << 3) }, // A3
    { &PORTC, &DDRC, &PINC, (1 << 4) }, // A4
    { &PORTC, &DDRC, &PINC, (1 << 5) }  // A5
};

const uint8_t PINION_PIN_COUNT = sizeof(pinion_pins) / sizeof(pinion_pins[0]);


#endif



