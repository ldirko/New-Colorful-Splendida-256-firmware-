//Splendida 256 NEW demoreel with palletes
//fastled fibonacci 256 leds demo
//Yaroslaw Turbin 
//https://vk.com/ldirko
//https://www.reddit.com/user/ldirko/
//https://twitter.com/ldir_ko

//controls: from start automode is enable and patterns change in loop 
//one button click change pattern to next and automode is OFF
//double click change bright in loop 0..maxbright with 7 steps. not affect to Automode
//long press activate Automode ON  


#include "OneButton.h"               // https://github.com/mathertel/OneButton
#include <FastLED.h>

#define DATA_PIN    32                //set your leds datapin   change to 32 for m5 atom lite
#define ATOMLED_PIN 27                //set your leds datapin   change to 27 for m5 atom lite
#define BUTTON_PIN_INPUT 39           //button pin              change to 39 for m5 atom lite

#define LED_TYPE    WS2812B          //leds type
#define COLOR_ORDER GRB              //color order of leds

#define MAX_POWER_MILLIAMPS 800      //write here your power in milliamps. default i set 800 mA for safet

#define NUM_COLS_PLANAR 20            // resolution of planar lookup table
#define NUM_ROWS_PLANAR 20            // resolution of planar lookup table
#define NUM_LEDS_PLANAR NUM_COLS_PLANAR*NUM_ROWS_PLANAR

#define NUM_COLS_CILINDR 45           // resolution of cilindrical lookup table
#define NUM_ROWS_CILINDR 11            // resolution of cinindrical lookup table
#define NUM_LEDS_CILINDR NUM_COLS_CILINDR*NUM_ROWS_CILINDR

#define NUM_LEDS 256                   
uint16_t lastSafeIndex = 256; 

CRGB leds [NUM_LEDS+1];

byte rain [(NUM_COLS_PLANAR+2)*(NUM_ROWS_PLANAR+2)];   


OneButton button(BUTTON_PIN_INPUT, true);

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
byte automode = 255;        //change to 0 if you dont want automode on start 
byte InitNeeded = 1;
byte brigtness = 80;

uint8_t gCurrentPatternNumber = 0;    // Index number of which pattern is current

#include "palletes.h"
#include "tables.h"
#include "patterns.h"

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, MAX_POWER_MILLIAMPS);   
  FastLED.setBrightness(brigtness);
  FastLED.clear();
  
  gTargetPalette = ( gGradientPalettes[random8(gGradientPaletteCount)]);       // shoose random pallete on start

  button.attachClick(oneClick);
  button.attachDoubleClick(doubleClick);
  button.attachDuringLongPress(longPress);
  //  button.setDebounceTicks(80);
  if (automode) Serial.println("automode On"); else Serial.println("automode Off");

}

void loop() {

  button.tick();

   EVERY_N_SECONDS( SECONDS_PER_PALETTE ) {   //random change palettes
    gCurrentPaletteNumber = random8 (gGradientPaletteCount);
    gTargetPalette = gGradientPalettes[ gCurrentPaletteNumber ];
  }

  EVERY_N_MILLISECONDS(40) {   //blend current palette to next palette
    nblendPaletteTowardPalette( gCurrentPalette, gTargetPalette, 16);
  }

  EVERY_N_SECONDS( 90 ) {  // speed of change patterns periodically
    if (automode) {
      FadeOut (150);        // fade out current effect
      gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns); //next effect
      InitNeeded=1; //flag if init something need
      FadeIn (200);        // fade in current effect
    }
  }
   
  gPatterns[gCurrentPatternNumber](); //play current pattern

  FastLED.show();
  delay(4);        //some time fast call rapidly FastLED.show() on esp32 causes flicker, this delay() is easy way to fix this 
}


static void doubleClick() {
  Serial.println("DoubleClicked! next bright");
  static byte brIndex = 3;
  static byte bright[] = {0,16,32,64,96,128,170}; //7 steps 
  brIndex = (brIndex+1)%7;
  brigtness = bright[brIndex];
  FastLED.setBrightness(brigtness);
  Serial.println(brigtness);
}

static void oneClick() {
  Serial.println("Clicked! Next pattern. automode OFF");

  gCurrentPatternNumber = (gCurrentPatternNumber + 1 + ARRAY_SIZE(gPatterns)) % ARRAY_SIZE(gPatterns); //next effect
  InitNeeded=1; //flag if init something need
  previousMillis = millis();
  automode = 0;
}

static void longPress() {
  Serial.println("Long press!");
  Serial.println("AutomodeOn");
    previousMillis = currentMillis;
    automode = 255;
}

void FadeOut (byte steps){
  for (int i=0; i<=steps; i++) {
    gPatterns[gCurrentPatternNumber]();
    byte fadeOut = lerp8by8 (brigtness, 0, 255*i/steps);
    FastLED.setBrightness(fadeOut);
    FastLED.show(); 
    delay(10);
  
  }
}

void FadeIn (byte steps){
  for (int i=steps+1; i--; i>=0) {
    gPatterns[gCurrentPatternNumber]();
    byte fadeOut = lerp8by8 (brigtness, 0, 255*i/steps);
    FastLED.setBrightness(fadeOut);
    FastLED.show(); 
    delay(10);

  }
}
