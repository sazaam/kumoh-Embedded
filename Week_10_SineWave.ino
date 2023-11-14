
#include <mbed.h>
#include <platform/mbed_thread.h>
#include <math.h>


#define _USE_MATH_DEFINES
/*
const double E = std::exp(1.0);
*/

using namespace mbed;


void test(float t){
  
  float A1 = 1.7, A2 = 1.9 ;
  float A3 = 1.532 ;
  
  float x1 = A1 * cos(M_PI*2*10 * t + (70*M_PI/180)) ;
  float x2 = A2 * cos(M_PI*2*10 * t + (200*M_PI/180)) ;
  float x1_pl_x2 = x1+x2 ;

  
  float x3 = A3 * cos(M_PI*2*10 * t + (141.79*M_PI/180)) ;
  Serial.println(t) ;
  Serial.print("x1 + x2 (Addition) : ") ;
  Serial.println(x1_pl_x2) ;
  Serial.print("x3 : ") ;
  Serial.println(x3) ;
}

void setup() {
  Serial.begin(9600);
}

int cnt = 0 ;

void loop() {
  
  cnt++ ;
  test((float) cnt);

  cnt = cnt % 100 ;
  thread_sleep_for(1000) ;
}

