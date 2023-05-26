#ifndef CONTROL_H
#define CONTROL_H
#include <list>
#include <iterator>
#include "Player.h"
#include "View.h"

//control class handles all main operations of the program
//contains 2 lists of player pointers and a view
class Control{
 private:
  list<Player*> players; //contains enemies, name could be changed in future
  list<Player*> heroes; //contains heroes, timmy and harold
  View view;
 public:
  void launch();
  void init();
  bool handleTurn();
  int random(int);

};

#endif
