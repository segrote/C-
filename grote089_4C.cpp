//Sever Grote
//CSci 1113 HW 04C

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void printResults(string userTeam1, string userTeam2, int team1Games, int team2Games); //initialize function to print out results

int main()
{
  string userTeam1, userTeam2, team1, team2; //initialize variables
  int seasonNumber1, team1Score, team2Score, team1Games = 0, team2Games = 0; //initialize variables
  ifstream fin; //initialize stream to search file

  cout << "Please input the two teams you are interested in: "; //get users input
  cin >> userTeam1 >> userTeam2;

  fin.open("sports.dat"); //open file we want to search

  if (fin.fail()) //test if file is valid/their
  {
    cout << "ERROR! File does not exist :("; //print out error and exit
    exit(1);
  }

  while (fin >> seasonNumber1 >> team1 >> team2 >> team1Score >> team2Score) //loop to check files data
  {
    if (team1 == userTeam1 && team2 == userTeam2) //check if users input is the same as what we are looking at in the file
    {
      if (team1Score > team2Score) //compare scores to increment
      {
        team1Games++;
      }

      if (team1Score < team2Score)
      {
        team2Games++;
      }
    }

    if (team1 == userTeam2 && team2 == userTeam1) //check if users input is the same as what we are looking at in the file in a different order
    {
      if (team1Score > team2Score) //compare scores to increment
      {
        team2Games++;
      }

      if (team1Score < team2Score)
      {
        team1Games++;
      }
    }
  }

  fin.close(); //close file now that we know everything we need

  printResults(userTeam1, userTeam2, team1Games, team2Games); //call to function to print out our results

  return 0; //end program
}

void printResults(string userTeam1, string userTeam2, int team1Games, int team2Games) //function/method to print out results
{
  //this prints out all the results and all the cases possible
  cout << "The " << userTeam1 << " and the " << userTeam2 << " played " << team1Games + team2Games << " times." << endl;
  cout << "The " << userTeam1 << " won " << team1Games << " times." << endl;
  cout << "The " << userTeam2 << " won " << team2Games << " times." << endl;
  if (team1Games > team2Games)
  {
    cout << "The " << userTeam1 << " are the better team!";
  }

  if (team1Games < team2Games)
  {
    cout << "The " << userTeam2 << " are the better team!";
  }

  if (team1Games == team2Games)
  {
    cout << "The teams are equally matched!";
  }
}
