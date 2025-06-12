

// https://sofapirate.github.io/Plaquette/

#include <Plaquette.h>
#include <FastLED.h>

// PqM5Atom

#define BUTTON_PIN 39
#define PIXEL_PIN 27

#define WIRE_SDA_PIN 26
#define WIRE_SCL_PIN 32

#define DAC_PIN 26
#define ADC_PIN 32

#define YELLOW_PIN 26
#define WHITE_PIN 32

// Button Btn = Button(39, true, 10);
// Button(uint8_t pin, uint8_t invert, uint32_t dbTime);

// PqFastLEDStrip
// FastLED.addLeds<WS2812, DATA_PIN, GRB>(&pixel, 1);
// FastLED.addLeds<WS2812, 27 , GRB>(&pixel, 1);

// Smooths over time window of 10 seconds.
// Smoother pqSmoother{10.0};

pq::DigitalIn atomButton{BUTTON_PIN, INPUT_PULLUP};

#include <PqOSC.h>
pq::OSCSSLIP<1024> pqOSC(Serial, 115200);
pq::OSCOut pqOSCOut(pqOSC, "/but", 50); // 50 ms minimum interval between messages
pq::OSCIn pqOSCIn(pqOSC, "/test");

#include <PqLEDStrip.h>
pq::LEDStripWS281X<PIXEL_PIN, RGB, 1> pqAtomPixel; // PIN RGB_ORDER LENGTH

pq::Wave pqWave{pq::Wave::Ramp, 2.0};

class Scaler : public Chainable
{
private:
  float _min = 0;
  float _range = 1;
  float _value;

public:
  Scaler(float min, float max) 
  {
    _min = min;
    _range = max-min;
  }

  float get() {
    return _value;
  }

  float put(float input) override {
    _value = input * _range + _min;
    return _value;
  }
};
Scaler scaler(0.5f,2.0f);

void begin()
{
}

void step()
{
  //pqWave.frequency(pqOSCIn);
  atomButton >> pqOSCOut;
  pqWave >> pqAtomPixel;

  // pqKey >> pqSmoother >> pqStrip;
  // pqKey >>  pqStrip;
  //
  // pqKey.smoothed() >> pqStrip;
  // pqWave >> pqStrip;
  // strip.setPixelRGB( );
}