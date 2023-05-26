using namespace std;
#include <iostream>
#include "Player.h"

//dorc ctor, sets symbol, initial location and stats
Dorc::Dorc(){
  type = "fighter";
  symbol = 'd';
  health = 5;
  strength = 6 + random(2);
  x = 24;
  y = random(4);
}
