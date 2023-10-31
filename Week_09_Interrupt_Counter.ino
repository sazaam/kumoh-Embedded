#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;

class Counter{
  InterruptIn _int ;
  volatile uint16_t _ct ;
  volatile bool _ok ;

  void isr(){
    _ct ++ ;
    _ok = 1 ;
  }
  public:
    Counter(PinName pin):_int(pin){
      _ct = _ok = 0 ;
      _int.fall(callback(this, &Counter::isr)) ;
    }
    uint16_t read(){
      _ok = 0 ;
      return _ct ;
    }
    bool isUpdated(){
      return _ok ;
    }
};

Counter cnt(P1_11) ;


void setup() {
  Serial.begin(9600) ;
}

void loop() {
  if(cnt.isUpdated()){
    Serial.print("count = ") ;
    Serial.println(cnt.read()) ;
    thread_sleep_for(100) ;
  }
  
}
