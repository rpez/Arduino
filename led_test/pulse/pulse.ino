#include <FastLED.h>

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    7
#define LED_TYPE    WS2813
#define COLOR_ORDER GRB
#define NUM_LEDS    144
CRGB leds[NUM_LEDS];

int brightness = 97;

int k = NUM_LEDS / 2;
int i = 0;
bool up = true;

int paletteR[] = {255, 165, 255, 220, 60, 250};
int paletteG[] = {255, 5, 160, 60, 0, 200};
int paletteB[] = {150, 0, 15, 0, 0, 70};

void setup() {
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(brightness);
}

void loop() {
  int pos = random16(NUM_LEDS);
  int color = random8(sizeof(paletteR));
  leds[pos] = CRGB(paletteR[color], paletteG[color], paletteB[color]);
  FastLED.show();
}
