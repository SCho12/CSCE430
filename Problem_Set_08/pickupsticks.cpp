#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
    vector<int> below; // Sticks that are below this stick
    int onTop = 0; // Number of sticks on top of this stick 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<node> graph(n+1);
    int pickup = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].below.push_back(b); 
        graph[b].onTop++; 
    }

    queue<int> q;
    for (int j = 1; j <= n; j++) {
        if (graph[j].onTop == 0) {
            q.push(j);
        }
    }

    vector<int> output;
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        output.push_back(idx);
        pickup++;

        for (int below : graph[idx].below) {
            graph[below].onTop--;
            if (graph[below].onTop == 0) {
                q.push(below);
            }
        }
    }

    if (pickup < n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int stick : output) {
            cout << stick << endl;
        }
    }

    return 0;
}
