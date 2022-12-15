//CSci 1113 HW 2B
//Sever Grote

#include <iostream>
#include <iomanip>
using namespace std;

int main() //main method
{
    int tolerance, red, green, blue, median, max1, max2, max3, c1, c2, c3; //initialize variables for program

    do {
    cout << "Input tolerance: ";
    cin >> tolerance;

    if (tolerance < 0)
    {
      cout << "Tolerance must be nonnegative" << endl;
    }
  } while (tolerance < 0); //loop to get valid input from user

    do {
      cout << "Input red, green, and blue components: ";
      cin >> red >> green >> blue;

      if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
      {
        cout << "All components must be between 0 and 255, inclusive." << endl;
      }
    } while (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255); //loop to get valid input from user

    median = red; //default variable conditions in case nothing is reassigned
    max1 = -3;
    max2 = -3;
    max3 = -3;

    if (red >= green && red >= blue)
    {
      max1 = red;
    }

    if (blue >= green && blue >= red)
    {
      max2 = blue;
    }

    if (green >= red && green >= blue)
    {
      max3 = green;
    }

    if (red > green && green > blue)
    {
      median = green;
      max1 = red;
    }

    if (blue > green && green > red)
    {
      median = green;
      max2 = blue;
    }

    if (green > red && red > blue)
    {
      median = red;
      max3 = green;
    }

    if (blue > red && red > green)
    {
      median = red;
      max2 = blue;
    }

    if (red > blue && blue > green)
    {
      median = blue;
      max1 = red;
    }

    if (green > blue && blue > red)
    {
      median = blue;
      max3 = green;
    }

    c1 = red - median; //make rgb value into value to compare with tolerance
    c2 = green - median;
    c3 = blue - median;

    if (tolerance >= c1 && tolerance >= c2 && tolerance >=c3) //check tolerances
    {
      cout << "The color is a near gray. "; //print if color is near gray
    } else {
      cout << "The color is not a near gray.";
      return 0;
    }

    if (max1 == red && max2 == blue && max3 == green) //check if components are equal
    {
      cout << "All components are equal.";
      return 0;
    }

    if (max1 == red && max2 == blue) //as the computer goes down the list it will stop if the values are right
    {
      cout << "The red and blue components are the largest";
      return 0;
    }

    if (max1 == red && max3 == green)
    {
      cout << "The red and green components are the largest";
      return 0;
    }

    if (max2 == blue && max3 == green)
    {
      cout << "The green and blue components are the largest";
      return 0;
    }

    if (max1 == red)
    {
      cout << "The red component is the largest";
      return 0;
    }

    if (max2 == blue)
    {
      cout << "The blue component is the largest";
      return 0;
    }

    if (max3 == green)
    {
      cout << "The green component is the largest";
      return 0;
    }
    return 0;
}
