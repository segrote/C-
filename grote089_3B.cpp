//Sever Grote CSci 1113
//HW 03B

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int posts, dBP, dBS, signCount = 0, k; //initialize variables
  string fence = ""; //initialize string to contain fence layout

  cout << "How many posts do you want to use?\n"; //get users number of posts
  cin >> posts;

  cout << "How many feet between posts?\n"; //get users feet between posts
  cin >> dBP;

  cout << "What is the minimum distance between signs (in feet)?\n"; //get users minimum distance between signs
  cin >> dBS;

  k = dBS; //assign k to dBS

  for (int i = 1; i < posts; i++) //loop for all of users posts
  {
      fence += '|'; //add first post

    for (int j = 0; j < dBP; j++) //loop for the distance between posts
    {
      if (k <= 0 && j != 0 && j != dBP - 1) //check if sign can be placed
      {
        fence += 'S'; //add sign
        signCount++; //increment sign count
        k = dBS + 1; //reset k
      }
      else {
        fence += '-'; //if the check for sign fails, we will add a dash
      }
        k--; //decrement k
    }
    if (i == posts - 1) //check if we are at the end of the fence
    {
      fence+= '|';
    }
  }

  cout << fence << endl; //print out fence

  cout << "Total Signs: " << signCount; //print out sign count

  return 0; //end program
}
