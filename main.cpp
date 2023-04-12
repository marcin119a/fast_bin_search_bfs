#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "check.cpp"
#include "bfs.cpp"

using namespace std;

const int inf = 1000001000;
typedef std::pair<int, int> pii;


Graph<pair<int, int>> generateGraphFromLattice(int size, vector<vector<int>> data)
{
    Graph<pair<int, int>> graph;

    const int offsetX[] = {-1, 0, 0, 1};
    const int offsetY[] = {0, 1, -1, 0};

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            for (int shift = 0; shift < 4; ++shift) {
                int posY = y + offsetY[shift];
                int posX = x + offsetX[shift];
                if (posY >= 0 && posX >= 0 && posY < size && posX < size) {
                        graph.addVertex(pair(x, y), {pair(posX, posY)}, data[x][y]);
                    }
                }
            }
    }


    return graph;
}



int main(int argc, char** argv){
    int size, required;
    vector<vector<int>> data(1010, vector<int> (1010));


    scanf("%d %d", &size, &required);
    int minVal = inf, maxVal = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            scanf("%d", &data[y][x]);
            minVal = std::min(minVal, data[y][x]);
            maxVal = std::max(maxVal, data[y][x]);
        }
    }
    Graph<pair<int, int>> graph1 = generateGraphFromLattice(size, data);
    cout << graph1;

    int start = binary_search(minVal, maxVal, graph1, required);

    printf("%d\n", start);
}