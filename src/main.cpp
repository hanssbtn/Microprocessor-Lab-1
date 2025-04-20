// Author: Hans Sebastian         
// Net ID: hanssebastian
// Date: February 7, 2025
// Assignment: Lab 1
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"

#define CHECK_SWITCH() \
do { \
  if (!(PINA & (1 << PA0))) { \
    _delay_ms(1000); \
  } else { \
    _delay_ms(100); \
  } \
} while (0)

int main(void) {
  // setup
  initLED();
  initSwitch();

  // main task loop
  while(1){
    runLED(0);
    CHECK_SWITCH();
    runLED(1);
    CHECK_SWITCH();
    runLED(2);
    CHECK_SWITCH();
    runLED(3);
    CHECK_SWITCH();
    runLED(5);
    CHECK_SWITCH();
    runLED(6);
    CHECK_SWITCH();
  }

  return 0;
}
