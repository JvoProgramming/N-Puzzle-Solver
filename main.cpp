#include <iostream>
#include <queue>
#include "board.h"
#include "jstar.h"
#include <typeinfo>
#include <string>
#include <sstream>

using namespace std;

bool UCS;
bool manhattan;

int main()
{
    board* gameBoard = new board();
    jStar* jstar = new jStar();
    board* solution = NULL;
    vector<int> problem = {};

    int puzzleChoice;
    cout << "Welcome to jvo033 and dvega007 - n puzzle solver.\n"
         << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> puzzleChoice;

    if (puzzleChoice == 1)
    {
        problem = {0,1,2,4,5,3,7,8,6};
    }
    else if (puzzleChoice == 2)
    {
        cout << "Enter puzzle size: ";
        int puzzleSize;
        cin >> puzzleSize;
        fflush(stdin);
        gameBoard->boardSize = puzzleSize+1;
        gameBoard->width = ceil(sqrt(gameBoard->boardSize));
        cout << "Enter game state, from top-left to right-bottom, " << gameBoard->boardSize << " characters, e.g. \"0 1 2 3 4 5 6 7 8\" " << endl;
        string userInput;
        fflush(stdin);
        getline(cin, userInput);

        stringstream stream(userInput); //parse user input
        int num;
        while(stream >> num){
            problem.push_back(num);
        }
        cout << endl;
    }
    else
    {
        cout << "That choice is not available, please try again!\n";
    }
    cout << "Puzzle Set! Please choose an algorithm: " << endl << "(1) Uniform Cost Search (UCS)" << endl << "(2) A* with Misplaced Tile heuristic" << endl << "(3) A* with Euclidean Distance heuristic" << endl << "Enter an option: ";

    int algoChoice;
    cin >> algoChoice;
    cout << algoChoice << endl;


    switch(algoChoice){
        case 1:             //Uniform Cost Search
            cout << "Performing uniform cost search... " << endl;
            gameBoard->setVec(problem);
            UCS = true;
            manhattan = false;
            solution = jstar->solve(gameBoard);

            if(solution != NULL){
                cout << "Max queue size: " << jstar->maxQueueSize << endl;
                cout << "Max explored size: " << jstar->exploredSize << endl;
                cout << "Number of nodes expanded: " << jstar->expandSize << endl;
                cout << "NOW PRINTING SOLUTION: " << endl;
                jstar->printSolution(solution);
            }
            else{
                cout << "NO SOLUTION FOUND" << endl;
            }
            break;
        case 2:             //A* with Misplaced Tile heuristic
            cout << "Performing A* search with the Misplaced Tile heuristic" << endl;
            
            gameBoard->setVec(problem);
            UCS = false;
            manhattan = false;
            solution = jstar->solve(gameBoard);

            if(solution != NULL){
                cout << "Max queue size: " << jstar->maxQueueSize << endl;
                cout << "Max explored size: " << jstar->exploredSize << endl;
                cout << "Number of nodes expanded: " << jstar->expandSize << endl;
                cout << "NOW PRINTING SOLUTION: " << endl;
                jstar->printSolution(solution);
            }
            else{
                cout << "NO SOLUTION FOUND" << endl;
            }
            break;
        case 3:             //A* with Euclidian Distance heuristic
            cout << "Performing A* search with the Euclidian Distance heuristic" << endl;
            gameBoard->setVec(problem);
            UCS = false;
            manhattan = true;
            solution = jstar->solve(gameBoard);

            if(solution != NULL){
                cout << "Max queue size: " << jstar->maxQueueSize << endl;
                cout << "Max explored size: " << jstar->exploredSize << endl;
                cout << "Number of nodes expanded: " << jstar->expandSize << endl;
                cout << "NOW PRINTING SOLUTION: " << endl;
                jstar->printSolution(solution);
            }
            else{
                cout << "NO SOLUTION FOUND" << endl;
            }
            break;
        default:
            cout << "That choice is not available, please try again!\n";
            return 1;
    }
    return 0;

}
