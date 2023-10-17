
#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;

/////// SETTINGS ///////
DigitalOut R_pullup(P1_0) ;
DigitalOut acc_pwr(P0_22) ;
I2C i2c(I2C_SDA1, I2C_SCL1);
uint8_t count = 0;


void setup(){

  Serial.begin(9600) ;
  R_pullup = 1 ;
  acc_pwr = 1 ;

}

void loop(){

  Serial.println("Scanning I2C devices") ;
  count = 0;
  char dt[3]; 

  for(int adr = 0 ; adr < 128 ; adr++ ){
      if(i2c.read((adr << 1), dt, 1) == 0){ // check ACKNOWLEDGE ACK
          Serial.print("found @ 0x");
          Serial.println(adr, HEX);
          count ++;
      }
      thread_sleep_for(10);
  }
  Serial.print("Total ") ;
  Serial.print(count) ;
  Serial.println(" devices were found.") ;
  thread_sleep_for(1000);
}
