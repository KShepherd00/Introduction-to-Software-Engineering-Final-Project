using namespace std;
#include <iostream>
#include "Player.h"

//ctor, sets alive to true
Fighter::Fighter(){
  alive = true;
}

//moves fighters one space to the left and
//at random 1 up, 1 down or no change in the y direction
void Fighter::move(){
  --x;
  int yMove = random(2);
  if((yMove == 0) && ( y< 4))
    ++y;
  if((yMove == 1) && (y > 0))
    --y;
}

//handles fighter collision
void Fighter::collide(Player& p){
  if(!alive){return;};
  if((x == p.getX()) && (y == p.getY())){
    if((p.getType() == "timmy") || (p.getType() == "harold")){
      if(p.getAlive()){
	health -= p.getStrength();
      }
    }
  }
}

//handles and checks for fighter death
bool Fighter::die(){
  if(health <= 0){
    symbol = 0;
    alive = false;
    return true;
  }
  return false;
}

bool Fighter::win(){
  return false;
}
