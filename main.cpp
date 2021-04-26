#include <iostream>
#include <queue>
#include "board.h"
#include "jstar.h"

using namespace std;

int main()
{
    /*cout << "main start" << endl;

    cout << "initializing board and problem" << endl;
    jStar* jstar = new jStar();
    vector<int> problem = {1,2,3,4,5,6,7,0,8};
    board* b1 = new board(problem);
    cout << "finished initializing" << endl;

    cout << "now calling solve()" << endl;
    board* solution = jstar->solve(b1);

    cout << "checking solution" << endl;
    if(solution != NULL){
        cout << "SOLUTION FOUND" << endl;
        solution->print();
    }
    else{
        cout << "NO SOLUTION FOUND" << endl;
    }*/
    
    vector<board*> vBoard;
    vector<int> problem = {1,2,3,4,5,6,7,0,8};
    board* b1 = new board(problem);
    vBoard.push_back(b1);
    vBoard.at(0)->print();
    vBoard.push_back(b1->moveLeft());
    vBoard.at(1)->print();


    /*board eightPuzzle;  //class object for hardcoded(default) puzzle
    int row = 3;
    int column = 3;

    int puzzleChoice;
    cout << "Welcome to jvo033 and dvega007 - 8 puzzle solver.\n"
         << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> puzzleChoice;
    cout << endl;

    if (puzzleChoice == 1)
    {
        eightPuzzle = board(); //Here will be the call for hardcoded example puzzle
    }
    else if (puzzleChoice == 2)
    {
        cout << "Enter your puzzle, use a zero to represent the blank.\n"
             << "Enter the first row, use space or tabs between numbers: ";
        cin >> row;
        cout << "Enter the second row, use space or tabs between numbers: ";
        cin >> row;
        cout << "Enter the third row, use space or tabs between numbers: ";
        cin >> row;

        cout << "Enter your choice of algorithm: \n";
    }
    else
    {
        cout << "That choice is not available, please try again!\n";
    }

    int algoChoice;

    switch(algoChoice){
        case 1:             //Uniform Cost Search

        case 2:             //A* with Misplaced Tile heuristic

        case 3:             //A* with Eucledian Distance heuristic

        default:
            cout << "That choice is not available, please try again!\n";
            return 1;
    }
*/
    return 0;

}