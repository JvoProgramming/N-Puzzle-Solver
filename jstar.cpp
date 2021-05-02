#include "jstar.h"

jStar::jStar(){
    this->root = NULL;
    maxQueueSize = 0;
    exploredSize = 0;
    expandSize = 0;
}

jStar::~jStar(){
}

board* jStar::solve(board* b){
    //INITIALIZE COUNTERS
    maxQueueSize = 0;
    exploredSize = 0;
    expandSize = 0;

    board* goalNode = NULL;
    root = b;
    cout << "Expanding state";
    root->print();
    //INITALIZE FRONTIER USING INITIAL STATE OF PROBLEM
    frontier.push(b);
    frontierSet.insert(b->getVec());
    explored.clear();
    frontierSet.clear();
    //LOOP UNTIL FRONTIER EMPTY OR GOAL STATE FOUND
    while(!frontier.empty()){
        if(frontier.size() > maxQueueSize){
            maxQueueSize = frontier.size();
        }
        b = frontier.top();
        if(b->gCost != 0){
            cout << "The best state to expand with f(n) = " << b->cost << ", " << "g(n) = " << b->gCost << ", and h(n) = " << b->hCost << " is..." << endl;
            b->print();
        }
        frontier.pop();
        //IF STATE IS GOAL, RETURN IT
        if(goalNode != NULL && (goalNode->cost <= frontier.top()->cost)){ //CHECK IF IT IS ACTUALLY THE GOAL NODE
            cout << "FOUND GOAL!" << endl;
            return goalNode;
        }
        //ELSE INSERT INTO EXPLORED SET
        explored.insert(b->getVec());
        exploredSize = explored.size();
        //THEN EXPAND ITS CHILDREN
        if(b->moveLeft() != NULL && !(explored.find(b->moveLeft()->getVec()) != explored.end()) && !(frontierSet.find(b->moveLeft()->getVec()) != frontierSet.end())){
            frontier.push(b->moveLeft());
            frontierSet.insert(b->moveLeft()->getVec());
            expandSize++;
            if(b->moveLeft()->goalFound()){
                goalNode = b->moveLeft();
            }
        }
        if(b->moveRight() != NULL && !(explored.find(b->moveRight()->getVec()) != explored.end()) && !(frontierSet.find(b->moveRight()->getVec()) != frontierSet.end())){
            frontier.push(b->moveRight());
            frontierSet.insert(b->moveRight()->getVec());
            expandSize++;
            if(b->moveRight()->goalFound()){
                goalNode = b->moveRight();
            }
        }
        if(b->moveUp() != NULL && !(explored.find(b->moveUp()->getVec()) != explored.end()) && !(frontierSet.find(b->moveUp()->getVec()) != frontierSet.end())){
            frontier.push(b->moveUp());
            frontierSet.insert(b->moveUp()->getVec());
            expandSize++;
            if(b->moveUp()->goalFound()){
                goalNode = b->moveUp();
            }
        }
        if(b->moveDown() != NULL && !(explored.find(b->moveDown()->getVec()) != explored.end()) && !(frontierSet.find(b->moveDown()->getVec()) != frontierSet.end())){
            frontier.push(b->moveDown());
            frontierSet.insert(b->moveDown()->getVec());
            expandSize++;
            if(b->moveDown()->goalFound()){
                goalNode = b->moveDown();
            }
        }
    }
    //CANNOT FIND A GOAL, RETURN NULL
    return NULL;
}

void jStar::printSolution(board* goalNode){
    int moves = 0;
    vector<board*> traverseVec;
    board* curr = goalNode;
    while(curr != NULL){
        traverseVec.push_back(curr);
        curr = curr->getParent();
    }
    for(unsigned i = traverseVec.size()-1; i > 0; i--){
        traverseVec.at(i)->print();
        moves++;
    }
    goalNode->print();
    cout << "Moves: " << moves << endl;
}