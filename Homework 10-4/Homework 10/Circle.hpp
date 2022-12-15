#include "Point2d.hpp"
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

using namespace std;

class Circle
{
protected:
  Point2d circleCenter;
  double radius;
  string circleColor;

public:
  Point2d getCenter() const;
  double getRadius() const;
  string getColor() const;
  void setCenter(Point2d newCenter);
  void setRadius(double newRadius);
  void setColor(string newColor);
  bool contains(Point2d point) const;
  friend bool hasOverlap(Circle circle1, Circle circle2);
  friend istream& operator>>(istream& in, Circle& object);
  friend ostream& operator<<(ostream& out, Circle object);

  Circle();
  Circle(Point2d cCenter, double r, string cColor);
};

#endif
