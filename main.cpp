#include "mbed.h"
#include "ThisThread.h"
#include "USBSerial.h"
 
// Virtual serial port over USB
USBSerial microUSB;

DigitalOut rLED(LED1);
DigitalOut gLED(LED2);
DigitalOut bLED(LED3);


// main() runs in its own thread in the OS
// (note the calls to ThisThread::sleep_for below for delays)
int main()
{
    rLED = LED_ON;
    gLED = LED_ON;
    bLED = LED_OFF;
 
    rLED = LED_OFF;

    while(1) {
        microUSB.printf("micro USB serial port\r\n");
        printf("daplink serial port\r\n");
        bLED =  !bLED;
        ThisThread::sleep_for(1000);
    }
}
