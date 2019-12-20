#include "Adafruit_NeoPixel.h";
#include "StripController.h";
#include "PulseAnimation.h";

StripController stripController;
PulseAnimation pulseAnimation(stripController.strip());


void setup() {
  stripController.init();
  for(int i = 0; i < stripController.length; i++) {
    stripController.strip()->setPixelColor(i, 0xff0000);
  }
  stripController.show();
}

void loop() {
  pulseAnimation.update(millis());
  stripController.show();
}
