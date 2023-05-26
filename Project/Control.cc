#include <iostream>
using namespace std;
#include "Control.h"
#include <cstdlib>
#include <time.h>

//launch function infinite loop of repeating view.print and handleTurn
void Control::launch(){
  srand( (unsigned)time( NULL ) );
  init();
  bool run = true;
  while(run){
    view.print();
    run = handleTurn();
  }
  list<Player*>::iterator it;
  list<Player*>::iterator k;
  for(it = players.begin(); it != players.end(); ++it){
    delete (*it);
  }
  for(k = heroes.begin(); k!=heroes.end(); ++k){
    delete (*k);
  }
}

//initializes timmy harold and the dragon, adds to their respective lists
//updates view
void Control::init(){
  Player* t = new Timmy();
  heroes.push_back(t);
  Player* h = new Harold();
  heroes.push_back(h);
  Player* d = new Dragon();
  players.push_back(d);
  list<Player*>::iterator it;
  for(it = players.begin(); it != players.end(); ++it){
    view.update((*it)->getX(), (*it)->getY(), (*it)->getSymbol());
  }
}

//handles each turn in the simulation
//moves all characters and handles all possible collisions
//updates view as needed
bool Control::handleTurn(){
  list<Player*>::iterator i;
  list<Player*>::iterator j;
  list<Player*>::iterator k;
 
  //move and update players
  for(i = players.begin(); i!=players.end(); ++i){
    view.remove((*i)->getX(), (*i)->getY());
    (*i)->move();
    view.update((*i)->getX(), (*i)->getY(), (*i)->getSymbol());
  }
  //move and update heroes
  for(k = heroes.begin(); k!=heroes.end(); ++k){
    view.remove((*k)->getX(), (*k)->getY());
    (*k)->move();
    view.update((*k)->getX(), (*k)->getY(), (*k)->getSymbol());
  }
  //check hero collisions
  for(k = heroes.begin(); k!=heroes.end(); ++k){
    for(i = players.begin(); i!=players.end(); ++i){
      (*k)->collide((*(*i)));
      (*i)->collide((*(*k)));
      (*k)->die();
      if((*i)->die()){
	      view.remove((*i)->getX(), (*i)->getY());
      }
    }
    view.update((*k)->getX(), (*k)->getY(), (*k)->getSymbol());
  }
  //check for both heroes dead case
  if((heroes.front()->die()) && (heroes.back()->die())){
    view.print();
    view.lose();
    return false;
  }
  //check for winner
  for(k = heroes.begin(); k!=heroes.end(); ++k){
    if((*k)->win()){
      view.print();
      view.win((*k)->getType());
      return false;
    }
  }
  
  //spawn new fighters
  int spawn = random(9);
  if(spawn < 6){
    if(spawn > 3){
      Player* f = new Dorc();
      players.push_front(f);
    }
    else if((spawn > 1) && (spawn < 4)){
      Player* f = new Porc();
      players.push_front(f);
    }
    else{
      Player* f = new Borc();
      players.push_front(f);
    }
  }
  //update view
  for(i = players.begin(); i != players.end(); ++i){    
    view.update((*i)->getX(), (*i)->getY(), (*i)->getSymbol());
  }
  for(k = heroes.begin(); k!=heroes.end(); ++k){
    view.update((*k)->getX(), (*k)->getY(), (*k)->getSymbol());
  }
  
  return true;
}

//returns a random int
int Control::random(int max){
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}
