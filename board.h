#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int boardSize = 9;
const int width = ceil(sqrt(boardSize));

class board{
    private:
        vector<int> initialState;   //vector<vector<int>> for passing (x,y) to matrix board
        vector<int> currentState;
        vector<int> goalState;
        
    public:
        board();
        board(vector<int> v);
        ~board();
        board* parent;
        int cost;
        int hCost;
        int gCost;
        int blankLocation();
        board* moveUp();
        board* moveDown();
        board* moveLeft();
        board* moveRight();
        bool goalFound();
        int misplacedCost();
        void print();
        board* getParent();
        vector<int> getVec();
        void setVec(vector<int>);
        
        //Functions for UCS, Misplace and Eucledian distance
        int f();
        int g();
        int h();

};

struct CompareCost{
    bool operator()(board* const  b1, board* const b2){
        return b1->cost > b2->cost;
    }
};

#endif