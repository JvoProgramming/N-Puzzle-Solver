#include <iostream>
#include "board.h"

bool UCS = false;


board::board(){     //hard code the default puzzle for choice 1
    parent = NULL;
    gCost = 0;
    hCost = 0;
    initialState = {};
    goalState = {1,2,3,4,5,6,7,8,0};
    currentState = {1,2,3,4,5,6,7,8,0};
    misplacedCost();

}

board::board(vector<int> v){
    gCost = 0;
    parent = NULL;
    goalState = {1,2,3,4,5,6,7,8,0};
    currentState = v;
    misplacedCost();
    cost = gCost + hCost;
}

board::~board(){
}

int board::blankLocation(){
    int location;
    for(int i = 0; i < boardSize; i++){
        if(currentState.at(i) == 0){
            location = i;
        }
    }
    return location;
}

int board::misplacedCost(){
    if(UCS){
        return 0;
    }
    int heuristic = 0;
    for(int i = 0; i < boardSize-1; i++){ //check n-1 spots
        if(currentState.at(i) != i+1){
            if(currentState.at(i) != 0){
                heuristic++;
            }
        }

    }
    if(currentState.at(boardSize-1) != 0){
        heuristic++;
    }
    this->hCost = heuristic;
    return heuristic;
}

board* board::moveUp(){
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos > (width-1)){
        int swapVal = temp->currentState.at(blankPos - width);
        temp->currentState.at(blankPos - width) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->gCost = temp->parent->gCost + 1;
        if(temp->getVec() == goalState){
            temp->hCost = 0;
        }
        temp->misplacedCost();
        return temp;
    }
    else{
        return NULL;
    }
}

board* board::moveDown(){
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos < (width*(width-1))){
        int swapVal = temp->currentState.at(blankPos + width);
        temp->currentState.at(blankPos + width) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->gCost = temp->parent->gCost + 1;
        if(temp->getVec() == goalState){
            temp->hCost = 0;
        }
        temp->misplacedCost();
        return temp;
    }
    else{
        return NULL;
    }
}

board* board::moveLeft(){
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos%width != 0){
        int swapVal = temp->currentState.at(blankPos - 1);
        temp->currentState.at(blankPos - 1) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->gCost = temp->parent->gCost + 1;
        if(temp->getVec() == goalState){
            temp->hCost = 0;
        }
        temp->misplacedCost();
        return temp;
    }
    else{
        return NULL;
    }
}

board* board::moveRight(){
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if((blankPos+1)%width != 0){
        int swapVal = temp->currentState.at(blankPos + 1);
        temp->currentState.at(blankPos + 1) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->gCost = temp->parent->gCost + 1;
        if(temp->getVec() == goalState){
            temp->hCost = 0;
        }
        temp->misplacedCost();
        return temp;
    }
    else{
        return NULL;
    }
}

void board::print(){
    int width = ceil(sqrt(boardSize));
    for(unsigned i = 0; i < boardSize; i++){
        if(i % width == 0){
            cout << endl;
        }
        cout << currentState.at(i) << " ";
    }
    cout << endl << endl;
}

bool board::goalFound(){
    if(currentState == goalState){
        return true;
    }
    else{
        return false;
    }
}

board* board::getParent(){
    return this->parent;
}

vector<int> board::getVec(){
    return this->currentState;
}

void board::setVec(vector<int> v){
    this->currentState = v;
}