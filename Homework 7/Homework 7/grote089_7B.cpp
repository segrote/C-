#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SensorReading.hpp"

using namespace std;

int size = 10;

int main()
{
  SensorReading array[size];
  string inputFile, outputFile;
  ifstream in;
  ofstream out;
  double pr, wD, wS;
  int t, index = 0, invalidReadings = 0, validReadings = 0;

  for (int i = 0; i < size; i++)
  {
    array[i] = SensorReading();
  }

  cout << "Input file: ";
  cin >> inputFile;

  cout << "Output file: ";
  cin >> outputFile;

  in.open(inputFile.c_str());
  out.open(outputFile.c_str());

  if (in.fail())
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }

  if (out.fail())
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }

  while (in >> t >> pr >> wD >> wS)
  {
    t = t;
    pr = pr;
    wD = wD;
    wS = wS;

    array[index].set(t, pr, wD, wS);
    index++;
  }

  in.close();

  for (int k = 0; k < index; k++)
  {
    array[k].adjustTime(-24);

    if (array[k].validateTime() && array[k].validatePressure() && array[k].validateWindDirection() && array[k].validateWindSpeed())
    {
      array[k].printCSV(out);
      validReadings++;
    } else
    {
      invalidReadings++;
    }
  }

  cout << "Number of invalid readings: " << invalidReadings << endl;
  cout << "Number of readings written to output file: " << validReadings << endl;

  out.close();

  return 0;
}
