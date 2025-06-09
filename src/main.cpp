


#include <Plaquette.h>
#include <FastLED.h>

#include <PqLEDStrip.h>
PqStripWS281X<4,RGB,16> pqStrip;  // PIN RGB_ORDER LENGTH


SineWave pqWave{2.0};
SineWave otherWave{2.0};

void begin() {

}

void step() {
  // UNCOMMENT ONE OF THE FOLLOWING FOR THE INDICATED EFFECT
 // pqWave.phase(otherWave);  // BACK AND FORTH MOVEMENT
 // pqWave.phase(0); // FIXED

 pqWave.frequency(2); // THE NUMBER OF TIMES IT REPEATS IN ONE SECOND
 pqStrip.applyWave(pqWave, 1.0);  // Float value = THE TIME DURACTION TO DISPLAY
}