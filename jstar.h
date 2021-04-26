#ifndef JSTAR_H
#define JSTAR_H

#include "board.h"
#include <set>
#include <queue>

using namespace std;

class jStar{
    public:
        jStar();
        ~jStar();
        int maxFrontierSize;
        board* root;
        board* goal;
        set<board*> explored;
        priority_queue<board*, vector<board*>, CompareCost> frontier;
        board* solve(board*);
        void printSolution();
};

#endif