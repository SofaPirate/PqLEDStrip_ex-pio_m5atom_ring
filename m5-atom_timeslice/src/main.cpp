
THIS EXAMPLE IS PSEUDOCODE AND DOES NOT COMPILE


#include <Plaquette.h>
#include <FastLED.h>

#include <PqLEDStrip.h>
PqStripWS281X<4, RGB, 16> pqStrip; // PIN RGB_ORDER LENGTH

TimeSlice timeSlive{0.05, 16}; // Period of 50ms and 16 samples (one sample per pixel)

SineWave sineWave{2.0};


void begin()
{
}

void step()
{

   sineWave.period(0.05); // 50ms period
    
    sineWave >> timeSlice; // TIMESLICE WILL SAMPLE TO FILL 16 SAMPLES OVER 50ms

    if ( timeSlice.full() ) { // this will trigger once all sampling is done
        pqStrip.apply(timeSlice); // draw the TimeSlice to the strip
        pqWave.phase(0); // sync the wave to the TimeSlice
    }

    if ( pqStrip.filled() ) {
        pqWave.phase(0); // sync the wave to the strip
    }
}