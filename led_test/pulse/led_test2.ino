#include <FastLED.h>

FASTLED_USING_NAMESPACE

// FastLED "100-lines-of-code" demo reel, showing just a few
// of the kinds of animation patterns you can quickly and easily
// compose using FastLED.
//
// This example also shows one easy way to define multiple
// animations patterns and have them automatically rotate.
//
// -Mark Kriegsman, December 2014

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    3
#define CLK_PIN   4
#define LED_TYPE    WS2813
#define COLOR_ORDER GRB
#define NUM_LEDS    144
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup() {
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  pinMode(CLK_PIN, INPUT_PULLUP);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  buttonState = digitalRead(CLK_PIN);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      buttonPushCounter++;
      if (buttonPushCounter > 14) { 
        buttonPushCounter = 0;
      }
    }
    delay(5);
  }

  lastButtonState = buttonState;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  leds[buttonPushCounter] = CRGB::Red;

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
