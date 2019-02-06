#include <TimerHelpers.h>

// Timer 0

// output    OC0A   pin 12  (D6)

const byte pinOut = 6;
const byte pinOut2_4 = 3;
const byte led = 13;
const 
 
void setup4MHz() {
  pinMode (pinOut, OUTPUT); 
  TIMSK0 = 0;  // no interrupts
  Timer0::setMode (2, Timer0::PRESCALE_1, Timer0::TOGGLE_A_ON_COMPARE);
  OCR0A = 1;  // count to 2 (4MHz square wave)
  // OCR0A = 0;  // count to 2 (8MHz square wave)
}  // end of setup

void setup2_4MHz() {
  pinMode(pinOut2_4, OUTPUT);
  TCCR2A = 0x33;
  TCCR2B = 0x09;
  
// Actually, it is 2.2869 MHz  
//  OCR2A = 0x06;
//  OCR2B = 0x03;    // Duty cycle?

// 333.50 kHz
//  OCR2A = 0x2f;
//  OCR2B = 0x19;

// 1.77867 MHz
//  OCR2A = 0x08;
//  OCR2B = 0x06;

//  OCR2A = 0x08;
//  OCR2B = 0x07;

// 2.2869 MHz  
  OCR2A = 0x06;
  OCR2B = 0x03;    // Duty cycle?

}

void setupIO() {
  pinMode (pinOut2_4, OUTPUT);
}
  
void setup() {
  setup2_4MHz();
//  setup4MHz();
setupIO();
}

// the loop routine runs over and over again forever:
void blink() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//TCCR2  pinMode (pinOut2_4, INPUT);
  delay(1000);               // wait for a second
  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  pinMode (pinOut2_4, OUTPUT);

  delay(1000);               // wait for a second
}

void loop() {
  blink();
}
