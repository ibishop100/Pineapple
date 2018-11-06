//Pineapple wires: Red-5V Green-GND White-Top Blue-Bottom

#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN       4
#define LED_PIN_TOP   5

#define NUM_LEDS      35
#define NUM_LEDS_TOP  8

#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define BRIGHTNESS 255

CRGB leds[NUM_LEDS];
CRGB leds_top[NUM_LEDS_TOP];

#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_TOP, COLOR_ORDER>(leds_top, NUM_LEDS_TOP).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
  delay( 3000 ); // power-up safety delay

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;    // set our current dot to red
    FastLED.show();
  }

  for(int i = 0; i < NUM_LEDS_TOP; i++) {
    leds_top[i] = CRGB::Green;    // set our current dot to red
    FastLED.show();
  }

}
