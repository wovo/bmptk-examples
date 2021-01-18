// ==========================================================================
//
// blink the LED on an Arduino Due
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================

.cpu cortex-m0
.text
.align 2

.global main

WDT_MR         = 0x400E1A54
WDT_MR_WDDIS   = 0x1 << 15
REG_PIOB_OER   = 0x400E1010
REG_PIOB_SODR  = 0x400E1030
REG_PIOB_CODR  = 0x400E1034

wait:
   LDR R0, = 10 * 1000 * 1000
wait_loop:
   SUB R0, R0, #1
   BNE wait_loop
   MOV PC, LR

main:
   
   // kill the watchdog
   LDR R0, = WDT_MR
   LDR R1, = WDT_MR_WDDIS
   STR R1, [ R0 ]
   
   // make the GPIO pin an output   
   LDR R0, = REG_PIOB_OER
   LDR R1, = 0x01 << 27;   
   STR R1, [ R0 ]
   
blink_loop:
      
      // make the GPIO pin high
      LDR R0, = REG_PIOB_SODR
      LDR R1, = 0x01 << 27;
      STR R1, [ R0 ]

      BL wait

      // make the GPIO pin low
      LDR R0, = REG_PIOB_CODR
      LDR R1, = 0x01 << 27;
      STR R1, [ R0 ]

      BL wait
      
   b blink_loop