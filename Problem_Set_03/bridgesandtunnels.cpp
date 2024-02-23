#include<bits/stdc++.h>
using namespace std;

map<string, string> parent;
map<string, int> setSize;


string find(string x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void merge(string x, string y) {
    string rootX = find(x);
    string rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX; 
        setSize[rootX] += setSize[rootY]; 
    }
}

int main() {
    int bridges;
    cin >> bridges;

    for (int i = 0; i < bridges; ++i) {
        string building1, building2;
        cin >> building1 >> building2;

        if (parent.find(building1) == parent.end()) {
            parent[building1] = building1;
            setSize[building1] = 1;
        }
        if (parent.find(building2) == parent.end()) {
            parent[building2] = building2;
            setSize[building2] = 1;
        }

        merge(building1, building2);
        cout << setSize[find(building1)] << endl;
    }
}