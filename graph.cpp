#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        //direction=0 -> undirected
        //direction=1 -> directed

        //create an edge from u to v

        adj[u].push_back(v);

        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph g1;
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        g1.addEdge(u, v, 0); //creating undirected graph
    }

    g1.printAdj();

}