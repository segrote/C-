//CSci 1113 HW 2A
//Sever Grote

#include <iostream>
#include <iomanip>
using namespace std;

int main() //main method
{
    int hours, minutes, breakH, breakM; //initialize variables for given time and break desired
    char ampm; //initialize variable to get day or night
    bool choice = false; //initialize variable for correcting day or night
    cout << "Input the current time as hours minutes and A (am) or P (pm): "; //ask user for current time
    cin >> hours >> minutes >> ampm; //get users input

    cout << "Input the break time as hours minutes "; //ask user for break time
    cin >> breakH >> breakM; //get users break time

    minutes = minutes + breakM; //reassign minutes to account for break time
    hours = hours + breakH; //reassign hours to account for break time

    while (minutes >= 60) //loop to deduct minutes below 60
    {
      hours++; //incremnt hours by 1
      minutes = minutes - 60; //deduct minutes by an hours worth
    }

    while (hours > 12) //loop to deduct hours below 12
    {
      hours = hours - 12; //deduct hours by half a day
      if (ampm == 'A') //change day or night
      {
        ampm = 'P';
      } else {
        ampm = 'A';
      }
    }

    if (hours == 12 && ampm == 'P') //another check to make sure time of day is formatted right
    {
      ampm = 'A';
      choice = true; //variable to check if this if has been ran through
    }

    if (hours == 12 && ampm == 'A' && choice == false) //check to make sure time of day is formatted right
    {
      ampm = 'P';
    }

    cout << "Break is done at "; //print out break time

    cout << hours << ":";
    // Note, the following syntax works with the iomanip include above.
    // This has the effect of forcing the computer to print 2 digits (I.E. 06 instead of 6)
    // The following line is bug-free.
    cout << setfill('0') << setw(2) << minutes;

    if (ampm == 'P') //check what the final time of day is
    {
        cout << "PM";
    }
    else
    {
        cout << "AM";
    }
    cout << endl;
    return 0;
}
