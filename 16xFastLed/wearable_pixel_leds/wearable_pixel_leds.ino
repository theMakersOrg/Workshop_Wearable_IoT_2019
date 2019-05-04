#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

#define DATA_PIN D1                // The pin we send the LED colour information to.

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
      // sets up our array of LEDs as well as what type and how many we are using.
      FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 

  // For each LED in the strip starting with the first, 
  // then in the next loop use the second, etc, until
  // we get to the NUM_LEDS strip length.
  
  for(int i = 0; i < NUM_LEDS; i++)   
  { 
    // Turn the LED on, then pause
    leds[i] = CRGB::Red;              // set the colour to red
    FastLED.show();                   // send our colour information to the LED Strip
    delay(100);                       // Wait for 100milliseconds (1/10th of a second
    
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;            // Turn Off the LED
    FastLED.show();
    delay(100);
  }

    for(int i = 0; i < NUM_LEDS; i++)
  { 
    // Turn the LED on, then pause
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(100);
    
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

    for(int i = 0; i < NUM_LEDS; i++)
  { 
    // Turn the LED on, then pause
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(100);
    
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(100);
  }
}
