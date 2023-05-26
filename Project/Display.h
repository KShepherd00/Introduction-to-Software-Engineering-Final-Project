#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
using namespace std;

//template class for a dynamically allocated 2D array
template <class T>
class Display{
 private:
  T** map; //the array
  int xLength;
  int yLength;
 public:
  Display(T, T);
  ~Display();
  void remove(int, int);
  void update(int, int, T);
  void print();
};

//ctor creates 2d array of size xDim by yDim, sets all values of inner array to 0
template <typename T>
Display<T>::Display(T xDim, T yDim){
  map = new T*[xDim]; //creates outer array of pointers
  for(int i=0; i<xDim; i++){
    map[i] = new T[yDim]; //populates outer array with inner array
  }
  for(int i=0; i<xDim; i++){
    for(int j=0; j<yDim; j++){
      map[i][j] = 0; //defaults all inner array values to 0
    }
  }
  //length characteristics
  xLength = xDim;
  yLength = yDim;
}
//display ctor
template <typename T>
Display<T>::~Display(){
  for(int i=0; i<xLength; i++){
    delete map[i];
  }
  delete map;
}

//sets the value at a given location to 0
template <typename T>
void Display<T>::remove(int x, int y){
  map[x][y] = 0;
}

//sets value at given location to symbol param
template <typename T>
void Display<T>::update(int x, int y, T symbol){
  map[x][y] = symbol;
}

//prints the map in proper format with all empty/0 values printed as a space
template <typename T>
void Display<T>::print(){
  for(int i=0; i<xLength; i++){
    cout<<"-";
  }
  cout<<endl;
  for(int y=0; y<yLength; y++){
    for(int x=0; x<xLength; x++){
      if(map[x][y] == 0)
	cout << " ";
      else
	cout << map[x][y];
    }
    cout<<endl;
  }
  for(int i=0; i<xLength; i++){
    cout<<"-";
  }
  cout<<endl;
}

#endif
