#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;

DigitalOut led1(P0_24) ;
DigitalOut led2(P0_16) ;
InterruptIn btn(P1_11) ;

void flip(){
  led2 = !led2;
}


void setup() {
  btn.fall(&flip) ;
}

void loop() {
  led1 = !led1 ;
  thread_sleep_for(1000) ;
}
