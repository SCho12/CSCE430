#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct node {
    int value; // if we will store a value per node
    vector<int> adj;
    vector<int> weight;
}; 

int main() {
    int n, k, i, j, a, b, w; // nodes, edges, iterators
    cin >> n;
    vector<node> v(n+1);
    for (i = 1; i <= n; i++) {
        // read in values per node
        // cin >> v[i].value;
    }
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> a >> b >> w;
        v[a].adj.push_back(b);
        v[a].weight.push_back(w);
        // Skip these next two if it is a directed graph
        v[b].adj.push_back(a);
        v[b].weight.push_back(w);
    }

    // BFS 
    for (i=1; i <= n; i++) v[i].value = -1;
    v[1].value = 1;
    queue<int> q;
    q.push(1);
    int time = 0;
    while(!q.empty()) {
        a = q.front();
        q.pop();
        time++;
        cout << "Encoutered node " << a << " at time " << time << endl;
        for (i = 0; i < v[a].adj.size(); i++) {
            b = v[a].adj[i];
            if (v[b].value == -1) {
                v[b].value = v[a].value + 1;
                q.push(b);
            }

        }
    }

    for (i = 1; i <= n; i++) {
        cout << "The distance of node " << i << " is " << v[i].value << endl;
    }
}