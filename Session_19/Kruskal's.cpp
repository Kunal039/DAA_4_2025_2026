#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    subsets[yroot].parent = xroot;
}

void kruskalMST(Edge edges[], int V, int E) {
    Subset subsets[V];
    for (int v = 0; v < V; v++)
        subsets[v].parent = v;

    cout << "Edge \tWeight\n";

    for (int i = 0; i < E; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            cout << edges[i].src << " - " << edges[i].dest
                 << "\t" << edges[i].weight << endl;
            Union(subsets, x, y);
        }
    }
}

int main() {
    int V = 4;
    int E = 5;

    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Edges must be sorted by weight (manually here)
    kruskalMST(edges, V, E);

    return 0;
}