#include "Circle.hpp"
#include "Point2d.hpp"
#ifndef TARGET_HPP
#define TARGET_HPP

using namespace std;

class Target: public Circle
{
public:
  void hitTarget(int& currentPoints);
  void set(Point2d coords, double r, string c);
  string getColor() const;
};

class Bubble : public Circle
{
private:
  bool wasPopped;

public:
  Bubble();
  void hitBubble(int& currentPoints);
  bool getPopped() const;
  void setPopped(bool newPopped);
  void set(Point2d coords, double r);
};

class Emoji : public Circle
{
private:
  string currentMood;

public:
  Emoji();
  void hitEmoji(int& currentPoints);
  string getCurrentMood() const;
  void setCurrentMood(string newMood);
  void set(Point2d coords);
};

#endif
