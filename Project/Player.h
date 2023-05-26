#ifndef PLAYER_H
#define PLAYER_H

//abstract player class, has all data members needed for child classes
class Player{
 public:
  virtual void move() = 0;
  virtual void collide(Player&) = 0;
  virtual bool win() = 0;
  virtual bool die() = 0;
  int getX();
  int getY();
  int getStrength();
  char getSymbol();
  string getType();
  int random(int);
  bool getAlive();
 protected:
  bool alive;
  char symbol;
  string type;
  int armour;
  int strength;
  int health;
  int x;
  int y;
};

//fighter class, inherits from player and provides implementataion for
//virtual void functions
class Fighter : public Player{
 public:
  Fighter();
  void move();
  void collide(Player&);
  bool die();
  bool win();
  
};
//a type of fighter
class Dorc : public Fighter{
 public:
  Dorc();
};
//a type of fighter
class Borc : public Fighter{
 public:
  Borc();
};
//a type of fighter
class Porc : public Fighter{
 public:
  Porc();
};
//timmy class inherits from player, has implementation of all functions
class Timmy : public Player{
 public:
  Timmy();
  void move();
  void collide(Player&);
  bool die();
  bool win();
};
//harold class inherits from player
class Harold : public Player{
 public:
  Harold();
  void move();
  void collide(Player&);
  bool die();
  bool win();
};
//dragon class
class Dragon : public Player{
 public:
  Dragon();
  void move();
  void collide(Player&);
  bool win();
  bool die();
 private:
  bool up;
};

#endif
