#include <iostream>
#include <cmath>
#include "Circle.hpp"
#include "Point2d.hpp"

using namespace std;

Circle::Circle()
{
  circleCenter = Point2d(0, 0);
  radius = 0;
  circleColor = "";
}

Circle::Circle(Point2d cCenter, double r, string cColor)
{
  circleCenter = cCenter;
  radius = r;
  circleColor = cColor;
}

Point2d Circle::getCenter() const
{
  return circleCenter;
}

double Circle::getRadius() const
{
  return radius;
}

string Circle::getColor() const
{
  return circleColor;
}

void Circle::setCenter(Point2d newCenter)
{
  circleCenter = newCenter;
}

void Circle::setRadius(double newRadius)
{
  radius = newRadius;
}

void Circle::setColor(string newColor)
{
  circleColor = newColor;
}

bool Circle::contains(Point2d point) const
{
  double withInCircle = pointDist(point, circleCenter);

  return withInCircle <= radius;
}

bool hasOverlap(Circle circle1, Circle circle2)
{
  double circleOverlap, radiiSum;
  Point2d thisCenter, thisCenter1;

  thisCenter = circle1.circleCenter;
  thisCenter1 = circle2.circleCenter;

  circleOverlap = pointDist(thisCenter, thisCenter1);

  radiiSum = circle1.radius + circle2.radius;

  if (radiiSum > circleOverlap)
  {
    return true;
  } else
  {
    return false;
  }
}

istream& operator>>(istream& in, Circle& object)
{
  double centerX, centerY, radius;
  string color;

  in >> centerX >> centerY >> radius >> color;

  object = Circle(Point2d(centerX, centerY), radius, color);

  return in;
}

ostream& operator<<(ostream& out, Circle object)
{
  Point2d currentCenter = object.circleCenter;

  out << "[" << object.circleColor << " c=(" << currentCenter.getX() << ", " << currentCenter.getY() << ") r=" << object.radius << "]" << endl;

  return out;
}
