#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;




#define RATE 500

DigitalOut LED(P0_13);

float v;




// the setup function runs once when you press reset or power the board
void setup() {
  //
  srand(time(NULL)) ;
}

// the loop function runs over and over again forever
void loop() {
  
  v = (float) rand() / RAND_MAX ;

  LED = (v < .1f)? 1 : 0 ;
  thread_sleep_for(RATE);


  /*
  LED = 1;
  thread_sleep_for(RATE);
  LED = 0;
  thread_sleep_for(RATE);
  */
}




