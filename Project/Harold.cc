using namespace std;
#include <iostream>
#include "Player.h"

//harold ctor
Harold::Harold(){
  symbol = 'H';
  type = "harold";
  armour = 1;
  strength = 5;
  health = 15;
  x = 0;
  y = random(4);
  alive = true;
}

//moves harold one space right and at random
//either 1 up, 1 down or no vertical change
void Harold::move(){
  if(!alive){return;}
  ++x;
  int yMove = random(2);
  if((yMove == 0) && ( y< 4))
    ++y;
  if((yMove == 1) && (y > 0))
    --y;
}

//handles harold collsion
void Harold::collide(Player& p){
  if(!alive){return;}
  if((x == p.getX()) && (y == p.getY())){
    if(p.getType() == "dragon"){health = 0;}
    if(p.getType() == "fighter"){
      health -= (p.getStrength() - armour);
    }
  }
}

//checks for and handles harold death
bool Harold::die(){
  if(!alive){return true;}
  if(health <= 0){
    alive = false;
    symbol = '+';
    return true;
  }
  return false;
}

//handles harold win
bool Harold::win(){
  if((x == 24) && (alive)){
    return true;
  }
  return false;
}
