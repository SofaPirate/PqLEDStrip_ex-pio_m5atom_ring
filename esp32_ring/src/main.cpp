
// THIS EXAMPLE IS PSEUDOCODE AND DOES NOT COMPILE

#include <Plaquette.h>
#include <FastLED.h>

#include <PqLEDStrip.h>
PqStripWS281X<4, RGB, 16> pqStrip; // <PIN RGB_ORDER LENGTH>
/*
PqStripWS281X<16, RGB, 16> pqStrip16; // <PIN RGB_ORDER LENGTH>
PqStripWS281X<17, RGB, 16> pqStrip17; // <PIN RGB_ORDER LENGTH>
PqStripWS281X<5, RGB, 16> pqStrip5; // <PIN RGB_ORDER LENGTH>
PqStripWS281X<18, RGB, 16> pqStrip18; // <PIN RGB_ORDER LENGTH>
PqStripWS281X<19, RGB, 16> pqStrip19; // <PIN RGB_ORDER LENGTH>
*/

/*
SineWave sineWave1{ 0.025 };

SineWave sineWave2{ 0.025 };

SineWave sineWave3{ 0.025 };

SineWave sineWave4{ 0.025 };

SineWave sineWave5{ 0.025 };

SineWave sineWave6{ 0.025 };

SineWave sineWave7{ 0.025 };

SineWave sineWave8{ 0.025 };

Metronome metronome { 0.05};

Metronome metronome1 { 0.05};
*/
SineWave otherWave{1};
SineWave anotherWave{0.45};

SineWave sineWave{0.05};
TimeMap<16> timeMap{0.05}; // Period of 50ms and 16 samples (one sample per pixel)

unsigned long chrono;

unsigned long stepChrono;
unsigned long stepChronoAccum;
int stepChronoCount;

#include <PqOSC.h>
PqOSCSlip<1024> pqOSC(Serial, 115200);
PqOSCOut pqOSCOutKey(pqOSC, "/key", 50); // 50 ms minimum interval between messages
PqOSCIn pqOSCIn(pqOSC, "/test");

void begin()
{
   
}

void step()
{
    /*

    sineWave >> pqStrip;
    */

    sineWave >> timeMap; // TIMESLICE WILL SAMPLE TO FILL 16 SAMPLES OVER 50ms

    if (timeMap.triggered())    // if ( metronome )
    {                           // this will trigger once all sampling is done
        pqStrip.draw(timeMap); // draw the TimeSlice to the strip
        // sineWave.phase(otherWave); // sync the wave to the TimeSlice
        sineWave.phase(0);
        // Serial.print("timeMap "); Serial.println(micros() - chrono);
       // chrono = micros();
        // timeMap.reset();
    }

    // pqStrip.applyWave(sineWave);

    /*
        stepChronoAccum += (micros() - stepChrono);
        stepChrono = micros();
        stepChronoCount++;

        if ( stepChronoCount >= 10000 ) {
            float average = (float)stepChronoAccum / (float)stepChronoCount;
            Serial.print("average "); Serial.println(average);
            stepChronoAccum = 0;
            stepChronoCount = 0;
        }
    */
    /*
        sineWave >> pqStrip;
        if ( pqStrip.triggered() ) {
            pqWave.phase(0); // sync the wave to the strip
        }
            */
}