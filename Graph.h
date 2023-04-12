#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <iostream>
#include <list>
#include <set>

using namespace std;

template <class T>
class Graph{

private:
    map<T, int> value_list;
    map<T, int> visited;

public:
    Graph();
    void addVertex(T val, set<T> edges, int value);
    map<T, set<T>> adj_list;
    set<T> getNeighbours(T vertex);
    int getValue(T vertex);
    int getVisited(T vertex);
    void setVisited(T vertex, int value);
};

#endif