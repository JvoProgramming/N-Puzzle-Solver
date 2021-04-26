//#include <studio.h>
#include <queue>
#include <map>
#include <list>
#include "board.h"

class Astar{
    private:
        int node;
        int maxNode;
        priority_queue<board*, vector<board*>, pq> frontier;
        vector<board*> search;
        board* root;

    public:
        Astar();
        ~Astar();
        Astar(board*);
        priority_queue<> ;

        void uniformCS();
        void misplacedTS();
        void eucledianDS();
};
