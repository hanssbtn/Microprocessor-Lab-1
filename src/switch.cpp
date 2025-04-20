// Author: Hans Sebastian         
// Net ID: hanssebastian
// Date: February 7, 2025
// Assignment: Lab 1
//----------------------------------------------------------------------//

#include <avr/io.h>

// initSwitch returns void and takes no parameters
void initSwitch() {
    DDRA &= ~(1 << DDA0);
    PORTA |= (1 << PORTA0); // enable pull up resistor.
}
