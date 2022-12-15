#ifndef SENSORREADING_HPP
#define SENSORREADING_HPP

using namespace std;

class SensorReading
{
public:
  int time;
  double pressure, windDirection, windSpeed;
  void getTime(int& hours, int& minutes, int& seconds) const;
  bool validateTime() const;
  bool validatePressure() const;
  bool validateWindDirection() const;
  bool validateWindSpeed() const;
  void print() const;
  void adjustWindDirection(double change);
  void adjustTime(int change);
  void set(int t, double pr, double wd, double ws);
  void printCSV(ostream& out) const;

  SensorReading();
  SensorReading(int t, double pr, double wd, double ws);
};

#endif
