#include <FastLED.h>

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    3
//#define CLK_PIN   4
#define LED_TYPE    WS2813
#define COLOR_ORDER GRB
#define NUM_LEDS    144
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

uint8_t gHue = 0; // rotating "base color" used by many of the patterns
int offset = 13;
int column = 13;
  
void loop()
{
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  displayLetter('s', offset, 255, 0, 0);
  displayLetter('e', offset + 7, 255, 255, 0);
  displayLetter('n', offset + 14, 255, 0, 255);
  displayLetter('d', offset + 20, 0, 255, 255);

  displayLetter('n', offset + 34, 0, 0, 255);
  displayLetter('u', offset + 40, 255, 255, 0);
  displayLetter('d', offset + 47, 255, 255, 255);
  displayLetter('e', offset + 54, 0, 255, 0);
  displayLetter('s', offset + 61, 0, 255, 255);
  
  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 1 ) { gHue += 3; }
  EVERY_N_MILLISECONDS( 75 ) {
    if (offset < -80) {
      offset = 14;
    }
    offset -= 1;
  }
}

void displayLetter(char letter, int offset, int r, int g, int b) {
  switch(letter) {
    case 'e':
      pixel(offset + 0, 0, r, g, b);
      pixel(offset + 1, 0, r, g, b);
      pixel(offset + 2, 0, r, g, b);
      pixel(offset + 3, 0, r, g, b);
      pixel(offset + 4, 0, r, g, b);
      pixel(offset + 5, 0, r, g, b);
      pixel(offset + 0, 1, r, g, b);
      pixel(offset + 0, 2, r, g, b);
      pixel(offset + 1, 2, r, g, b);
      pixel(offset + 2, 2, r, g, b);
      pixel(offset + 3, 2, r, g, b);
      pixel(offset + 4, 2, r, g, b);
      pixel(offset + 5, 2, r, g, b);
      pixel(offset + 0, 3, r, g, b);
      pixel(offset + 0, 4, r, g, b);
      pixel(offset + 1, 4, r, g, b);
      pixel(offset + 2, 4, r, g, b);
      pixel(offset + 3, 4, r, g, b);
      pixel(offset + 4, 4, r, g, b);
      pixel(offset + 5, 4, r, g, b);
      break;
    case 'd':
      pixel(offset + 1, 0, r, g, b);
      pixel(offset + 2, 0, r, g, b);
      pixel(offset + 3, 0, r, g, b);
      pixel(offset + 4, 0, r, g, b);
      pixel(offset + 0, 0, r, g, b);
      pixel(offset + 0, 1, r, g, b);
      pixel(offset + 0, 2, r, g, b);
      pixel(offset + 0, 3, r, g, b);
      pixel(offset + 0, 4, r, g, b);
      pixel(offset + 1, 4, r, g, b);
      pixel(offset + 2, 4, r, g, b);
      pixel(offset + 3, 4, r, g, b);
      pixel(offset + 4, 4, r, g, b);
      pixel(offset + 5, 1, r, g, b);
      pixel(offset + 5, 2, r, g, b);
      pixel(offset + 5, 3, r, g, b);
      break;
    case 'n':
      pixel(offset + 0, 0, r, g, b);
      pixel(offset + 0, 1, r, g, b);
      pixel(offset + 0, 2, r, g, b);
      pixel(offset + 0, 3, r, g, b);
      pixel(offset + 0, 4, r, g, b);
      pixel(offset + 1, 1, r, g, b);
      pixel(offset + 2, 2, r, g, b);
      pixel(offset + 3, 3, r, g, b);
      pixel(offset + 4, 0, r, g, b);
      pixel(offset + 4, 1, r, g, b);
      pixel(offset + 4, 2, r, g, b);
      pixel(offset + 4, 3, r, g, b);
      pixel(offset + 4, 4, r, g, b);
      break;
    case 's':
      pixel(offset + 0, 0, r, g, b);
      pixel(offset + 1, 0, r, g, b);
      pixel(offset + 2, 0, r, g, b);
      pixel(offset + 3, 0, r, g, b);
      pixel(offset + 4, 0, r, g, b);
      pixel(offset + 5, 0, r, g, b);
      pixel(offset + 0, 1, r, g, b);
      pixel(offset + 0, 2, r, g, b);
      pixel(offset + 1, 2, r, g, b);
      pixel(offset + 2, 2, r, g, b);
      pixel(offset + 3, 2, r, g, b);
      pixel(offset + 4, 2, r, g, b);
      pixel(offset + 5, 2, r, g, b);
      pixel(offset + 5, 3, r, g, b);
      pixel(offset + 0, 4, r, g, b);
      pixel(offset + 1, 4, r, g, b);
      pixel(offset + 2, 4, r, g, b);
      pixel(offset + 3, 4, r, g, b);
      pixel(offset + 4, 4, r, g, b);
      pixel(offset + 5, 4, r, g, b);
      break;
    case 'u':
      pixel(offset + 0, 0, r, g, b);
      pixel(offset + 0, 1, r, g, b);
      pixel(offset + 0, 2, r, g, b);
      pixel(offset + 0, 3, r, g, b);
      pixel(offset + 1, 4, r, g, b);
      pixel(offset + 2, 4, r, g, b);
      pixel(offset + 3, 4, r, g, b);
      pixel(offset + 4, 4, r, g, b);
      pixel(offset + 5, 0, r, g, b);
      pixel(offset + 5, 1, r, g, b);
      pixel(offset + 5, 2, r, g, b);
      pixel(offset + 5, 3, r, g, b);
      break;
    default:
      break;
  }
}

void pixel(int x, int y, int r, int g, int b) {
  if (x < 13 && x >= 0) {
    leds[x + y * column] = CRGB(r, g, b);
  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 1);
}
