//Sever Grote
//CSci HW 04A

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double arctanApprox(double x, double tol);

int main()
{
  double tolerance;
  char answer;

  do {
    cout << "Input tolerance: ";
    cin >> tolerance;
      if (tolerance < 0)
    {
      cout << "Tolerance must be positive. ";
    } else {

      double tan1 = arctanApprox(1.0/5.0, tolerance);
      double tan2 = arctanApprox(1.0/239.0, tolerance);
      double pie = (16 * tan1) - (4 * tan2);

      std::cout << "PI approximation: " << setprecision(14) << pie << endl;
      cout << "Do you wish to approximate pi again? ";
      cin >> answer;
          }

      } while (tolerance < 0 || answer == 'y' || answer == 'Y');

  return 0;
}

double arctanApprox(double x, double tol)
{
  int j = 2;
  double result = x, lastResult, y, z = 3, e = x;
  do {
    lastResult = result;

    e = e * x * x;
    y = (e) / z;

    if (j % 2 == 0)
    {
      result = result - y;
    } else
    {
      result = result + y;
    }

    j++;
    z = z + 2;
  } while (fabs(result - lastResult) > tol/20);

  return result;
}
