#include <iostream>
#include "Graph.h"

using namespace std;

template <class T>
bool check(int limit, Graph<T> graph, int required)
{
    int found = 0;
    for (typename map<T, set<T>>::const_iterator it = graph.adj_list.begin(), end = graph.adj_list.end(); it != end;++it){

        if (graph.getVisited(it->first) != limit && graph.getValue(it->first) <= limit)
            {
                found = std::max(found, bfs(it->first, graph, limit));
            }

    }

    return (found >= required);
}

template <class T>
int binary_search(int minVal, int maxVal, Graph<T> graph, int required){
    int start = minVal, end = maxVal;
    while (start != end)
    {
        int mid = (start + end) / 2;
        if (check(mid, graph, required))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}