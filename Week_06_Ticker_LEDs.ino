
#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

/*
Ticker tick;
DigitalOut rd(P0_24);
DigitalOut gr(P0_16);

void toggleRed(){
  
  rd = !rd;

}


void setup() {

  tick.attach(&toggleRed, 0.1) ;

}

void loop() {

  gr = !gr ;

  delay(1000) ;

}
*/

class Blinker{
  DigitalOut _led;
  Ticker _tick;

  void blink(){
    _led = !_led ;
  }

  public:
    Blinker(PinName pin):_led(pin){
      _led = 0 ;
    }
    void begin(float s){
      _tick.attach(callback(this, &Blinker::blink), s) ;
    }
    void kill(){
      _tick.detach() ;
      _led = 0;
    }

};

Blinker rd(P0_24);
Blinker gr(P0_16);
Blinker bl(P0_6);

void setup() {
  rd.begin(1.0) ;
  gr.begin(0.333) ;
  bl.begin(0.666) ;
}

void loop() {
  // nothing to do here...
}



