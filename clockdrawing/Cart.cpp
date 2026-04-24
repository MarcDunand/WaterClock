#include "Cart.h"

Cart::Cart(int stepPin1, int dirPin1, int stepPin2, int dirPin2, long _speed, long _accel, unsigned int _microsteps, unsigned int _wheelRadius, unsigned int _axleLength){
  left = AccelStepper(AccelStepper::DRIVER, stepPin1, dirPin1);
  right = AccelStepper(AccelStepper::DRIVER, stepPin2, dirPin2);
  speed = _speed;
  accel = _accel;
  microsteps = _microsteps;
  wheelRadius = _wheelRadius;
  axleLength = _axleLength;
  mmToSteps = (STEPS_PER_REV * microsteps) / (2*PI*wheelRadius);

}
void Cart::resetMotors(){
  left.setCurrentPosition(0);
  right.setCurrentPosition(0);
}
void Cart::setupMotors(){
  left.setAcceleration(accel);
  right.setAcceleration(accel);
  left.setMaxSpeed(speed);
  right.setMaxSpeed(speed);
  this->resetMotors();
}

void Cart::move(long steps){
  left.move(steps);
  right.move(steps);
}

void Cart::rotate(int degrees){
  //amount of millimeters on the circumference needs to turn degrees amount of degrees
  double totalMM = 2*PI*axleLength*(degrees/360.0);
  Serial.println(totalMM);
  //circumference of wheel/ steps per rotation * totalMMs gives total number of steps
  long totalSteps = mmToSteps*totalMM;
  Serial.println(totalSteps);
  left.move(totalSteps/2.0);
  right.move(-1*totalSteps/2.0);
}

void Cart::run(){
  left.run();
  right.run();
}

bool Cart::isDone(){
  return left.distanceToGo() == 0 && right.distanceToGo() == 0;
}