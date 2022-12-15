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

bool SensorReading::validateTime() const
{
  if (getTime() >= 0 && getTime() < 86400)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validatePressure() const
{
  if (getPressure() >= 0.0)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validateWindDirection() const
{
  if (getWindDirection() >= 0.0 && getWindDirection() < 360.0)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validateWindSpeed() const
{
  if (getWindSpeed() >= 0.0)
  {
    return true;
  } else
  {
    return false;
  }
}

bool SensorReading::validate() const
{
  if (validateTime() && validatePressure() && validateWindDirection() && validateWindSpeed())
  {
    return true;
  } else
  {
    return false;
  }
}

int SensorReading::getTime() const
{
  return time;
}

double SensorReading::getPressure() const
{
  return pressure;
}

double SensorReading::getWindDirection() const
{
  return windDirection;
}

double SensorReading::getWindSpeed() const
{
  return windSpeed;
}

ostream& operator<<(ostream& out, SensorReading& object)
{
  out << object.time << " " << object.pressure << " " << object.windDirection << " " << object.windSpeed << endl;

  return out;
}
