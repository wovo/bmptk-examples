// ==========================================================================
//
// Hello world on DB103 (LPC1114)
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2017
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================

#include "bmptk.h"

int main( void ){
   
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;   
   
   // enable the clock to port A
   PMC->PMC_PCER0 = 1 << ID_PIOA;
	
   // disable PIO Control on PA9 and set up for Peripheral A
	PIOA->PIO_PDR   = PIO_PA8; 
	PIOA->PIO_ABSR &= ~PIO_PA8; 
	PIOA->PIO_PDR   = PIO_PA9; 
	PIOA->PIO_ABSR &= ~PIO_PA9; 

	// enable the clock to the UART
   PMC->PMC_PCER0 = ( 0x01 << ID_UART );
   
   Uart * uart = UART;

   // Reset and disable receiver and transmitter.
   uart->UART_CR = UART_CR_RSTRX | UART_CR_RSTTX | UART_CR_RXDIS | UART_CR_TXDIS;

   // Set the baudrate 
   uart->UART_BRGR = 748800 / BMPTK_BAUDRATE; 

   // No parity, normal channel mode.
   uart->UART_MR = UART_MR_PAR_NO;

   // Disable all interrupts.	  
   uart->UART_IDR = 0xFFFFFFFF;   

   // Enable the receiver and the trasmitter.
   uart->UART_CR = UART_CR_RXEN | UART_CR_TXEN;      

   volatile int v;
   for(;;){
      for( const char *p = "Hello world\n"; *p != '\0'; ++p ){
         
         // wait for tx empty
         while( ( uart->UART_SR & 2 ) == 0 ){ }
         
         // send char
         uart->UART_THR = *p;
      }
      for( int32_t i = 0; i < 5000 * 1000l; ++i ){ (void)v; }
   }
   
}
