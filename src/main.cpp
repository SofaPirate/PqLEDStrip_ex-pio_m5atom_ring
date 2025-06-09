


#include <Plaquette.h>
#include <FastLED.h>

#include <PqLEDStrip.h>
PqStripWS281X<4,RGB,16> pqStrip;  // PIN RGB_ORDER LENGTH


SineWave pqWave{2.0};
SineWave otherWave{2.0};

void begin() {

}

void step() {
 // pqWave.phase(otherWave);  // BACK AND FORTH MOVEMENT
 pqWave.phase(0); // FIXED
 
 pqWave.frequency(2);
 pqStrip.applyWave(pqWave, 1.0);  
}