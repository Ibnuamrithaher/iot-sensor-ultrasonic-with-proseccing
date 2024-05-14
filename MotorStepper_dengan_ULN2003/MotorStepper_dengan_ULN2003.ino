#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

#include <Stepper.h>
#include <Wire.h>

const int stepsPerRevolution = 200;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0; // number of steps the motor has taken

// int paso [4][4] =
// {
//   {1, 1, 0, 0},
//   {0, 1, 1, 0},
//   {0, 0, 1, 1},
//   {1, 0, 0, 1}
// };

// int Paso [ 8 ][ 4 ] = 
// {  
//   {1, 0, 0, 0}, 
//   {1, 1, 0, 0}, 
//   {0, 1, 0, 0}, 
//   {0, 1, 1, 0}, 
//   {0, 0, 1, 0}, 
//   {0, 0, 1, 1}, 
//   {0, 0, 0, 1}, 
//   {1, 0, 0, 1} 
// };
void setup() {
  // pinMode(IN1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  // pinMode(IN3, OUTPUT);
  // pinMode(IN4, OUTPUT);
}

void loop() {
  // for (int i = 0; i < 4; i++)
  // {
  //   digitalWrite(IN1, paso[i][0]);
  //   digitalWrite(IN2, paso[i][1]);
  //   digitalWrite(IN3, paso[i][2]);
  //   digitalWrite(IN4, paso[i][3]);
  //   delay(10);
  // }

  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}
