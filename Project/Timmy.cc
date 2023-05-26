using namespace std;
#include <iostream>
#include "Player.h"

//timmy ctor
Timmy::Timmy(){
  symbol = 'T';
  type = "timmy";
  armour = 3;
  strength = 3;
  health = 15;
  x = 0;
  y = random(4);
  alive = true;
}

//moves timmy one to the right, and at random
//either one up one down or no vertical change
void Timmy::move(){
  if(!alive){return;}
  if(y == 24){win();}
  ++x;
  int yMove = random(2);
  if((yMove == 0) && ( y< 4))
    ++y;
  if((yMove == 1) && (y > 0))
    --y;
}

//handles timmy collisions
void Timmy::collide(Player& p){
  if(!alive){return;}
  if((x == p.getX()) && (y == p.getY())){
    if(p.getType() == "dragon"){health =0;}
    if(p.getType() == "fighter"){
      health -= (p.getStrength() - armour);
    }
  }
}

//checks for and handles timmy death
bool Timmy::die(){
  if(!alive){return true;}
  if(health <= 0){
    alive = false;
    symbol = '+';
    return true;
  }
  return false;
}

//checks for and handles timmy win
bool Timmy::win(){
  if((x == 24) && (alive)){
    return true;
  }
  return false;
}
