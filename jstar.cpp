#include "jstar.h"

jStar::jStar(){
    this->root = NULL;
}

jStar::~jStar(){
}

board* jStar::solve(board* b){
    cout << "entering jstar solve()..." << endl;
    root = b;
    root->print();
    //INITALIZE FRONTIER USING INITIAL STATE OF PROBLEM
    frontier.push(b);
    explored.clear();
    //LOOP UNTIL FRONTIER EMPTY OR GOAL STATE FOUND
    while(!frontier.empty()){
        b = frontier.top();
        frontier.pop();
        //IF STATE IS GOAL, RETURN IT
        if(b->goalFound()){
            return b;
        }
        //ELSE INSERT INTO EXPLORED SET
        explored.insert(b);
        //THEN EXPAND ITS CHILDREN
        // -------- IF STATEMENT NEEDS TO CHECK FRONTIER TOO (implement later) ----------
        if(b->moveLeft() != NULL && !(explored.find(b) != explored.end())){
            frontier.push(b->moveLeft());
        }
        if(b->moveRight() != NULL && !(explored.find(b) != explored.end())){
            frontier.push(b->moveRight());
        }
        if(b->moveUp() != NULL && !(explored.find(b) != explored.end())){
            frontier.push(b->moveUp());
        }
        if(b->moveDown() != NULL && !(explored.find(b) != explored.end())){
            frontier.push(b->moveDown());
        }
    }
    //CANNOT FIND A GOAL, RETURN NULL
    return NULL;
}