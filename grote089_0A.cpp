//CSci 1113 HW 0
//Sever Grote

#include <iostream>
#include <cmath> //include math package
using namespace std;

int main() //math method
{
	double x; //initilaize variables
	double y; //initilaize variables
	double z; //initilaize variables

	cout << "Input Cartesian coordinates x, y, z: "; //ask user for input
	cin >> x >> y >> z; //get users x, y, z

	double r = sqrt((x * x) + (y * y) + (z * z)); //calculate r
	double theta = atan2(y, x); //calculate theta
	double phi = acos(z / r); //calculate phi

	double thetaDegrees = theta * (180 / M_PI); //convert radians to degrees
	double phiDegrees = phi * (180 / M_PI); //convert radians to degrees

	cout << "Spherical coordinates: (" << r << ", " << thetaDegrees << ", " << phiDegrees << ")"; //print out spherical coordinates

	return 0;
}
