using namespace std;
#include <iostream>
#include "Player.h"

//porc ctor, sets symbol, initial location and stats
Porc::Porc(){
  type = "fighter";
  symbol = 'p';
  health = 5;
  strength = 4 + random(1);
  x = 24;
  y = random(4);
}
