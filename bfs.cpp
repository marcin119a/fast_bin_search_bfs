#include <iostream>
#include <queue>
#include "bfs.h"
#include "Graph.h"

typedef std::pair<int, int> pii;


template <class T>
int bfs(T vertex, Graph<T> graph, int limit){
    // queue for bfs and set for checking if nodes have been visited
    queue<T> myQueue;
    set<T> visited;
    int ret = 0;

    //enqueue the vertex
    myQueue.push(vertex);
    //set the limit for vertex
    graph.setVisited(vertex,limit);

    //while there are still nodes to be visited
    while (!myQueue.empty()){
        //get the node to be searched next and add it to visited
        T curr = myQueue.front(); myQueue.pop();
        ++ret;

        visited.insert(curr);
        cout << "Visiting node:" << curr << endl;

        //add all the nodes neighbours to the queue
        for (T elem: graph.getNeighbours(curr)){
            typename set<T> :: iterator it = visited.find(elem);

            //if the neighbours of the current node have been visitted then dont add to queue
            if (graph.getVisited(vertex) != limit && graph.getValue(vertex) <= limit){
                    if (it == visited.end()){
                        myQueue.push(elem);
                    }
            }
        }
    }
    return ret;
}