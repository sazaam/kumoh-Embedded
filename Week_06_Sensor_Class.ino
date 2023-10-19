
#include <mbed.h>
#include <platform/mbed_thread.h>
#include <Arduino_HTS221.h>

using namespace mbed;


class Sensor{
  Ticker _tick;
  int _state;

  void sense(){
    _state = true ;
  }

  public:
    Sensor(){
      _state = false;
    }
    void begin(float s){
      _tick.attach(callback(this, &Sensor::sense), s) ;
    }
    int test(){
      return HTS.begin();
    }
    int getState(){
      return _state ;
    }
    float temperature(){
      return HTS.readTemperature() ;
    }
    float humidity(){
      return HTS.readHumidity() ;
    }
    void setState(int val){
      _state = val ;
    }

};

Sensor sensor;
// Sensor sensor(); // this throws compiler Error => when no arguments in CTOR, loose the brackets ^^

void setup() {

  Serial.begin(115200);
  while(!Serial);

  int available = sensor.test() ; 
  Serial.println(available ? "Sensor Test OK" : "Sensor initializing Failed...");
  if(!available) while(1);

  sensor.begin(0.5) ;
}

void loop() {
  if(!sensor.getState()) return ;
  Serial.print("temperature : ");
  Serial.print(sensor.temperature());
  Serial.print(", ");
  Serial.print("humidity : ");
  Serial.println(sensor.humidity());
  
  
  sensor.setState(0);

}



