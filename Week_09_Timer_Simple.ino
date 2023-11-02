

#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;



#define MS 10000

Timer tmr ;
DigitalOut led(P0_24) ;

void setup() {
  tmr.start() ;

}

void loop() {
  if(tmr.read_us() > MS){
    tmr.reset() ;
    led = !led ;
  }

}
