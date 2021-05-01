#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// bind the motor ports
Adafruit_DCMotor *headMotor = AFMS.getMotor(1);
Adafruit_DCMotor *tailMotor = AFMS.getMotor(2);
Adafruit_DCMotor *mouthMotor = AFMS.getMotor(3);

void setup() {
  Serial.begin(9600);           // for debugging
  Serial.println("Initializing Magic Fish!");
  AFMS.begin();
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
    Serial.println("Head Motors: Activate!");
  headMotor->setSpeed(255);
  headMotor->run(FORWARD);
  delay(1000); // turn on motor
  headMotor->run(BACKWARD);
  delay(1000); // turn on motor
  headMotor->run(RELEASE);

      Serial.println("Tail Motors: Activate!");
  tailMotor->setSpeed(255);
  tailMotor->run(FORWARD);
  delay(1000); // turn on motor
  tailMotor->run(BACKWARD);
  delay(1000); // turn on motor
 tailMotor->run(RELEASE);

      Serial.println("Mouth Motors: Activate!");
  mouthMotor->setSpeed(255);
  mouthMotor->run(FORWARD);
  delay(1000); // turn on motor
  mouthMotor->run(BACKWARD);
  delay(1000); // turn on motor
  mouthMotor->run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("open");

  mouthMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    mouthMotor->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    mouthMotor->setSpeed(i);  
    delay(10);
  }
  
  Serial.print("close");

  mouthMotor->run(BACKWARD);
  for (i=0; i<255; i++) {
    mouthMotor->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    mouthMotor->setSpeed(i);  
    delay(10);
  }
}
