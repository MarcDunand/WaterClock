#ifndef CART_H
#define CART_H
#include <AccelStepper.h>
const int STEPS_PER_REV = 200;

class Cart{
  private:
    AccelStepper left;
    AccelStepper right;
    long speed;
    long accel;
    unsigned int microsteps;
    unsigned int wheelRadius;
    unsigned int axleLength;
    float mmToSteps;
  public:
    /*
     *  Initializes Cart 
     *
     *  param stepPin1: step pin of the left motor
     *  param dirPin1: direction pin of the left motor
     *  param stepPin2: step pin of the right motor
     *  param dirPin2: direction pin of the right motor
     *  param _speed: the max speed you want the cart to go in steps per second
     *  param _accel: the acceleration you want the cart to have in steps per second per second
     *  param _microsteps: the microstep stepping mode you are using (1,2,4,8,16)
     *  param _wheelRadius: radius of the wheels in mm
     *  param _axleLength: distance between the center of one wheel to the center of another
     */
    Cart(int stepPin1, int dirPin1, int stepPin2, int dirPin2, long _speed, long _accel, unsigned int _microsteps, unsigned int _wheelRadius, unsigned int _axleLength);
    /*
     * Sets the motor speed and acceleration according to what you defined in Cart
     */
    void setupMotors();
    /*
     * Reset the motor position
     */
    void resetMotors();
    /*
     *  Moves the cart in a straight line 
     *  
     *  param steps: the number of steps you want to move either forward (positive) or (backwards) 
     */
    void move(long steps);
    /*
     *  Rotates the cart in place
     * 
     *  param degrees: the number of degrees you want the robot to turn (negative: CCW, positive: CW)
     *  param direction: the direction you want the robot to turn (-1:CCW, 1: CW) 
     */
    void rotate(int degrees);
    /*
     *  Moves the cart if the cart should be move (YOU NEED TO CALL THIS FUNCTION FOR THE CART TO RUN)
     */
    void run();
    /*
     * Returns if the cart has finished moving or not
     */
    bool isDone();
};
#endif