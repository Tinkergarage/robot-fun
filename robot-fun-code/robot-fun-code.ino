#include "TinkerRobot.h"

#define trigPin 3
#define echoPin 5

enum statuses {
  none,
  stopped,
  forward,
  backward,
  turning
};

enum directions {
  right,
  left
};

int prevStatus = none;
int status = stopped;

int m1Speed = 0;
int m2Speed = 0;

unsigned long startTurningTime = 0;

TinkerRobotRed md;

void setup()
{
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  md.begin();
}

void loop()
{
  if(status=needToChangeStatus()){
    changeStatus(status);
  }

  Serial.print("Status: ");
  Serial.println(status);

  delay(12);
}

long getDistance()
{
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  return distance;  
}

bool isThereObstacle()
{
  long distance = getDistance();
  
  /*
  if (distance < 4) {  
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  */

  if(distance < 20)
    return true;
  else
    return false;
}

bool isWayFree()
{
  long distance = getDistance();

  if(distance > 50)
    return true;
  else
    return false;
}

int needToChangeStatus()
{
  int newStatus = status;
  
  switch (status) {
    case stopped:
      if(prevStatus == none){
        newStatus = forward;
      }
      break;
    case forward:
      if(isThereObstacle()){
        turn(right);
        newStatus = turning;
      }
      break;
    case backward:
      break;
    case turning:
      newStatus = checkWayFree();
      break;
  }

  if(newStatus != status)
    prevStatus = status;
  return newStatus;  
}

void changeStatus(int s)
{
  switch (s) {
    case stopped:
      needToStop();
      break;
    case forward:
      moveForward();
      break;
    case backward:
      break;
    case turning:
      break;
  }
}

void moveForward()
{
  for (int i = 200; i <= 300; i++)
  {
    m1Speed = m2Speed = i;
    md.setM1Speed(m1Speed);
    md.setM2Speed(m2Speed);
  }
}

void needToStop()
{
  if((prevStatus==forward || prevStatus==turning) && (m1Speed > 0 || m2Speed > 0) ){  
    for (int i = 400; i > 100; i--)
    {
      m1Speed += (m1Speed > 0 ? -1 : 1);
      m2Speed += (m2Speed > 0 ? -1 : 1);
      md.setM1Speed(m1Speed);
      md.setM2Speed(m2Speed);
    }  
    md.setM1Speed(m1Speed=0);
    md.setM2Speed(m2Speed=0);
  }
}

int direction = -1;
void turn(int d)
{
  needToStop();

  direction = d;

  m1Speed = -1 * ( m2Speed = 200 * (direction == right ? 1 : -1));
  md.setM1Speed(m1Speed);
  md.setM2Speed(m2Speed);

  startTurningTime = millis();
}

int checkWayFree()
{
  if( ((startTurningTime + 3000l) < millis() ) && direction == right)
    turn(left);
  else if( ((startTurningTime + 3000l) < millis()) && direction == left)
    return stopped;
 
  if ( isWayFree() ){
    direction = -1;
    return forward;
  }

  return turning;
}


