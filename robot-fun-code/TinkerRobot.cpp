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

