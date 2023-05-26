using namespace std;
#include <iostream>
#include "Player.h"

//all needed player class getters

int Player::getX(){
  return x;
}

int Player::getY(){
  return y;
}

int Player::getStrength(){
  return strength;
}

char Player::getSymbol(){
  return symbol;
}

string Player::getType(){
  return type;
}

int Player::random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}

bool Player::getAlive(){
  return alive;
}
