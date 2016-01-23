/*
   Copyright 2016 Gianluca Sforna (giallu@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef TinkerRobot_h
#define TinkerRobot_h

#include "DualMC33926MotorShield.h"

#define MOTOR1 0
#define MOTOR2 1

class TinkerRobotRed
{
  public:
    TinkerRobotRed();
    TinkerRobotRed(unsigned char M1DIR, unsigned char M1PWM, unsigned char M1FB,
                   unsigned char M2DIR, unsigned char M2PWM, unsigned char M2FB,
                   unsigned char nD2, unsigned char nSF); 
    
    void begin(); // Initialize TIMER 1, set the PWM to 20kHZ. 
    void move(int motor, int speed );
    void stop();

  private:
    DualMC33926MotorShield _robot; 
};


class TinkerRobotBlue
{
  public:
    TinkerRobotBlue();
    void begin(); // initialize pins
    void move(int motor, int speed); // speed between -255 and 255
    void stop();

  private:
    int _STBY = 10;
    int _PWMA = 5;
    int _AIN1 = 8;
    int _AIN2 = 7;
    int _PWMB = 6;
    int _BIN1 = 12;
    int _BIN2 = 13;
};



#endif
