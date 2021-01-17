// ==========================================================================
//
// OLED lines demo on DB103
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2019
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){
       
   namespace target = hwlib::target;
   
   auto scl      = hwlib::target::pin_oc{ 0, 4 };
   auto sda      = hwlib::target::pin_oc{ 0, 5 };
   
   auto bus       = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled      = hwlib::glcd_oled( bus ); 
   
   hwlib::graphics_random_lines( oled );
   
}
