#include <platform/mbed_thread.h>
#include <math.h>

#define DATA_N 300
#define FS 8000.0f
#define PI 3.141592
#define ORDER 6

float data[DATA_N];
float bm[ORDER + 1] = {0.00105165, 0.00630988, 0.0157747 , 0.02103294, 0.0157747 ,
0.00630988, 0.00105165};
float am[ORDER] = {-2.97852993, 4.136081 , -3.25976428, 1.51727884,
-0.39111723, 0.04335699};
float un[ORDER] = {0};




float fIirDirectIITrans(float input)
{
    int m;
    float yn;

    yn = un[0] + bm[0] * input;

    for (m = 1; m <= ORDER; m++) /* multiply and accumulate */
        un[m - 1] = bm[m] * input - am[m - 1] * yn + un[m];


    return yn;
}



float fIirDirectII(float input)
{
    int m;
    float yn, utmp;
    utmp = input;
    
    for (m = 0; m < ORDER; m++) 
        utmp = utmp - am[m] * un[m];
    
    yn = bm[0] * utmp;
    
    for (m = 0; m < ORDER; m++) 
        yn = yn + bm[m + 1] * un[m];
    
    for (m = ORDER - 1; m > 0; m--) 
        un[m] = un[m - 1];
    
    un[0] = utmp;
    
    return yn;
}

void fCosWave(float freq, float phase, float fs, float gain, float bias, float* data) {
    int i;
    float omega = freq / fs;
    for (i = 0; i < DATA_N; i++) {
        data[i] = cos(2 * PI * omega * i + phase);
        data[i] = data[i] * gain + bias;
    }
}




void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Program Start!!!");
    fCosWave(1000, 0, FS, 100, 0, data);
}
void loop() {
    // put your main code here, to run repeatedly:
    int i = 0;
    while (1) {
        if (Serial.available() > 0) {
            Serial.read();
            break;
        }
    }
    for (i=0; i<ORDER; i++) un[i] = 0;
    for (i = 0; i < DATA_N; i++) {
        Serial.print(data[i]);
        Serial.print(",");
        //Serial.println((data[i]));
        
        //Serial.println(fIirDirectII(data[i]));
        Serial.println(fIirDirectIITrans(data[i]));
        
        thread_sleep_for(10);
    }
}









