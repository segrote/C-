//Sever Grote
//CSci 1113 HW 07A

#include <iostream>
#include "SensorReading.hpp"

using namespace std;

int main()
{
  char input;
  int adjustTime;
  double adjustDirection;

  SensorReading s1 = SensorReading(6722, 724.5, 340.8, 5.2);

  do {

    cout << "Validate(v), print(p), adjust time(t), adjust direction(d), or quit(q): ";
    cin >> input;

    if (input == 'v' || input == 'p' || input == 't' || input == 'd')
    {
      if (input == 'v')
      {
        if (s1.validateTime() && s1.validatePressure() && s1.validateWindDirection() && s1.validateWindSpeed())
        {
          cout << "Valid" << endl;
        } else
        {
          cout << "NOT valid" << endl;
        }
      }

      if (input == 'p')
      {
        s1.print();
      }

      if (input == 't')
      {
        cout << "Amount of change: ";
        cin >> adjustTime;
        s1.adjustTime(adjustTime);
      }

      if (input == 'd')
      {
        cout << "Amount of change: ";
        cin >> adjustDirection;
        s1.adjustWindDirection(adjustDirection);
      }
    } else
    {
    if (input != 'q')
    {
      cout << "That character is not an option" << endl;
    }
    }
  } while (input != 'q');

  return 0;
}
