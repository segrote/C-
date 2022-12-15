//CSci 1113 HW 1A
//Sever Grote

#include <iostream>
#include <cmath> //include math package
using namespace std;

int main() //main method
{
  double r, g, b; //initialize variables for users input
  double red, green, blue; //initialize variables for equated values
  char input; //initialize variable for users input

  cout << "Input r, g, b: "; //ask user to input 3 values
  cin >> r >> g >> b; //assign users values into variables

  cout << "Options:\n"; //print out users options
  cout << "Enhance contrast (E)\n";
  cout << "Decrease contrast (D)\n";
  cout << "Enter E or D: ";
  cin >> input; //assign users value into variable

  if (input == 'E') //check users input
  {
    red = (127.5) * (sin((r / 255.0 - .5) * M_PI)) + 127.5; //transform users input to enhance rgb values
    green = (127.5) * (sin((g / 255.0 - .5) * M_PI)) + 127.5;
    blue = (127.5) * (sin((b / 255.0 - .5) * M_PI)) + 127.5;

    cout << "(" << round(red) << ", " << round(green) << ", " << round(blue) << ")"; //print out enhanced rgb values
    return 0; //return (end)
  }

  if (input == 'D') //check users input
  {
    red = (255.0) * ((1 / M_PI) * (asin((r - 127.5) / 127.5)) + .5); //transform users input to decrease rgb values
    green = (255.0) * ((1 / M_PI) * (asin((g - 127.5) / 127.5)) + .5);
    blue = (255.0) * ((1 / M_PI) * (asin((b - 127.5) / 127.5)) + .5);

    cout << "(" << round(red) << ", " << round(green) << ", " << round(blue) << ")"; //print out decreased rgb values
    return 0; //return (end)
  }

  cout << "Invalid option"; //if program makes it this far the user didn't input a correct value to enhance or decrease
  return 0; //return (end)
}
