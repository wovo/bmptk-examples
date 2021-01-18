![](logo.png)

# Basic bmptk example projects by target.

These examples show how simple assembler, 
C and C++ projects (blinky, hello)
can be set up with bmptk.
For more interesting examples, 
check hwlib and hwlib-examples.

The makefile.link is included by the 
general makefile and the makefiles in 
the subdirectories; it includes bmptk/makefile.inc.
It is assumed that bmptk is in the same directory
as these examples.

The makefile in this directory can 
clean or build (all) applications.

The makefile in each example directory can
clean, build or run the example.

If you want to see more examples of simple bare-metal
projects, do check out David Welch's work at 
https://github.com/dwelch67. 
It helped me to get started on quite a few targets.
      
(c) Wouter van Ooijen (wouter@voti.nl) 2021

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at 
http://www.boost.org/LICENSE_1_0.txt)     

status:
- arduino uno: done
- arduino due: do asm blink and cpp hello     
      