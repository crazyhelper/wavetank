#include <Stepper.h>

// steps per particular revolution of motor
#define motorSteps 200

// initializes pins 8 and 9, the motor pins on the Arduino board
#define motorPin1 8
#define motorPin2 9
#define ledPin 13

// initialize of the Stepper library:
Stepper myStepper(motorSteps, motorPin1,motorPin2);

// initializes pins 11, 12, 13 which determine which modes to loop
// ABC = 001 = Mode 1 = Start Position
// ABC = 010 = Mode 2 = Single Wave Pulse 
// ABC = 011 = Mode 2 = Steady Wave Form
#define modebitA 11
#define modebitB 12
#define modebitC 13

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

void setup() {
 
   // Initialize the Serial port:
   Serial.begin(9600);
 
   // set up the LED pin:
   pinMode(ledPin, OUTPUT);

   // set up mode bits pins
   pinMode(modebitA, INPUT)
   pinMode(modebitB, INPUT)
   pinMode(modebitC, INPUT)
   
   // blink the LED:
   blink(3);
}

void loop() {
   A = digitalRead(modebitA); 
   B =  digitalRead(modebitB);
   C =  digitalRead(modebitC); 

   if (A == LOW && B == LOW && C == LOW)
       delay(200)
   else if (A == LOW && B == LOW && C == HIGH)
       loopmode1()
   else if (A == LOW && B == HIGH && C == LOW)
      loopmode2()
   else if (A == LOW && B == HIGH && C == HIGH)
      loopmode3()
}

void loopmode1() {
   
    // Set the motor speed for resetting paddle to start position
    myStepper.setSpeed(2000);
    
    // Step forward (steps). Sets the paddle wherever is needed.
    // May need touch sensors to position paddle at 'beginning position'.
    // Delay needs to be infinite.
    Serial.println("Forward");
    myStepper.step(300);
    
    // Check if we'ere changing Modes
    A = digitalRead(modebitA); 
    B = digitalRead(modebitB);
    C = digitalRead(modebitC); 
    
    if (A == LOW && B == LOW && C == LOW)
        exit()
 
}

void loopmode2() {
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

    // Check if we'ere changing Modes
    A = digitalRead(modebitA); 
    B = digitalRead(modebitB);
    C = digitalRead(modebitC); 
    
    if (A == LOW && B == LOW && C == LOW)
        exit()

}

void loopmode3() {
    // set the motor speed (RPMS):
    myStepper.setSpeed(1000);

    // Step forward (# of micro-steps)
    Serial.println("Forward");
    myStepper.step(4000);
    delay(50);
 
    // Step backward (# of micro-steps)
    Serial.println("Backward");
    myStepper.step(-4000);
    delay(500);

    // Check if we'ere changing Modes
    A = digitalRead(modebitA); 
    B = digitalRead(modebitB);
    C = digitalRead(modebitC); 
    
    if (A == LOW && B == LOW && C == LOW)
        exit()
}
