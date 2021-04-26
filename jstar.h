#include "board.h"
#include <set>
#include <queue>

using namespace std;

class jStar{
    public:
        set<vector<int>> explored;
        priority_queue<int, vector<int>, greater<int>> pq;
        board* solve(board*);
};