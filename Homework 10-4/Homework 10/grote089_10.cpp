//Sever Grote
//CSci 1113 HW 10

#include "Circle.hpp"
#include "Point2d.hpp"
#include "Target.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

Target *setTargetData(Target *array, int size, double xPos, double yPos, double r, string c);
Bubble *setBubbleData(Bubble *array, int size, double xPos, double yPos, double r);
Emoji *setEmojiData(Emoji *array, int size, double xPos, double yPos);

int main()
{
  Point2d currentDart;
  string inputFile, color, dataType;
  fstream fin;
  int targetArraySize = 0, bubbleArraySize = 0, emojiArraySize = 0, targetIndex = 0, bubbleIndex = 0, emojiIndex = 0, dartNumber = 1, points = 0, indexSum = 0;
  double x = 0.0, y = 0.0, radius = 0.0;
  bool first = true, targetHit, bubbleHit, emojiHit;

  cout << "Enter target file: ";
  cin >> inputFile;

  fin.open(inputFile.c_str());

  if (fin.fail())
  {
    cout << "Cannot open" << endl;
    exit(1);
  }

  if (fin >> targetArraySize >> bubbleArraySize >> emojiArraySize)
  {
    targetArraySize = targetArraySize;
    bubbleArraySize = bubbleArraySize;
    emojiArraySize = emojiArraySize;
  }

  Target *targetArray = new Target[targetArraySize];
  Bubble *bubbleArray = new Bubble[bubbleArraySize];
  Emoji *emojiArray = new Emoji[emojiArraySize];

  indexSum = targetArraySize + bubbleArraySize + emojiArraySize + 1;

  for (int v = 0; v < indexSum; v++)
  {
    if (!first)
    {
      fin >> dataType >> x >> y;
    }

    if (!first && dataType == "target" && targetIndex != targetArraySize)
    {
      fin >> radius >> color;

      targetArray = setTargetData(targetArray, targetIndex, x, y, radius, color);
      targetIndex++;
    }

    if (!first && dataType == "bubble" && bubbleIndex != bubbleArraySize)
    {
      fin >> radius;

      bubbleArray = setBubbleData(bubbleArray, bubbleIndex, x, y, radius);
      bubbleIndex++;
    }

    if (!first && dataType == "emoji" && emojiIndex != emojiArraySize)
    {
      emojiArray = setEmojiData(emojiArray, emojiIndex, x, y);
      emojiIndex++;
    }
    first = false;
  }

  while (dartNumber <= 3)
  {
    cout << "Dart: " << dartNumber << endl;
    cout << "insert dart (x y): ";
    cin >> currentDart;

    targetHit = false;
    bubbleHit = false;
    emojiHit = false;

    for (int t = 0; t < targetIndex; t++)
    {
      if (targetArray[t].contains(currentDart))
      {
        targetArray[t].hitTarget(points);
        targetHit = true;
      }
    }

    if (!targetHit)
    {
      for (int b = 0; b < bubbleIndex; b++)
      {
        if (bubbleArray[b].contains(currentDart))
        {
          bubbleArray[b].hitBubble(points);
          bubbleHit = true;
        }
      }
    }

    if (!targetHit && !bubbleHit)
    {
      for (int e = 0; e < emojiIndex; e++)
      {
        if (emojiArray[e].contains(currentDart))
        {
          emojiArray[e].hitEmoji(points);
          emojiHit = true;
        }
      }
    }

    if (!targetHit && !bubbleHit && !emojiHit)
    {
      cout << "Miss!" << endl;
    }

    cout << "Points: " << points << endl;
    dartNumber++;
  }

  cout << "Game Over!" << endl;

  delete [] targetArray;
  delete [] bubbleArray;
  delete [] emojiArray;

  fin.close();
}

Target *setTargetData(Target *array, int size, double xPos, double yPos, double r, string c)
{
  array[size] = Target();
  Point2d coordinates = Point2d(xPos, yPos);
  array[size].set(coordinates, r, c);

  return array;
}

Bubble *setBubbleData(Bubble *array, int size, double xPos, double yPos, double r)
{
  array[size] = Bubble();
  Point2d coordinates = Point2d(xPos, yPos);
  array[size].set(coordinates, r);

  return array;
}

Emoji *setEmojiData(Emoji *array, int size, double xPos, double yPos)
{
  array[size] = Emoji();
  Point2d coordinates = Point2d(xPos, yPos);
  array[size].set(coordinates);

  return array;
}
