
#include <mbed.h>
#include <USBSerial.h>
#include <platform/mbed_thread.h>

using namespace mbed;
//Virtual serial port over USB
USBSerial serial;


////// WARNING //////
// will switch COM{PORT} after uploading / installing...
// so need to switch to new port in order to use Serial stuff && Monitor 


int main(void) {
    serial.printf("Loop back program start!!\n");
    while (1) {
        if(serial.readable()){
            serial.putc(serial.getc());
        }
        thread_sleep_for(1);
    }
}

int main(void) {
    serial.printf("Loop back program start!!\n");
    while (1) {
        if(serial.readable()){
            serial.putc(serial.getc());
        }
        thread_sleep_for(100);
    }
}
