//CSci 1113 HW 1B
//Sever Grote

#include <iostream>
#include <cmath> //include math package
#include <iomanip>
using namespace std;

int main() //main method
{
  char units; //initialize variable for users input
  double distance, hours, minutes, seconds, paceMinutes, paceSeconds; //initialize all variables used to determine pace

  cout << "Is the distance in kilometers(k) or miles(m)? "; //ask user for units
  cin >> units; //get users input

  if (units != 'k' && units != 'm') //check for valid input
  {
    cout << "Invalid distance option"; //print error message
    return 0; //stop program
  }

  cout << "\nInput distance: "; //ask for distance
  cin >> distance; //get distance

  cout << "\nInput target time in hours, minutes, and seconds.\n"; //ask for users target time

  cout << "Hours: ";
  cin >> hours; //get hours

  cout << "Minutes: ";
  cin >> minutes; //get minutes

  cout << "Seconds: ";
  cin >> seconds; //get seconds

  if (units == 'k') //check if units are in kilometers so we can convert them to miles
  {
    distance = distance * 0.62137119; //converting distance to miles
  }

  if (hours != 0) //check if user entered hours
  {
    hours = 60 * hours; //convert hours to minutes for conversion
    minutes = minutes + hours; //add converted hours to total minutes
  }

  if (seconds != 0) //check if user entered seconds
  {
    seconds = seconds / 60; //convert seconds to minutes for conversion
    minutes = minutes + seconds; //add converted seconds to total minutes
  }

  paceMinutes = minutes / distance; //divide users target time with the distance they need to run for pace

  int iM = (int)paceMinutes; //round paceminutes down to get a nice int number

  paceSeconds = (paceMinutes - iM) * 60; //get paceminutes decimal and convert to seconds

  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << "The average time per mile is " << (int)paceMinutes << " minutes and " << paceSeconds << " seconds"; //print out users pace

  return 0; //end program
}
