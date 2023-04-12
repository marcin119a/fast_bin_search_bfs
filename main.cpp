#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "check.cpp"
#include "bfs.cpp"

using namespace std;



int main(){
    //initialize graph
    Graph<int> graph1;

    //create simple tree
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    set<int> connections1 = {2, 3};
    set<int> connections2 = {4, 5};
    set<int> connections3 = {6, 7};

    graph1.addVertex(1, connections1, 1);
    graph1.addVertex(2, connections2, 2);
    graph1.addVertex(3, connections3, 3);
    graph1.addVertex(4, connections1, 4);
    graph1.addVertex(5, connections2, 5);

    // perfrom BFS


    int minValue = 0; int maxValue = 5;
    int required = 2;
    cout << graph1;

    int a = binary_search(minValue, maxValue, graph1, required);
    cout << a;

    return 0;
}