#include <iostream>
#ifndef POINT2D_HPP
#define POINT2D_HPP

using namespace std;

class Point2d
{
private:
  double x, y;

public:
  friend istream& operator>>(istream& in, Point2d& object);
  friend ostream& operator<<(ostream& out, Point2d object);
  friend double pointDist(Point2d point1, Point2d point2);
  double getX() const;
  double getY() const;

  Point2d();
  Point2d(double xPosition, double yPosition);
};

#endif