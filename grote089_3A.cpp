//Sever Grote CSci 1113
// HW 03A

#include <iostream>
#include <ctype.h>

using namespace std;

int main() {

    //START DO NOT MODIFY
    int rotate;
    char mode;
    string message;

    cout << "Encrypt (e/E) or Decrypt (d/D)?\n";
    cin >> mode;
    cout << "What is the cipher rotation value?\n";
    cin >> rotate;

    cout << "What is the message?\n";
    cin.ignore();
    getline(cin, message);
    //END DO NOT MODIFY

    //BEGIN YOUR CODE HERE:
    char c; //initialize variable for changing message order

    if (mode != 'd' && mode != 'e' && mode != 'D' && mode != 'E') //check for invalid input
    {
      cout << "INVALID MODE...  TERMINATING";
      return 0; //end program
    }

    if (rotate > 25 || rotate < 0) //check for invalid cipher roation value
    {
      cout << "INVALID ROTATION...  TERMINATING";
      return 0; //end program
    }

    if (mode == 'e' || mode == 'E') //check if user wants to encrypt message
    {
      for (int i = 0; i < message.length(); i++) //loop to cycle through each message char
      {
        if (message.at(i) == ' ') //check for blank space and fix
        {
          message = message.substr(0, i) + message.substr(i+1, message.length() - i - 1); //I got help from a TA and this is what he came up with
          i--;
        } else {

          c = message.at(i); //assign c to whatever char message is at

          if (int(c) >= 97 && int(c) <= 122) //convert lower to upper case
          {
            message.at(i) = int(c) - 32;
          }
          c = message.at(i) + rotate; //encrypt message

          if (int(c) > 90) //check if chars encrypted past Z
          {
            int difference = int(c) - 90;
            c = difference + 64; //order chars in correct order
          }

          message.at(i) = c; //reassign changed char into message
      }
      }
    } else { //now we know the user selected to decrypt

      for (int i = 0; i < message.length(); i++) //loop to check each char in message
      {
        if (message.at(i) == ' ') //check for blank space and fix
        {
          message = message.substr(0, i) + message.substr(i+1, message.length() - i - 1); //I got help from a TA and this is what he came up with
          i--;
        } else {

          c = message.at(i); //assign c to whatever char message is at

          if (int(c) >= 97 && int(c) <= 122) //convert lower to upper case
          {
            message.at(i) = int(c) - 32;
          }
          c = message.at(i) - rotate; //decrypt message

          if (int(c) < 65) //check if chars encrypted past A
          {
            int difference = 65 - int(c);
            c = 91 - difference; //order chars in correct order
          }

          message.at(i) = c; //reassign changed char into message
      }
      }
    }

    cout << "Translated message: ";
    for (int i = 0; i < message.length(); i++) //loop to cycle through message and print each letter
    {
      cout << message.at(i);
    }
    return 0; //end program
}
