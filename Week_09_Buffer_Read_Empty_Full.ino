#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;
using namespace rtos ; 

#define BUF_SIZE 10
#define MS_SM 100
#define MS_MID 400
#define MS_LG 500

DigitalOut led(LED1);

Thread th, ser_th;
CircularBuffer <char, BUF_SIZE> buff;
char c;


void pusher(){
  char c = '0' ;
  while(1){
    if(!buff.full()){
      buff.push(c) ;
      if(c < '9') c++ ;
      else c = '0' ;
    }
    thread_sleep_for(MS_LG) ;
  }
}

void dataArrived(){
    char c = 0 ;
  while(1){
    if(Serial.available()> 0){
      Serial.readBytes(&c, 1) ;
      if(!buff.full() && c != '\n') buff.push(c) ;
    }
    thread_sleep_for(MS_SM) ;
  }
}

void setup() {
  Serial.begin(9600) ;
  th.start(pusher) ;
  ser_th.start(dataArrived) ;
}

void loop() {
  if(!buff.empty()){
    buff.pop(c) ;
    Serial.print("Size : ") ;
    Serial.print(buff.size()) ;
    Serial.print(", Data : ") ;
    Serial.println(c) ;
  }
  led = buff.full() ? 1 : 0 ;
  thread_sleep_for(MS_MID) ;

}
