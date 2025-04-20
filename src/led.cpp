// Author: Hans Sebastian         
// Net ID: hanssebastian
// Date: February 7, 2025
// Assignment: Lab 1
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

#define LED4 0
#define LED5 1 
#define LED6 2
#define LED7 3
#define LED8 4
#define LED9 5
#define LED10 6
#define LED11 7

// initLED which returns void and takes no parameters
void initLED(){
    DDRB |= (1 << PG4) | (1 << PG5);
    DDRH |= (1 << PH3) | (1 << PH4) | (1 << PH5) | (1 << PH6);
    DDRG |= (1 << PG5);
    DDRE |= (1 << PE3);

    // Turn off all ports
    PORTB &= 0;
    PORTE &= 0;
    PORTG &= 0;
    PORTH &= 0;
}

// turnOnLED which returns void and takes in an unsigned int parameter called led
void turnOnLED(unsigned int led){
    switch (led) {
        case LED4: {
            PORTG |= 1 << PORTG5;
        } break;
        case LED5: {
            PORTE |= 1 << PORTE3;
        } break;
        case LED6: 
        case LED7: 
        case LED8: 
        case LED9: {
            // led = 2, 3, 4, 5 -> port H2, H3, H4, H5
            // led + 1 = 3, 4, 5, 6 -> port H3, H4, H5, H6
            PORTH |= 1 << (1 + led); 
        } break;
        case LED10:
        case LED11: {
            // led = 6, 7 -> port B6, B7
            // led = 4, 5 -> port B4, B5
            PORTB |= 1 << (led - 2);
        } break;
        default:
            break;
    }
}

// turnOffLED which returns void and takes in an unsigned int parameter called led
void turnOffLED(unsigned int led){
    switch (led) {
        case LED4: {
            PORTG &= ~(1 << PORTG5);
        } break;
        case LED5: {
            PORTE &= ~(1 << PORTE3);
        } break;
        case LED6: 
        case LED7: 
        case LED8: 
        case LED9: {
            // led = 2, 3, 4, 5 -> port H2, H3, H4, H5
            // led + 1 = 3, 4, 5, 6 -> port H3, H4, H5, H6
            PORTH &= ~(1 << (1 + led)); 
        } break;
        case LED10:
        case LED11: {
            // led = 6, 7 -> port B6, B7
            // led = 4, 5 -> port B4, B5
            PORTB &= ~(1 << (led - 2));
        } break;
        default:
            break;
    }
}

// [4][5][6][7][8][9][10][11]
// [1][0][0][0][0][0][0][1] -> 0
// [0][1][0][0][0][0][1][0] -> 1
// [0][0][1][0][0][1][0][0] -> 2
// [0][0][0][1][1][0][0][0] -> 3
// [0][0][1][0][0][1][0][0] -> 5
// [0][1][0][0][0][0][1][0] -> 6

// runLED which returns void and takes in an unsigned int parameter called led
void runLED(unsigned int led){
    switch (led) {
        case 0: {
            turnOffLED(LED5);
            turnOffLED(LED10);
            turnOnLED(LED4);
            turnOnLED(LED11);
        } break;
        case 1: {
            turnOffLED(LED4);
            turnOffLED(LED11);
            turnOnLED(LED5);
            turnOnLED(LED10);
        } break;
        case 2: {
            turnOffLED(LED5);
            turnOffLED(LED10);
            turnOnLED(LED6);
            turnOnLED(LED9);
        } break;
        case 3: {
            turnOffLED(LED6);
            turnOffLED(LED9);
            turnOnLED(LED7);
            turnOnLED(LED8);
        } break;
        case 5: {
            turnOffLED(LED7);
            turnOffLED(LED8);
            turnOnLED(LED6);
            turnOnLED(LED9);
        } break;
        case 6: {
            turnOffLED(LED6);
            turnOffLED(LED9);
            turnOnLED(LED5);
            turnOnLED(LED10);
        } break;
    }
}
