#include "jstar.h"

jStar::jStar(){
    this->root = NULL;
    maxQueueSize = 0;
    exploredSize = 0;
}

jStar::~jStar(){
}

board* jStar::solve(board* b){
    //INITIALIZE COUNTERS
    maxQueueSize = 0;
    exploredSize = 0;
    expandSize = 0;

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
        cout << "The best state to expand with g(n) = " << b->gCost << " and h(n) = " << b->hCost << " is..." << endl;
        b->print();
        frontier.pop();
        //IF STATE IS GOAL, RETURN IT
        if(b->goalFound()){
            cout << "Goal!!!" << endl << endl;
            return b;
        }
        //ELSE INSERT INTO EXPLORED SET
        explored.insert(b->getVec());
        exploredSize = explored.size();
        //THEN EXPAND ITS CHILDREN
        if(b->moveLeft() != NULL && !(explored.find(b->moveLeft()->getVec()) != explored.end()) && !(frontierSet.find(b->moveLeft()->getVec()) != frontierSet.end())){
            frontier.push(b->moveLeft());
            frontierSet.insert(b->moveLeft()->getVec());
            expandSize++;
        }
        if(b->moveRight() != NULL && !(explored.find(b->moveRight()->getVec()) != explored.end()) && !(frontierSet.find(b->moveRight()->getVec()) != frontierSet.end())){
            frontier.push(b->moveRight());
            frontierSet.insert(b->moveRight()->getVec());
            expandSize++;
        }
        if(b->moveUp() != NULL && !(explored.find(b->moveUp()->getVec()) != explored.end()) && !(frontierSet.find(b->moveUp()->getVec()) != frontierSet.end())){
            frontier.push(b->moveUp());
            frontierSet.insert(b->moveUp()->getVec());
            expandSize++;
        }
        if(b->moveDown() != NULL && !(explored.find(b->moveDown()->getVec()) != explored.end()) && !(frontierSet.find(b->moveDown()->getVec()) != frontierSet.end())){
            frontier.push(b->moveDown());
            frontierSet.insert(b->moveDown()->getVec());
            expandSize++;
        }
    }
    //CANNOT FIND A GOAL, RETURN NULL
    return NULL;
}

void jStar::printSolution(board* goalNode){
    cout << "PRINTING SOLUTION: " << endl;
    vector<board*> traverseVec;
    board* curr = goalNode;
    while(curr != NULL){
        traverseVec.push_back(curr);
        curr = curr->getParent();
    }
    for(unsigned i = traverseVec.size()-1; i > 0; i--){
        traverseVec.at(i)->print();
    }
    goalNode->print();
}