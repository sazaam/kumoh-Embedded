#include <Arduino_HTS221.h>
#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed ;
using namespace rtos ; 

#define BUF_SIZE 10
#define MS_SM 100
#define MS_MID 400
#define MS_LG 1000

DigitalOut led(LED1);

Thread th_temp;
Mutex mutex ;

struct TemperatureData{
  float temperatureCelsius ;
  float humidity;
  uint32_t timestampMS ;
};

CircularBuffer<TemperatureData, BUF_SIZE> buff;
TemperatureData tempdata ;
TemperatureData data ;


void dataArrived(){
    char c = 0 ;
  while(1){
    data.temperatureCelsius = HTS.readTemperature() ;
    data.humidity = HTS.readHumidity() ;
    data.timestampMS = millis() ;

    if(!buff.full()){
      buff.push(data) ;
    }

    led = buff.full() ? 1 : 0 ;
    thread_sleep_for(MS_SM) ;
  }
}

void setup() {
  Serial.begin(9600) ;

  if(!HTS.begin()){
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
  th_temp.start(&dataArrived) ;
}

void loop() {
  while(!buff.empty()){
    buff.pop(tempdata) ;
    Serial.print("temperature : ") ;
    Serial.print(tempdata.temperatureCelsius) ;
    Serial.print(", humidity : ") ;
    Serial.print(tempdata.humidity) ;
    Serial.print(", ms : ") ;
    Serial.println(tempdata.timestampMS) ;
  }
  
  thread_sleep_for(MS_LG) ;

}
