// atmega2560.h

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

#ifdef PINION_MCU_ATMEGA2560


#include <avr/io.h>
#include "../Pinion_types.h"

/*
Arduino Mega 2560
-----------------
Digital pins 0–53
Analog pins A0–A15 (mapped to 54–69)
*/

#ifndef A0
#define A0  54
#define A1  55
#define A2  56
#define A3  57
#define A4  58
#define A5  59
#define A6  60
#define A7  61
#define A8  62
#define A9  63
#define A10 64
#define A11 65
#define A12 66
#define A13 67
#define A14 68
#define A15 69
#endif


/* Tabella pinion_pins */
const Pinion_pin pinion_pins[] = {
    /* Digital 0–7 -> PORTE/PINE */
    { &PORTE, &DDRE, &PINE, (1 << 0) }, // D0
    { &PORTE, &DDRE, &PINE, (1 << 1) }, // D1
    { &PORTE, &DDRE, &PINE, (1 << 4) }, // D2
    { &PORTE, &DDRE, &PINE, (1 << 5) }, // D3
    { &PORTG, &DDRG, &PING, (1 << 5) }, // D4
    { &PORTE, &DDRE, &PINE, (1 << 3) }, // D5
    { &PORTH, &DDRH, &PINH, (1 << 3) }, // D6
    { &PORTH, &DDRH, &PINH, (1 << 4) }, // D7

    /* Digital 8–13 -> PORTH/PORTB */
    { &PORTH, &DDRH, &PINH, (1 << 5) }, // D8
    { &PORTH, &DDRH, &PINH, (1 << 6) }, // D9
    { &PORTB, &DDRB, &PINB, (1 << 4) }, // D10
    { &PORTB, &DDRB, &PINB, (1 << 5) }, // D11
    { &PORTB, &DDRB, &PINB, (1 << 6) }, // D12
    { &PORTB, &DDRB, &PINB, (1 << 7) }, // D13

    /* Digital 14–21 -> PORTJ/PORTC */
    { &PORTJ, &DDRJ, &PINJ, (1 << 1) }, // D14
    { &PORTJ, &DDRJ, &PINJ, (1 << 0) }, // D15
    { &PORTJ, &DDRJ, &PINJ, (1 << 2) }, // D16
    { &PORTJ, &DDRJ, &PINJ, (1 << 3) }, // D17
    { &PORTJ, &DDRJ, &PINJ, (1 << 4) }, // D18
    { &PORTJ, &DDRJ, &PINJ, (1 << 5) }, // D19
    { &PORTJ, &DDRJ, &PINJ, (1 << 6) }, // D20
    { &PORTJ, &DDRJ, &PINJ, (1 << 7) }, // D21

    /* Digital 22–29 -> PORTA */
    { &PORTA, &DDRA, &PINA, (1 << 0) }, // D22
    { &PORTA, &DDRA, &PINA, (1 << 1) }, // D23
    { &PORTA, &DDRA, &PINA, (1 << 2) }, // D24
    { &PORTA, &DDRA, &PINA, (1 << 3) }, // D25
    { &PORTA, &DDRA, &PINA, (1 << 4) }, // D26
    { &PORTA, &DDRA, &PINA, (1 << 5) }, // D27
    { &PORTA, &DDRA, &PINA, (1 << 6) }, // D28
    { &PORTA, &DDRA, &PINA, (1 << 7) }, // D29

    /* Digital 30–37 -> PORTC */
    { &PORTC, &DDRC, &PINC, (1 << 7) }, // D30
    { &PORTC, &DDRC, &PINC, (1 << 6) }, // D31
    { &PORTC, &DDRC, &PINC, (1 << 5) }, // D32
    { &PORTC, &DDRC, &PINC, (1 << 4) }, // D33
    { &PORTC, &DDRC, &PINC, (1 << 3) }, // D34
    { &PORTC, &DDRC, &PINC, (1 << 2) }, // D35
    { &PORTC, &DDRC, &PINC, (1 << 1) }, // D36
    { &PORTC, &DDRC, &PINC, (1 << 0) }, // D37

    /* Digital 38–45 -> PORTD */
    { &PORTD, &DDRD, &PIND, (1 << 7) }, // D38
    { &PORTD, &DDRD, &PIND, (1 << 6) }, // D39
    { &PORTD, &DDRD, &PIND, (1 << 5) }, // D40
    { &PORTD, &DDRD, &PIND, (1 << 4) }, // D41
    { &PORTD, &DDRD, &PIND, (1 << 3) }, // D42
    { &PORTD, &DDRD, &PIND, (1 << 2) }, // D43
    { &PORTD, &DDRD, &PIND, (1 << 1) }, // D44
    { &PORTD, &DDRD, &PIND, (1 << 0) }, // D45

    /* Digital 46–53 -> PORTL */
    { &PORTL, &DDRL, &PINL, (1 << 0) }, // D46
    { &PORTL, &DDRL, &PINL, (1 << 1) }, // D47
    { &PORTL, &DDRL, &PINL, (1 << 2) }, // D48
    { &PORTL, &DDRL, &PINL, (1 << 3) }, // D49
    { &PORTL, &DDRL, &PINL, (1 << 4) }, // D50
    { &PORTL, &DDRL, &PINL, (1 << 5) }, // D51
    { &PORTL, &DDRL, &PINL, (1 << 6) }, // D52
    { &PORTL, &DDRL, &PINL, (1 << 7) }, // D53

    /* Analog A0–A15 -> mapped 54–69 -> PORTF/PORTK */
    { &PORTF, &DDRF, &PINF, (1 << 0) }, // A0 / 54
    { &PORTF, &DDRF, &PINF, (1 << 1) }, // A1
    { &PORTF, &DDRF, &PINF, (1 << 2) }, // A2
    { &PORTF, &DDRF, &PINF, (1 << 3) }, // A3
    { &PORTF, &DDRF, &PINF, (1 << 4) }, // A4
    { &PORTF, &DDRF, &PINF, (1 << 5) }, // A5
    { &PORTF, &DDRF, &PINF, (1 << 6) }, // A6
    { &PORTF, &DDRF, &PINF, (1 << 7) }, // A7

    { &PORTK, &DDRK, &PINK, (1 << 0) }, // A8 / 62
    { &PORTK, &DDRK, &PINK, (1 << 1) }, // A9
    { &PORTK, &DDRK, &PINK, (1 << 2) }, // A10
    { &PORTK, &DDRK, &PINK, (1 << 3) }, // A11
    { &PORTK, &DDRK, &PINK, (1 << 4) }, // A12
    { &PORTK, &DDRK, &PINK, (1 << 5) }, // A13
    { &PORTK, &DDRK, &PINK, (1 << 6) }, // A14
    { &PORTK, &DDRK, &PINK, (1 << 7) }  // A15 / 69
};

const uint8_t PINION_PIN_COUNT = sizeof(pinion_pins) / sizeof(pinion_pins[0]);

#endif


