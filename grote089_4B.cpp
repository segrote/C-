//Sever Grote
//CSci 1113 HW 04B

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

double vectorLength(double u, double v, double w); //initialize functions
void vectorNormalize(double& u, double& v, double& w);
void interpolateVectors(double a, double u1, double v1, double w1,double u2, double v2, double w2, double& u, double& v, double& w);

int main()
{
  double u1, v1, w1, u2, v2, w2, u, v, w; //initialize variables
  int n, i = 0;

  cout << "Input the first vector u1 v1 w1: "; //get all the input we need and validate it
  cin >> u1 >> v1 >> w1;

  cout << "Input the second vector u2 v2 w2: ";
  cin >> u2 >> v2 >> w2;

  if (u1 == 0 && v1 == 0 && w1 == 0 || u2 == 0 && v2 == 0 && w2 == 0)
  {
    cout << "Vectors must be non-zero.";
    exit(1); //stop the program
  }

  vectorNormalize(u1, v1, w1); //normalize both vectors
  vectorNormalize(u2, v2, w2);

  cout << "Enter the number of interpolation vectors to compute: ";
  cin >> n;

  double a = 0;
  double increment = 1.0 / (n - 1); //calculate what a needs to incremented by

  while (i < n) //loop to print all vectors from 0 to 1
  {

    interpolateVectors(a, u1, v1, w1, u2, v2, w2, u, v, w);
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << setw(8) << u << setw(8) << v << setw(8) << w << endl;
    i++;
    a = a + increment;
  }

  return 0; //stop program
}

double vectorLength(double u, double v, double w)
{
  double result = sqrt(u * u + v * v + w * w); //calculate vector Length
  return result; //return calculated result
}

void vectorNormalize(double& u, double& v, double& w)
{
  double length = vectorLength(u, v, w);

  u = u / length; //calculate normal vectors
  v = v / length;
  w = w / length;
}

void interpolateVectors(double a, double u1, double v1, double w1, double u2, double v2, double w2, double& u, double& v, double& w)
{
  u = (1 - a) * u1 + a * u2; //calculate interpolate vector
  v = (1 - a) * v1 + a * v2;
  w = (1 - a) * w1 + a * w2;

  vectorNormalize(u, v, w); //normalize interpolate vectors
}
