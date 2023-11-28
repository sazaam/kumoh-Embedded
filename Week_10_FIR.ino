#include <platform/mbed_thread.h>
#include <math.h>

#define MAX 10


#define F 3

float data[MAX] = {1,0,0,0,0} ;
float xn[F];

float runAverage(float inp, int n, int coef){
  int k;
  float sum, yn;

  xn[0] = inp ;
  
  yn = (float)( add(n, coef) / n) ;

  write(n) ;
  
  return yn ;
}


float bk[3] = {1, 2, 1};




float add(int n, int coef){
  int k = 0, l = n;
  while(--n >= 0){
      k += (coef ? bk[n] : 1) * xn[n] ;
  }
  return k ;
}

void write(int n){
  while(--n){
      xn[n] = xn[n - 1] ;
  }
}

void setup() {
  Serial.begin(115200) ;
  Serial.println("Start !") ;
}

void loop() {
  int i = 0 ;


  while(true){

    if(Serial.available() > 0){
      Serial.read() ;
      break;
    }
  }

  int n = F ;

  for(i = 0 ; i < MAX ; i++ ){
    Serial.print(data[i]) ;
    Serial.print(", ") ;
    
    Serial.println(runAverage(data[i], n, 1)) ;
    thread_sleep_for(10) ;
  }

}
