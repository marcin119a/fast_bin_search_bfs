#include <iostream>
#include <queue>
#include "Graph.h"

typedef std::pair<int, int> pii;


template <class T>
void bfs(T vertex, Graph<T> graph){
    // queue for bfs and set for checking if nodes have been visited
    queue<T> myQueue;
    set<T> visited;

    //enqueue the vertex
    myQueue.push(vertex);

    //while there are still nodes to be visited
    while (!myQueue.empty()){

        //get the node to be searched next and add it to visited
        T curr = myQueue.front();
        myQueue.pop();
        visited.insert(curr);
        cout << "Visiting node:" << curr << endl;

        //add all the nodes neighbours to the queue
        for (T elem: graph.getNeighbours(curr)){
            typename set<T> :: iterator it = visited.find(elem);

            //if the neighbours of the current node have been visitted then dont add to queue
            if (it == visited.end()){
                myQueue.push(elem);
            }
        }
    }
}