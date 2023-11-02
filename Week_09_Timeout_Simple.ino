#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

DigitalOut led(P0_24);
DigitalOut led2(P0_6, 0); // here I set it up at 0 on start

Timeout tmo ;

void toggle(){
  led2 = !led2;
}
void setup() {
  Serial.begin(9600);
  tmo.attach(&toggle, 10.0);
}
void loop() {
  led = !led;
  thread_sleep_for(100);
}
