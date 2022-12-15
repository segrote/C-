#include <iostream>
#include "Point2d.hpp"
#include "Circle.hpp"
#include "fstream"
#include "cstdlib"

using namespace std;

const int arraySize = 1000;

void howManyPoints(Circle circleArray[], int closestCircleIndex, int& points, int arraySize);
void getClosestCircleIndex(Circle circleArray[], int& closestCircleIndex, int index, bool& hitCircle, Point2d currentDart);
void setCirclesToGray(Circle circleArray[], int closestCircleIndex, int index);

int main()
{
  Circle circleArray[arraySize];
  ifstream fin;
  string fileName, color;
  double centerX, centerY, radius;
  int index = 0, points = 0, closestCircleIndex;
  Point2d currentDart;
  bool hitCircle;

  cout << "Input file name: ";
  cin >> fileName;

  fin.open(fileName.c_str());

  if (fin.fail())
  {
    cout << "ERROR: cannot open" << endl;
    exit(1);
  }

  while (fin >> centerX >> centerY >> radius >> color)
  {
    centerX = centerX;
    centerY = centerY;
    radius = radius;
    color = color;

    circleArray[index] = Circle(Point2d(centerX, centerY), radius, color);
    index++;
  }

  fin.close();

  for (int i = 0; i < 3; i++)
  {
    cout << "Round: " << i + 1 << endl;
    cout << "Points: " << points << endl;
    cout << "Where do you throw the dart (x y): ";
    cin >> currentDart;

    getClosestCircleIndex(circleArray, closestCircleIndex, index, hitCircle, currentDart);

    if (!hitCircle)
      {
        cout << "Miss!" << endl;
      } else
      {
        cout << "Hit: " << circleArray[closestCircleIndex];

        howManyPoints(circleArray, closestCircleIndex, points, arraySize);

        setCirclesToGray(circleArray, closestCircleIndex, index);
      }
  }

  cout << "Out of darts!" << endl;
  cout << "Points: " << points << endl;

  return 0;
}

void howManyPoints(Circle circleArray[], int closestCircleIndex, int& points, int arraySize)
{
    if (circleArray[closestCircleIndex].getColor() == "Red")
      {
        points += 10;
      }
       
    if (circleArray[closestCircleIndex].getColor() == "Yellow") 
      {
        points += 5;
      }

    if (circleArray[closestCircleIndex].getColor() == "Green")
      {
	points += 2;
      }

    if (circleArray[closestCircleIndex].getColor() == "Gray")
      {
	points -= 1;
      }
}

void getClosestCircleIndex(Circle circleArray[], int& closestCircleIndex, int index, bool& hitCircle, Point2d currentDart)
{
    hitCircle = false;
    int closestCircle;

    for (int j = 0; j < index; j++)
      {
        if (circleArray[j].contains(currentDart))
          {
	    if (!hitCircle)
	      {
		closestCircle = pointDist(circleArray[j].getCenter(), currentDart);
		closestCircleIndex = j;
	      }

            hitCircle = true;

            if (pointDist(circleArray[j].getCenter(), currentDart) < closestCircle)
	      {
	        closestCircle = pointDist(circleArray[j].getCenter(), currentDart);
	        closestCircleIndex = j;
	      }
          }
      }
}

void setCirclesToGray(Circle circleArray[], int closestCircleIndex, int index)
{
    circleArray[closestCircleIndex].setColor("Grey");

    for (int p = 0; p < index; p++)
      {
	if (hasOverlap(circleArray[p], circleArray[closestCircleIndex]))
	  {
	    circleArray[p].setColor("Gray");
	  }
      }
}