#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

class Debounce{
  InterruptIn _int ;
  Timeout _tmo ;
  int _intval ;
  int _state, _ready ;

  void btnISR(){
    if(_ready){
      _ready = 0;
      _tmo.attach(callback(this, &Debounce::decide), _intval) ;
    }
  }
  void decide(){
    _state = 0 ;
    _ready = 1 ;
    _tmo.detach() ;
  }

  public:
    Debounce(PinName pin, int intv = 100000) : _int(pin) {
      _int.fall(callback(this, &Debounce::btnISR)) ;
      _state = 1 ;
      _ready = 1 ;
      _intval = intv ;
    }
    int read(){
      int state = _state ;
      _state = 1 ;
      return state ;
    }
    operator int(){
      return read() ;
    }
};

Debounce dbc(P1_11, 100000) ;
int cnt;


void setup() {
  Serial.begin(9600);
  cnt = 0;
}
void loop() {
  if(!dbc){
    cnt++ ;
    Serial.print("Count = ") ;
    Serial.println(cnt) ;
  }
  Serial.println("TEST") ;
  thread_sleep_for(1000);
}
