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

#include "TinkerRobot.h"

TinkerRobotRed::TinkerRobotRed()
{
  _robot = DualMC33926MotorShield();
}



void TinkerRobotRed::begin()
{
  _robot.init();
}


void TinkerRobotRed::setM1Speed(int speed)
{
  _robot.setM1Speed(speed);
}

void TinkerRobotRed::setM2Speed(int speed)
{
  _robot.setM2Speed(speed);
}

