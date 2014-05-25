#include "FastLED.h"

#define NUM_LEDS 25
#define DATA_PIN 2
#define CLOCK_PIN 3

String strx;
int x;

String inputString = "";
String resultado = "";
boolean stringComplete = false;  // whether the string is complete

CRGB leds[NUM_LEDS];

void setup() {
      Serial.begin(115200);
      delay(2000);
      inputString.reserve(200);
      FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
 
}


void serialEvent() {

  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '#'){
       Serial.println(inputString);
       int valorEncendido = inputString.toInt();
       Serial.println(valorEncendido);
       leds[valorEncendido] = CHSV(255, 255, 255);
       FastLED.show();
       inputString = "";
       delay(30); 
    }
    if(inChar == ';'){
       Serial.println(inputString);  
       int valorApagado = inputString.toInt();
       Serial.println(valorApagado);
       leds[valorApagado] = CHSV(0, 0, 0);
       FastLED.show();
       inputString = "";
       delay(30); 
    }
  }
}

