#include <Stepper.h>

// steps per particular revolution of motor
#define motorSteps 200   

// initializes pins 8 and 9, the motor pins on the Arduino board
#define motorPin1 8
#define motorPin2 9
#define ledPin 13

// initialize of the Stepper library:
Stepper myStepper(motorSteps, motorPin1,motorPin2); 

void setup() {

  // Initialize the Serial port:
  Serial.begin(9600);

  // set up the LED pin:
  pinMode(ledPin, OUTPUT);
  // blink the LED:
  blink(3);
}

void loop() {
  // Set the motor speed for single pulse.
  // This will be much higher than the return below (RPMS):
  myStepper.setSpeed(1800);

  // Make three buttons for single pulse waves, one for 
  // large waves (possibly 1200), one for meidum
  // waves (possibly 750), and one for small waves (possibly 500)
  // Step forward (steps):
  Serial.println("Forward");
  myStepper.step(4500);
  delay(50);

  // Set the motor speed for wave paddle return 
  // to starting position (RPMS):
  myStepper.setSpeed(50);

  // Step backward (steps):
  Serial.println("Backward");
  myStepper.step(-4500);
  delay(500); 

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

