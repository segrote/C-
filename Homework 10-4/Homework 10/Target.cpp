#include <iostream>
#include "Target.hpp"

using namespace std;

Bubble::Bubble() : Circle()
{
  setColor("Blue");
  setPopped(false);
}

Emoji::Emoji() : Circle()
{
  setRadius(10.0);
  setColor("Yellow");
  setCurrentMood("happy");
}

void Target::hitTarget(int& currentPoints)
{
  cout << "Hit: " << getColor() << " Target" << endl;

  if (getColor() == "Red")
  {
    currentPoints += 10;
  } else

  if (getColor() == "Yellow")
  {
    currentPoints += 5;
  } else

  if (getColor() == "Green")
  {
    currentPoints += 2;
  } else
  {
    currentPoints += 1;
  }
}

void Target::set(Point2d coords, double r, string c)
{
  circleCenter = coords;
  radius = r;
  circleColor = c;
}

bool Bubble::getPopped() const
{
  return wasPopped;
}

void Bubble::set(Point2d coords, double r)
{
  circleCenter = coords;
  radius = r;
}

string Emoji::getCurrentMood() const
{
  return currentMood;
}

void Emoji::set(Point2d coords)
{
  circleCenter = coords;
}

void Bubble::setPopped(bool newPopped)
{
  wasPopped = newPopped;
}

void Emoji::setCurrentMood(string newMood)
{
  currentMood = newMood;
}

string Target::getColor() const
{
  return circleColor;
}

void Bubble::hitBubble(int& currentPoints)
{
  if (getPopped())
  {
    cout << "Plunk!" << endl;
  } else
  {
    cout << "Pop!" << endl;
    currentPoints += 20;
    setPopped(true);
  }
}

void Emoji::hitEmoji(int& currentPoints)
{
  cout << "Hit: " << currentMood << " emoji" << endl;
  if (getCurrentMood() == "happy")
  {
    setCurrentMood("sad");
    cout << "Now it's " << getCurrentMood() << endl;
  } else

  if (getCurrentMood() == "sad")
  {
    setCurrentMood("mad");
    cout << "Now it's " << getCurrentMood() << endl;

  } else

  if (getCurrentMood() == "mad")
  {
    cout << "you should not have done that" << endl;
    setCurrentMood("happy");
    cout << "Now it's " << currentMood << endl;
    currentPoints -= 1000;
  }
}
