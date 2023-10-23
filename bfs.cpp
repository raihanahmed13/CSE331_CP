#include<bits/stdc++.h>
using namespace std;

class graph1 {
public:
    int arr[5][5] = { 0 };
    void addEdge(int i, int j) {
        arr[i][j] = 1;
        arr[j][i] = 1;
    }

    void bfs() {
        vector<bool> v(5, false);

        queue<int> q1;
        v[0] = true;
        q1.push(0);

        while (!q1.empty()) {
            int s = q1.front();

            cout << static_cast<char> ('A' + s) << " ";
            q1.pop();

            for (int i = 0;i < 5;i++) {
                if (arr[s][i] && !v[i]) {
                    v[i] = true;
                    q1.push(i);
                }
            }


        }

    }
};
int main() {

    graph1 g;
    g.addEdge(0, 1);  //A-B
    g.addEdge(0, 2);  //A-C
    g.addEdge(0, 3);  //A-D
    g.addEdge(1, 3);   //B-D
    g.addEdge(2, 3);   //C-D
    g.addEdge(3, 4);    //D-E
    g.addEdge(1, 4);   //B-E

    g.bfs();

}