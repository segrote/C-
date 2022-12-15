//Sever Grote
//CSci 1113 HW 06A

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int findOverlap(string s1, string s2);

int main()
{
  string userInput, stringArray[30], swap;
  int index = 0, overlapLength = 0, max, maxIndex;
  ifstream fin;

  cout << "Input filename: ";
  cin >> userInput;

  fin.open(userInput.c_str());

  if (fin.fail())
  {
    cout << "Unable to open file";
    exit(1);
  }

  while (getline(fin, userInput))
  {
    stringArray[index] = userInput;
    index++;
  }

  fin.close();

  for (int l = 0; l < index - 1; l++)
  {
    max = 0;
    maxIndex = -2;
    for (int g = l+1; g < index; g++)
    {
      overlapLength = findOverlap(stringArray[l], stringArray[g]);

      if (overlapLength > max)
      {
        max = overlapLength;
        maxIndex = g;
      }
    }
    if (maxIndex != -2)
    {
      swap = stringArray[maxIndex];
      stringArray[maxIndex] = stringArray[l + 1];
      stringArray[l + 1] = swap;
    }
  }

  for (int i = 0; i < index; i++)
  {
    cout << stringArray[i] << endl;
  }

  return 0;
}

int findOverlap(string s1, string s2)
{
  string s1Overlap = "", s2Overlap = "", maxOverlap;
  int s1Position = s1.length() - 1, s2Position = 0, smallestString;

  if (s1.length() >= s2.length())
  {
    smallestString = s2.length();
  } else {
    smallestString = s1.length();
  }

  for (int i = 0; i < smallestString; i++)
  {
    s1Overlap = s1.at(s1Position) + s1Overlap;
    s2Overlap = s2Overlap + s2.at(s2Position);

    if (s1Overlap == s2Overlap)  //check if string 1 overlap is a substring of string 2
      {
        maxOverlap = s2Overlap;
      }

    s1Position--;
    s2Position++;
  }

  return maxOverlap.length();
}
