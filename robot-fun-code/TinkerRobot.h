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
