#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;
using namespace rtos ; 

#define MS_PLUS 490
#define MS_MINUS 1000

DigitalOut led(LED1);
Mutex mutex ;
Thread t2, t3;
int cnt = 0;

void notify(const char* name, int ct){
  Serial.print(name) ;
  Serial.print(" : ") ;
  Serial.println(ct) ;
}

void thread_plus(const char* args){
  while(1){
    mutex.lock() ;
    led = !led ;
    notify((const char *) args, ++cnt) ;
    mutex.unlock() ;
    thread_sleep_for(MS_PLUS) ;
  }
}

void thread_minus(const char* args){

  while(1){
    mutex.lock() ;
    led = !led ;
    notify((const char *) args, --cnt) ;
    mutex.unlock() ;
    thread_sleep_for(MS_MINUS) ;
  }
}

void setup() {
  Serial.begin(115200) ;
  t2.start(callback(&thread_plus, (const char *) "Th 2")) ;
  t3.start(callback(&thread_minus, (const char *) "Th 2")) ;
}

void loop() {
  thread_minus((const char *) "Th 1") ;
}
