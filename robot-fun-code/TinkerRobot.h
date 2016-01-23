#ifndef TinkerRobot_h
#define TinkerRobot_h

#include "DualMC33926MotorShield.h"

class TinkerRobotRed
{
  public:
    TinkerRobotRed();
    TinkerRobotRed(unsigned char M1DIR, unsigned char M1PWM, unsigned char M1FB,
                   unsigned char M2DIR, unsigned char M2PWM, unsigned char M2FB,
                   unsigned char nD2, unsigned char nSF); 
    
    void begin(); // Initialize TIMER 1, set the PWM to 20kHZ. 
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.


  private:
    DualMC33926MotorShield _robot; 
};


#endif
