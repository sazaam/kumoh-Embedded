

#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

#define BLINK_RATE_MS 100

DigitalOut led(P0_13);

DigitalIn inp(P0_4);

float v;

void setup() {
  srand(time(NULL)) ;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*led = 1;
  */

  /*
  thread_sleep_for(BLINK_RATE_MS);
  led = 0;
  thread_sleep_for(BLINK_RATE_MS);
  */



  /*
  repeatedly:
    if(!inp){
      led = !led;
    }

  */


  /*
  v = (float)rand() / RAND_MAX ;
  led = (v < 0.1f) ? 1 : 0 ;
  thread_sleep_for(BLINK_RATE_MS);
  */

  if(!inp){
    led = 1 ;
    Serial.println(rand() % 6 + 1);
    thread_sleep_for(BLINK_RATE_MS);
    led = 0;
  }


}
