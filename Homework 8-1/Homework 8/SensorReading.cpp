#include <iostream>
#include <fstream>
#include "SensorReading.hpp"

using namespace std;

SensorReading::SensorReading()
{
  time = 0;
  pressure = 0;
  windDirection = 0;
  windSpeed = 0;
}

SensorReading::SensorReading(int t, double pr, double wd, double ws)
{
  time = t;
  pressure = pr;
  windDirection = wd;
  windSpeed = ws;
}

void SensorReading::getTime(int& hours, int& minutes, int& seconds) const
{
  int copyOfTime = time;

  while (copyOfTime >= 3600)
  {
    copyOfTime -= 3600;
    hours++;
  }

  while (copyOfTime >= 60)
  {
    copyOfTime -= 60;
    minutes++;
  }

  while (copyOfTime > 0)
  {
    copyOfTime--;
    seconds++;
  }

  if (copyOfTime < 0)
  {
    seconds = copyOfTime;
  }
}

bool SensorReading::validateTime() const
{
  if (time >= 0 && time < 86400)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validatePressure() const
{
  if (pressure >= 0.0)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validateWindDirection() const
{
  if (windDirection >= 0.0 && windDirection < 360.0)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validateWindSpeed() const
{
  if (windSpeed >= 0.0)
  {
    return true;
  } else
  {
    return false;
  }
}

void SensorReading::print() const
{
  int seconds = 0, minutes = 0, hours = 0;

  getTime(hours, minutes, seconds);

  if (validateTime())
  {
    cout << "Time: " << hours << ":" << minutes << ":";
    if (seconds < 10)
    {
      cout << "0";
    }
      cout << seconds << endl;
  } else
  {
    cout << "Out of range" << endl;
  }

  if (validatePressure())
  {
    cout << "Pressure: " << pressure << " Pa" << endl;
  } else
  {
    cout << "Out of range" << endl;
  }

  if (validateWindDirection())
  {
    cout << "Direction: " << windDirection << " Degrees" << endl;
  } else
  {
    cout << "Out of range" << endl;
  }

  if (validateWindSpeed())
  {
    cout << "Speed: " << windSpeed << " m/s" << endl;
  } else
  {
    cout << "Out of range" << endl;
  }
}

void SensorReading::adjustWindDirection(double change)
{
  windDirection += change;

  while (windDirection >= 360)
  {
    windDirection -= 360;
  }
}

void SensorReading::adjustTime(int change)
{
  time += change;
}

void SensorReading::set(int t, double pr, double wd, double ws)
{
  time = t;
  pressure = pr;
  windDirection = wd;
  windSpeed = ws;
}
void SensorReading::printCSV(ostream& out) const
{
  out << time << "," << pressure << "," << windDirection << "," << windSpeed << endl;
}

SensorReading SensorReading::operator+(SensorReading object)
{
  SensorReading objectSum;
  int t;
  double pr, wD, wS;

  t = object.time + time;
  pr = object.pressure + pressure;
  wD = object.windDirection + windDirection;
  wS = object.windSpeed + windSpeed;

  objectSum = SensorReading(t, pr, wD, wS);

  return objectSum;
}

bool SensorReading::operator==(SensorReading object)
{
  double newWD, newWS;
  bool weGood = false;

  if (object.time == time && object.pressure == pressure)
{
  weGood = true;
}

  newWD = object.windDirection - windDirection;
  newWS = object.windSpeed - windSpeed;

  if (newWD < 0)
{
  newWD *= -1;
}

  if (newWS < 0)
{
  newWS *= -1;
}

  if (newWD <= 0.1 && newWS <= 0.01 && weGood)
{
  return true;
} else
{
  return false;
}
}

istream& operator>>(istream& in, SensorReading& object)
{
  int t;
  double pr, wD, wS;

  in >> t >> pr >> wD >> wS;

  object.set(t, pr, wD, wS);

  return in;
}

ostream& operator<<(ostream& out, SensorReading& object)
{
  out << object.time << "," << object.pressure << "," << object.windDirection << "," << object.windSpeed << endl;
  
  return out;
}
