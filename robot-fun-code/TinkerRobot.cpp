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

void TinkerRobotRed::move(int motor, int speed)
{
  if (motor == MOTOR1) {
    _robot.setM1Speed(map(speed,-255, 255, -400, 400));
  } else {
    _robot.setM2Speed(map(speed,-255, 255, -400, 400));
  }
}

void TinkerRobotRed::stop()
{
  _robot.setSpeeds(0, 0);
}




TinkerRobotBlue::TinkerRobotBlue()
{}

void TinkerRobotBlue::begin()
{
  pinMode(_STBY, OUTPUT);

  pinMode(_PWMA, OUTPUT);
  pinMode(_AIN1, OUTPUT);
  pinMode(_AIN2, OUTPUT);

  pinMode(_PWMB, OUTPUT);
  pinMode(_BIN1, OUTPUT);
  pinMode(_BIN2, OUTPUT);
}

void TinkerRobotBlue::move(int motor, int speed)
{
  digitalWrite(_STBY, HIGH);

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (speed < 0){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if (motor == 1){
    digitalWrite(_AIN1, inPin1);
    digitalWrite(_AIN2, inPin2);
    analogWrite(_PWMA, abs(speed));
  } else {
    digitalWrite(_BIN1, inPin1);
    digitalWrite(_BIN2, inPin2);
    analogWrite(_PWMB, abs(speed));
  }
}

void TinkerRobotBlue::stop(){ 
  digitalWrite(_STBY, LOW); 
}

