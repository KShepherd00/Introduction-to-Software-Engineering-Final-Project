using namespace std;
#include <iostream>
#include "Player.h"

//borc ctor, sets symbol, initial location and stats
Borc::Borc(){
  type = "fighter";
  symbol = 'b';
  health = 5;
  strength = 8 + random(3);
  x = 24;
  y = random(4);
}
