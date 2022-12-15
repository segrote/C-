//Sever Grote
//CSci 1113 HW 05B

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double computeDiff(double metalPlate[10][10], double newMetalPlate[10][10], int rows, int cols);
void arrayUpdate(double metalPlate[10][10], double newMetalPlate[10][10], int rows, int cols);

int main()
{
  int rows = 0, cols = 0;
  string userFile;
  double tolerance, metalPlate[10][10], newMetalPlate[10][10], quantity = 10000;
  ifstream fin;

  cout << "Input the data file name: ";
  cin >> userFile;

  fin.open(userFile.c_str());

  if (fin.fail())
  {
    cout << "Cannot open file";
    exit(1);
  }

  cout << "Input the tolerance: ";
  cin >> tolerance;
  cout << endl;

  if (tolerance <= 0)
  {
    cout << "Tolerance  must  be  positive";
    exit(1);
  }

  if (fin >> rows >> cols)
  {
    rows = rows;
    cols = cols;
  }

  for (int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      fin >> metalPlate[i][j];
    }
  }

  fin.close();

  while (quantity > tolerance)
  {
    arrayUpdate(metalPlate, newMetalPlate, rows, cols);
    quantity = computeDiff(metalPlate, newMetalPlate, rows, cols);
  }

  for (int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      cout << fixed << setw(9) << setprecision(3) << metalPlate[i][j];
    }
    cout << endl;
  }

  return 0;
}

void arrayUpdate(double metalPlate[10][10], double newMetalPlate[10][10], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      newMetalPlate[i][j] = metalPlate[i][j];
    }
  }

  for (int k = 1; k < (rows - 1); k++)
  {
    for (int p = 1; p < (cols - 1); p++)
    {
      metalPlate[k][p] = (newMetalPlate[k - 1][p] + newMetalPlate[k + 1][p] + newMetalPlate[k][p - 1] + newMetalPlate[k][p + 1]) / 4;
    }
  }
}

double computeDiff(double metalPlate[10][10], double newMetalPlate[10][10], int rows, int cols)
{
  double sum = 0;

  for (int k = 0; k < (rows - 1); k++)
  {
    for (int p = 0; p < (cols - 1); p++)
    {
       sum = sum + pow(metalPlate[k][p] - newMetalPlate[k][p], 2);
    }
  }

  return sqrt(sum);
}
