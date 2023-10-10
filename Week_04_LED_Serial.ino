

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



/*

#define ledOn LOW
#define ledOff HIGH

const int ledPin =  LED_BUILTIN;
const int buttonPin = D0;  // Wemos D1 GPIO 16

int ledState = ledOff;        // the current state of the LED
int previousState = LOW;      // the previous buttonState from the button pin

unsigned long buttonTime = 0;                  // The last time the output pin was toggled
unsigned long debounceTime = 400;              // debounceTime time (I am using a noisy button)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState != previousState && millis() - buttonTime > debounceTime) {
    ledState = !ledState;
    buttonTime = millis();
  }

if (ledState == ledOn) {
    digitalWrite(ledPin, (millis() >> 9) & 3);  //Blink
  } else
    digitalWrite(ledPin, ledOff);

previousState = buttonState;
}

*/





