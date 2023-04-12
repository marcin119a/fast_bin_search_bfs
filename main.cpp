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
    set<int> connections1 = {2, 3, 4};
    set<int> connections2 = {5, 6};
    set<int> connections3 = {7, 8};
    set<int> connections4 = {9, 10};
    set<int> connections5 = {11, 12};

    graph1.addVertex(1, connections1, 10);
    graph1.addVertex(2, connections2, 5);
    graph1.addVertex(3, connections3, 5);
    graph1.addVertex(5, connections4, 5);
    graph1.addVertex(5, connections5, 5);


    // perfrom BFS


    int minValue = 0; int maxValue = 10;
    int required = 2;
    cout << graph1;

    int a = binary_search(minValue, maxValue, graph1, required);
    cout << a;

    return 0;
}