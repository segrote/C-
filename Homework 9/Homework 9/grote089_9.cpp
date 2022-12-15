//Sever Grote
//CSci 1113 HW9

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "SensorReading.hpp"

using namespace std;

int main()
{
    ifstream fin;
    ofstream errorLog, validLog, deltaLog; //ran out of time for function decomposition :(
    int mainTime, size = 0, currentMaxTime, index = 0, validDeltaIndex = 0, highestPressureIndex = 0, lowestPressureIndex = 0;
    int latestHighPressureTimeIndex = 0, latestLowPressureTimeIndex = 0, deltaTime, latestTimeIndex = 0;
    int highLocation = 0, lowLocation = 0, earliestTimeIndex = 0;
    double mainPressure, mainWindDirection, mainWindSpeed, lowestPressuresMax = 0;
    bool multipleHighPressures = false, multipleLowPressures = false, wasChanged = false;

    fin.open("readings.dat");

    if (fin.fail())
    {
      cout << "ERROR, readings file not in directory!" << endl;
      exit(1);
    }

    while (fin >> mainTime >> mainPressure >> mainWindDirection >> mainWindSpeed)
    {
        size++;
    }

    fin.close();

    SensorReading *objectArray = new SensorReading[size];

    fin.open("readings.dat");

    if (fin.fail())
    {
      cout << "ERROR, readings file not in directory!" << endl;
      exit(1);
    }

    while (fin >> mainTime >> mainPressure >> mainWindDirection >> mainWindSpeed)
    {
      mainTime = mainTime;
      mainPressure = mainPressure;
      mainWindDirection = mainWindDirection;
      mainWindSpeed = mainWindSpeed;

      if (mainTime > currentMaxTime || index == 0)
      {
        currentMaxTime = mainTime;
        objectArray[index] = SensorReading(mainTime, mainPressure, mainWindDirection, mainWindSpeed);
        index++;
      }
    }

    fin.close();
    errorLog.open("error.log");
    validLog.open("readings.sanitized.dat");
    deltaLog.open("pressure.delta.log");

    if (errorLog.fail() || validLog.fail() || deltaLog.fail())
    {
      cout << "ERROR, can't open files!" << endl;
      exit(1);
    }

    SensorReading *deltaObjectArray = new SensorReading[index];
    SensorReading *highestPressures = new SensorReading[index];
    SensorReading *lowestPressures = new SensorReading[index];

    for (int i = 0; i < index; i++)
    {
      if (!objectArray[i].validate())
      {
        errorLog << objectArray[i];
      } else
      {
        validLog << objectArray[i];
        deltaObjectArray[validDeltaIndex] = objectArray[i];
        validDeltaIndex++;
      }
    }

    for (int j = 0; j < validDeltaIndex; j++)
    {
      if (deltaObjectArray[j].getPressure() >= deltaObjectArray[highestPressureIndex].getPressure())
      {
        highestPressures[highLocation] = deltaObjectArray[j];
        highLocation++;
        highestPressureIndex = j;
      } else
      {
        lowestPressures[lowLocation] = deltaObjectArray[j];
        lowLocation++;
        lowestPressureIndex = j;
      }
    }

    for (int p = 0; p < highLocation; p++)
    {
      if (highestPressures[p].getPressure() >= highestPressures[latestHighPressureTimeIndex].getPressure())
      {
        if (highestPressures[p].getPressure() == highestPressures[latestHighPressureTimeIndex].getPressure() && p != 0)
        {
          multipleHighPressures = true;
        } else
        {
          multipleHighPressures = false;
        }
        latestHighPressureTimeIndex = p;
      }
    }

    if (multipleHighPressures)
    {
      for (int a = 0; a < highLocation; a++)
      {
        if (highestPressures[a].getTime() > highestPressures[latestTimeIndex].getTime() || a == 0)
        {
          latestTimeIndex = a;
          wasChanged = true;
        }
      }
    }

    if (wasChanged)
    {
      latestHighPressureTimeIndex = latestTimeIndex;
    }

    for (int e = 0; e < lowLocation; e++)
    {
      if (lowestPressures[e].getPressure() > lowestPressuresMax)
      {
        lowestPressuresMax = lowestPressures[e].getPressure();
      }
    }

    for (int k = 0; k < lowLocation; k++)
    {
      if (lowestPressures[k].getPressure() <= lowestPressuresMax && highestPressures[latestHighPressureTimeIndex].getTime() < lowestPressures[k].getTime())
      {
        if (lowestPressures[k].getPressure() == lowestPressures[latestLowPressureTimeIndex].getPressure() && k != 0)
        {
          multipleLowPressures = true;
        } else
        {
          multipleLowPressures = false;
        }
        latestLowPressureTimeIndex = k;
        lowestPressuresMax = lowestPressures[k].getPressure();
      }
    }

    wasChanged = false;

    if (multipleLowPressures)
    {
      for (int b = 0; b < lowLocation; b++)
      {
        if ((highestPressures[latestHighPressureTimeIndex].getTime() > lowestPressures[b].getTime() && lowestPressures[b].getTime() < lowestPressures[earliestTimeIndex].getTime()) || b == 0)
        {
          earliestTimeIndex = b;
          wasChanged = true;
        }
      }
    }

    if (wasChanged)
    {
      latestLowPressureTimeIndex = earliestTimeIndex;
    }

    deltaTime = abs(highestPressures[latestHighPressureTimeIndex].getTime() - lowestPressures[latestLowPressureTimeIndex].getTime());

    deltaLog << highestPressures[latestHighPressureTimeIndex].getTime() << " " << deltaTime << " " << highestPressures[latestHighPressureTimeIndex].getPressure() << " " << lowestPressures[latestLowPressureTimeIndex].getPressure() << endl;

    errorLog.close();
    validLog.close();
    deltaLog.close();
    delete [] objectArray;
    delete [] deltaObjectArray;
    delete [] highestPressures;
    delete [] lowestPressures;

    return 0;
}
