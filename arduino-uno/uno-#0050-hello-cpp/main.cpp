// ==========================================================================
//
// Hello world on on an Arduino Uno
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================

#include "bmptk.h"

int main(){
   
   // set baudrate	   
   uint64_t UBRR_VALUE = ((( BMPTK_XTAL * 1000UL / ( BMPTK_BAUDRATE * 16UL ))) - 1 );
   UBRR0H = (uint8_t) ( UBRR_VALUE >> 8 );
   UBRR0L = (uint8_t) UBRR_VALUE;
	  
   // format : 8 data bits, no parity, 1 stop bit
   UCSR0C = 0x06;
  
  // enable rx and tx
  UCSR0B = ( 1 << RXEN0 ) |( 1 << TXEN0 );
  
   volatile int v;
   for(;;){
      for( const char *p = "Hello world\n"; *p != '\0'; ++p ){
         
         // wait for tx empty
         while( !( UCSR0A & ( 0x01 << UDRE0 ))){ }
         
         // send char
         UDR0 = *p;
      }
      for( int32_t i = 0; i < 5000 * 1000l; ++i ){ (void)v; }
   }
}
