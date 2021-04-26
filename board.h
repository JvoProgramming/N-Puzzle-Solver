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

        //Functions for UCS, Misplace and Eucledian distance
        int f();
        int g();
        int h();

};

class Tree{
    private:
        int node;
        int maxNode;
        priority_queue<board*, vector<board*> > frontier;
        vector<board*> search;
        board* root;

    public:
        Tree();
        ~Tree();
        Tree(board*);
        priority_queue<> ;

};