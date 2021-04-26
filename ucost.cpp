#include "board.h"

using namespace std;

board::board(){
    this -> moveUp();
    this -> moveDown();
    this -> moveLeft();
    this -> moveRight();
    this -> parent = NULL;
    

}