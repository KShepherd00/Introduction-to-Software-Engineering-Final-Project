#include <iostream>
using namespace std;
#include "View.h"
#include "Display.h"

//basic view functions that call their equivalent in the display class

View::View(){
  disp = new Display<char>(25, 5);
}

View::~View(){
  delete disp;
}

void View::update(int x, int y, char sym){
  disp->update(x,y,sym);
}

void View::remove(int x, int y){
  disp->remove(x,y);
}

void View::print(){
  disp->print();
}

void View::win(string name){
  cout<<name<<" has captured the emerald!"<<endl;
}

void View::lose(){
  cout<<"Both heros have died"<<endl;
}
