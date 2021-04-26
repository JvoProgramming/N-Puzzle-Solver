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
        explored.insert(b->getVec());
        //THEN EXPAND ITS CHILDREN
        // -------- IF STATEMENT NEEDS TO CHECK FRONTIER TOO (implement later) ----------
        if(b->moveLeft() != NULL && !(explored.find(b->moveLeft()->getVec()) != explored.end())){
            frontier.push(b->moveLeft());
            cout << "moved left" << endl;
            b->moveLeft()->print();
        }
        if(b->moveRight() != NULL && !(explored.find(b->moveRight()->getVec()) != explored.end())){
            frontier.push(b->moveRight());
            cout << "moved right" << endl;
            b->moveRight()->print();
        }
        if(b->moveUp() != NULL && !(explored.find(b->moveUp()->getVec()) != explored.end())){
            frontier.push(b->moveUp());
            cout << "moved up" << endl;
            b->moveUp()->print();
        }
        if(b->moveDown() != NULL && !(explored.find(b->moveDown()->getVec()) != explored.end())){
            frontier.push(b->moveDown());
            cout << "moved down" << endl;
            b->moveDown()->print();
        }
    }
    //CANNOT FIND A GOAL, RETURN NULL
    return NULL;
}