#include <Stepper.h>

// steps per particular revolution of motor
#define motorSteps 200   

// initialize motor pins 8 and 9 on the Arduino board
#define motorPin1 8
#define motorPin2 9
#define ledPin 13

// initialize of the Stepper library:
Stepper myStepper(motorSteps, motorPin1,motorPin2); 

void setup() {
  // set the motor speed (RPMS):
  myStepper.setSpeed(2000);

  // Initialize the Serial port:
  Serial.begin(9600);

  // set up the LED pin:
  pinMode(ledPin, OUTPUT);
  // blink the LED:
  blink(3);
}

void loop() {
  // Step forward (steps). Sets the paddle wherever is needed.
  // May need touch sensors to position paddle at 'beginning position'.
  // Delay needs to be infinite.
  Serial.println("Forward");
  myStepper.step(300);
  delay(50000000000000000000000000000000000000000000);


}

// Blink the reset LED:
void blink(int howManyTimes) {
  int i;
  for (i=0; i< howManyTimes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}



