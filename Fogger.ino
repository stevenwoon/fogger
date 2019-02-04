#include <TimerHelpers.h>

// Timer 0

// output    OC0A   pin 12  (D6)

const byte pinOut = 6;
 
void setup4MHz() {
  pinMode (pinOut, OUTPUT); 
  TIMSK0 = 0;  // no interrupts
  Timer0::setMode (2, Timer0::PRESCALE_1, Timer0::TOGGLE_A_ON_COMPARE);
  OCR0A = 1;  // count to 2 (4MHz square wave)
  // OCR0A = 0;  // count to 2 (8MHz square wave)
}  // end of setup

void setup2_4MHz() {
  pinMode(3, OUTPUT);
  TCCR2A = 0x33;
  TCCR2B = 0x09;
  OCR2A = 0x06;
  OCR2B = 0x03;
}


void setup() {
  setup2_4MHz();
}

void loop() {}
