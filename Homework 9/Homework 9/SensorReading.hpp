#include <iostream>
#ifndef SENSORREADING_HPP
#define SENSORREADING_HPP

using namespace std;

class SensorReading
{
private:
  int time;
  double pressure, windDirection, windSpeed;

public:
  int getTime() const;
  double getPressure() const;
  double getWindDirection() const;
  double getWindSpeed() const;
  bool validateTime() const;
  bool validatePressure() const;
  bool validateWindDirection() const;
  bool validateWindSpeed() const;
  bool validate() const;
  friend ostream& operator<<(ostream& out, SensorReading& object);

  SensorReading();
  SensorReading(int t, double pr, double wd, double ws);
};

#endif
