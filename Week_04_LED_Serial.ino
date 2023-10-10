

#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

#define BUFFTIME 2
#define BLINK_RATE_MS 100
#define ON 1
#define OFF 0


DigitalOut led(P0_13);
DigitalIn inp(P0_4);

int state, prevState, ledState = OFF ;
int btnTime = 0, m = 0 ;


void setup() {
  //Serial.begin(9600);
}

void loop() {
  
  state = inp ;
  m = millis() ;

  if (state != prevState && (m - btnTime > BUFFTIME) ) { // noise cancelling --> BUFFTIME set to 2 for more accuracy
    ledState = !ledState;
    btnTime = m;
  }
  
  led = !ledState ;
  prevState = state ;

  delay(BLINK_RATE_MS);
}
