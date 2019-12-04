#include <Adafruit_MotorShield.h>
#define trigPin 8
#define echoPin 7
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// The DC motor connected to M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

// The DC motor connected to M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

void setup() {
  Serial.begin(19200);
  AFMS.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  leftMotor->setSpeed(200);
  rightMotor->setSpeed(200);
  Serial.println("Startup");
}


void loop() {
   
   long duration, distance; 
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
 delay(100);


  if (distance < 20)
 

 {   
  Serial.print("turn");
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);

}

 else {
  Serial.print("Moving forward...");
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD); 
  }  
}
