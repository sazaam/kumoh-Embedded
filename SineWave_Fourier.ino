
#include <platform/mbed_thread.h>
#include <math.h>

#define _USE_MATH_DEFINES

#define DATA_N 300
#define FS 300.0f

float data[3][DATA_N];



void fSineWave(float freq, float phase, float fs, float gain, float bias, float* data) {
  int i;
  float omega = freq / fs;
  data[0] = 1;
  for (i = 1; i < DATA_N; i++) {
    data[i] = sin(2 * PI * omega*i + phase);
    data[i] = data[i] * gain + bias;
  }
}





void setup() {
  Serial.begin(115200);
  Serial.println("Program Start!!!");
  fSineWave(25, 0, FS, 2.0/PI, 0, data[0]);
  fSineWave(75, 0, FS, 2.0/(3.0*PI), 0, data[1]);
}

void loop() {

  int i = 0;
  while(1){
    if(Serial.available() > 0){
      Serial.read();
      break;
    }
  }

  for (i=0; i<DATA_N; i++){
    Serial.println(0.5+data[0][i]+data[1][i]);
    thread_sleep_for(10); 
  }
}
