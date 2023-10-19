#include <mbed.h>
#include <platform/mbed_thread.h>

using namespace mbed;
AnalogIn but(P0_4);

void setup() {
  Serial.begin(9600);
}
void loop() {
  float voltage = but * 3.3f;
  uint16_t value = but.read_u16();
  Serial.print("Button Value = ");
  Serial.print(value);
  Serial.print(" Voltage = ");
  Serial.println(voltage);
  thread_sleep_for(10);
}
