// ------------
// Blink a LED the hard way, using macros found in the Arduino environment...
// Sketch works on both Photon and Uno...
// ------------

#include "Arduino.h"

// ------------
#ifdef SPARK_CORE // Particle...

int LED_PIN = D7; // This one is the little blue LED on your board.
		  // On the Photon it is next to D7, and on the Core it is next to the USB jack.

#else // ... Arduino...

int LED_PIN = 13; // normal LED location on UNO...

#endif
// ------------

int val = LOW;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {

    digitalWrite(LED_PIN, bitRead(val,0)); // use only bit 0 ...

    if ( bitRead(val, 0) ) {
	bitClear(val,0);
    } else {
	bitSet(val,0);
    }
    delay(1000);
}

