// ==========================================================================
//
// blink the LED on an Arduino Uno
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================
//
// based on 
// https://github.com/dwelch67/avr_samples/blob/master/blinker01/blinker01.s
//
// ==========================================================================

.global main

DDRB  = 0x04
PORTB = 0x05

main:
    ldi R16, 0b01 << 5
    out DDRB, R16

    ldi R18 ,0x00
    ldi R17, 0x00
    ldi R20, 0b01 << 5
    
blink_loop:

    ldi R19, 0xE8
delay_loop:
    inc R17
    cpi R17, 0x00
    brne delay_loop

    inc R18
    cpi R18, 0x00
    brne delay_loop

    inc R19
    cpi R19, 0x00
    brne delay_loop

    // toggle the LED pin
    eor R16, R20
    out PORTB, R16
    
    rjmp blink_loop