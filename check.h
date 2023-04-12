#ifndef CHECK_H
#define CHECK_H
#include "Graph.h"
#include "bfs.h"

template <class T>
bool check(int limit, Graph<T> graph, int required);

template <class T>
int binary_search(int minVal, int maxVal, Graph<T> graph, int required);


#endif
