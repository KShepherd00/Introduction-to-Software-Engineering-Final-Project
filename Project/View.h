#ifndef VIEW_H
#define VIEW_H
#include "Display.h"

//view class manages a display object and handles the interaction between
//the display and the control
class View{
 private:
  Display<char>* disp;
 public:
  ~View();
  View();
  void update(int, int, char);
  void remove(int, int);
  void print();
  void win(string);
  void lose();
};



#endif
