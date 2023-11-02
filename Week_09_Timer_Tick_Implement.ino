#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

#define MS 1000000

DigitalOut led(P0_24);
DigitalOut led2(P0_6);

Ticker tic;
Timer tmr;

void toggle(){
  led2 = !led2;
}
void setup() {
  Serial.begin(9600);
  tmr.start();
  tic.attach(&toggle, 1);
}
void loop() {
  if(tmr.read_us() > MS){
    tmr.reset();
    led = !led;
    for(int i = 0; i < 4000; i++)
      Serial.println("PRINT 15bytes!");
  }
}


/* LED BLUE & RED NO SYNC EXAMPLE --> No TIMER IMPLEMENTATION */


/*

#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

DigitalOut led(P0_24);
DigitalOut led2(P0_6);
Ticker tic;

void toggle(){
  led2 = !led2;
}
void setup() {
  Serial.begin(9600);
  tic.attach(&toggle, 1);
}
void loop() {
  thread_sleep_for(1000);
  led = !led;
  for(int i = 0; i < 4000; i++)
    Serial.println("PRINT 15bytes!");
}

*/




