//Sever Grote
//CSci 1113 HW 05A

#include <iostream>
#include <stdlib.h>

using namespace std;

double leftHeight(double heights[], int index); //declare functions
double rightHeight(double heights[], int index);
double waterHeight(double heights[], int index);

int main()
{
  double heights[10], amountOfWater = 0.0; //declare variables for program
  cout << "Input 10 heights: ";
  cin >> heights[0] >> heights[1] >> heights[2] >> heights[3] >> heights[4] >>
         heights[5] >> heights[6] >> heights[7] >> heights[8] >> heights[9];

  for (int i = 0; i < 10; i++) //loop to check if input is valid
  {
    if (heights[i] <= 0.0)
    {
      cout << "Invalid heights!";
      exit(1);
    }
  }

  for (int index = 0; index < 10; index++) //loop to scan through array and determine if it can hold water
  {
    if (leftHeight(heights, index) != 0.0 && rightHeight(heights, index) != 0.0)
    {
      amountOfWater = amountOfWater + waterHeight(heights, index);
    }
  }

  cout << "Amount of water: " << amountOfWater; //print total amount of water
  return 0;
}

double leftHeight(double heights[], int index) //function to get maximum height to left of index
{
  if (index == 0)
  {
    return 0.0;
  }

  double max = 0;

  for (int i = index - 1; i >= 0; i--)
  {
    if (heights[i] > max && heights[i] > heights[index])
    {
      max = heights[i];
    }
  }

  return max;
}

double rightHeight(double heights[], int index) //function to get maximum height to right of index
{
  if (index == 9)
  {
    return 0.0;
  }

  double max = 0;

  for (int i = index + 1; i <= 9; i++)
  {
    if (heights[i] > max && heights[i] > heights[index])
    {
      max = heights[i];
    }
  }

  return max;
}

double waterHeight(double heights[], int index) //function to get water height for a given index
{
  double left, right;

  left = leftHeight(heights, index);
  right = rightHeight(heights, index);

  if (left > right)
  {
    return right - heights[index];
  }

  if (left < right)
  {
    return left - heights[index];
  }

  return 0;
}
