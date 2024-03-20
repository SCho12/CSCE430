#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main() {
    int n, k, i, j, a, b, w; // nodes, edges, iterators
    cin >> n;
    vector<vector<int> > v(n+1);
    for (i = 1; i <= n; i++) {
        // read in values per node
        // cin >> v[i].value;
        v[i].resize(n + 1, -1);
    }
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> a >> b >> w;
        v[a][b] = w;
        // Skip next line if directed graph
        v[b][a] = w;
    }

    // BFS 
    vector<int> value(n+1,-1);
    value[1] = 1;
    queue<int> q;
    q.push(1);
    int time = 0;
    while(!q.empty()) {
        a = q.front();
        q.pop();
        time++;
        cout << "Encoutered node " << a << " at time " << time << endl;
        for (b = 1; b <= n; b++) {
            if (v[a][b] != -1 && value[b] == -1) {
                value[b] = value[a] + 1;
                q.push(b);
            }
        }
    }

    for (i = 1; i <= n; i++) {
        cout << "The distance of node " << i << " is " << value[i] << endl;
    }
}