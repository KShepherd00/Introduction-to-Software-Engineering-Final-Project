using namespace std;
#include <iostream>
#include "Player.h"

Dragon::Dragon(){
  type = "dragon";
  symbol = 'D';
  x = 24;
  y = 2;
  up = true;
}

//moves the dragon back and forth along cave entrance
void Dragon::move(){
  if(up){
    ++y;
    if(y==3)
      up = false;
  }
  else{
    --y;
    if(y==1)
      up = true;
  }
}

//the folowing functions do not serve a function but need to exist as they are
//needed in other player inherited classes
void Dragon::collide(Player&){
  return;
}

bool Dragon::win(){
  return false;
}
bool Dragon::die(){
  return false;
}
