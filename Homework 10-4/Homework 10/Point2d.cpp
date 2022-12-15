#include <iostream>
#include <cmath>
#include "Point2d.hpp"
#include "Circle.hpp"

using namespace std;

Point2d::Point2d()
{
  x = 0;
  y = 0;
}

Point2d::Point2d(double xPosition, double yPosition)
{
  x = xPosition;
  y = yPosition;
}

istream& operator>>(istream& in, Point2d& object)
{
  double newX, newY;

  in >> newX >> newY;

  object = Point2d(newX, newY);

  return in;
}

ostream& operator<<(ostream& out, Point2d object)
{
  out << "(" << object.x << "," << object.y << ")" << endl;

  return out;
}

double pointDist(Point2d point1, Point2d point2)
{
  double distanceBetween = 0;

  distanceBetween = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));

  return distanceBetween;
}

double Point2d::getX() const
{
  return x;
}

double Point2d::getY() const
{
  return y;
}