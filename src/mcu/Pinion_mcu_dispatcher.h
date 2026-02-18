// Pinion_mcu_dispatcher.h

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
 *  - APIs / Libs:    N/A
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


#ifndef PINION_MCU_DISPATCHER_H
#define PINION_MCU_DISPATCHER_H

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
    #define PINION_MCU_ATMEGA328P

#elif defined(__AVR_ATmega2560__)
    #define PINION_MCU_ATMEGA2560

#elif defined(__AVR_ATmega32U4__)
    #define PINION_MCU_ATMEGA32U4

#else
    #error "[Pinion] Error: Unsupported MCU"

#endif

#endif


