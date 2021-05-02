#include <iostream>
#include "board.h"

board::board(){ //default constructor 
    parent = NULL;
    boardSize = 9; //CHANGE IF YOU WANT TO CHANGE PUZZLE SIZE
    width = ceil(sqrt(boardSize));
    gCost = 0;
    hCost = 0;
    cost = 0;
    goalState = {1,2,3,4,5,6,7,8,0}; //CHANGE IF YOU WANT TO CHANGE PUZZLE SIZE
    currentState = {1,2,3,4,5,6,7,8,0}; // CHANGE IF YOU WANT TO CHANGE PUZZLE SIZE
    misplacedCost();

}

board::board(vector<int> v){//constructor with parameter to set board current state (vector)
    boardSize = 9; //CHANGE IF YOU WANT TO CHANGE PUZZLE SIZE
    width = ceil(sqrt(boardSize));
    gCost = 0;
    //hCost = 0;
    parent = NULL;
    goalState = {1,2,3,4,5,6,7,8,0}; //CHANGE IF YOU WANT TO CHANGE PUZZLE SIZE
    currentState = v;
    misplacedCost();
    cost = gCost + hCost;
}

board::~board(){
}

int board::blankLocation(){ //returns location of blank spot
    int location;
    for(int i = 0; i < boardSize; i++){
        if(currentState.at(i) == 0){
            location = i;
        }
    }
    return location;
}

double board::misplacedCost(){ //returns # of misplaced tiles and sets this->hCost and this->cost
    if(UCS && !euclidean){ //UCS heuristic
        this->hCost = 0;
        return 0;
    }
    else if(euclidean && !UCS){ //Euclidean Distance Algorithm
        double heuristic = 0;
        int x = 0;
        int y = 0;
        int currentX = 0;
        int correctX = 0;
        double currentY = 0;
        double correctY = 0;
        double result = 0;
        for(int i = 0; i < boardSize; i++){
            if(currentState.at(i) != 0 && currentState.at(i) != i+1){
                //FIND DISTANCE OF X
                if(currentState.at(i) % width == 0){
                    correctX = width;
                }
                else{
                    correctX = currentState.at(i) % width;
                }
                if((i+1)%width == 0){
                    currentX = width;
                }
                else{
                    currentX = (i+1)%width;
                }
                x = currentX - correctX;

                //FIND DISTANCE OF Y
                currentY = ceil((double(i+1))/double(width));
                correctY = ceil(double(currentState.at(i))/double(width));
                y = currentY - correctY;

                //Calculate euclidean
                x = abs(x);
                y = abs(y);

                result = sqrt(pow(x,2)+pow(y,2));
                heuristic += result;
            }
        }
        this->hCost = heuristic;
        this->cost = this->hCost + this->gCost;
        return heuristic;
    }
    else if(!UCS && !euclidean){ //Misplaced Tile Algorithm
        int heuristic = 0;
        for(int i = 0; i < boardSize-1; i++){ //check n-1 spots
            if(currentState.at(i) != i+1){
                if(currentState.at(i) != 0){
                    heuristic++;
                }
            }

        }
        if(currentState.at(boardSize-1) != 0){ //check n-th spot
            heuristic++;
        }
        this->hCost = heuristic;   //update costs
        this->cost = this->hCost + this->gCost;
        return heuristic;
    }

}

board* board::moveUp(){ //returns a board after operation, sets parent, then update cost
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos > (width-1)){
        int swapVal = temp->currentState.at(blankPos - width);
        temp->currentState.at(blankPos - width) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->boardSize = this->boardSize;
        temp->goalState = this->goalState;
        temp->width = this->width;
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

board* board::moveDown(){ //returns a board after operation, sets parent, then update cost
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos < (width*(width-1))){
        int swapVal = temp->currentState.at(blankPos + width);
        temp->currentState.at(blankPos + width) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->boardSize = this->boardSize;
        temp->goalState = this->goalState;
        temp->width = this->width;
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

board* board::moveLeft(){ //returns a board after operation, sets parent, then update cost
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if(blankPos%width != 0){
        int swapVal = temp->currentState.at(blankPos - 1);
        temp->currentState.at(blankPos - 1) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->boardSize = this->boardSize;
        temp->goalState = this->goalState;
        temp->width = this->width;
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

board* board::moveRight(){ //returns a board after operation, sets parent, then update cost
    board* temp = new board(this->currentState);
    int blankPos = blankLocation();
    if((blankPos+1)%width != 0){
        int swapVal = temp->currentState.at(blankPos + 1);
        temp->currentState.at(blankPos + 1) = 0;
        temp->currentState.at(blankPos) = swapVal;
        temp->parent = this;
        temp->boardSize = this->boardSize;
        temp->goalState = this->goalState;
        temp->width = this->width;
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

void board::print(){ //prints out the board
    int width = ceil(sqrt(boardSize));
    for(unsigned i = 0; i < boardSize; i++){
        if(i % width == 0){
            cout << endl;
        }
        cout << currentState.at(i) << " ";
    }
    cout << endl << endl;
}

void board::printGoal(){ //prints out the board
    int width = ceil(sqrt(boardSize));
    for(unsigned i = 0; i < boardSize; i++){
        if(i % width == 0){
            cout << endl;
        }
        cout << goalState.at(i) << " ";
    }
    cout << endl << endl;
}

bool board::goalFound(){ //return a bool if the board has reached its goal state
    if(currentState == goalState){
        return true;
    }
    else{
        return false;
    }
}

board* board::getParent(){ //helper function to return parent
    return this->parent;
}

vector<int> board::getVec(){ //helper function to return board's current state (vector)
    return this->currentState;
}

void board::setVec(vector<int> v){ //helper function to set's a boards current state (vector)
    this->currentState = v;
}

void board::setGoal(vector<int> v){ //helper function to set's a boards goal state (vector)
    this->goalState = v;
}