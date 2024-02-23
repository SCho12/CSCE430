#include<bits/stdc++.h>
using namespace std;

vector<int> p; 
vector<int> mh; 
vector<int> set_sizes;

int findSet(int x){ 
    if (p[x] == x) return x;
    p[x] = findSet(p[x]); 
    return p[x];
}

void merge(int a, int b){
    int x, y;
    x = findSet(a);
    y = findSet(b);

    if (x == y) return; 

    if (mh[x] > mh[y]){ 
        p[y] = x;
        set_sizes[x] += set_sizes[y];
    }
    else if (mh[x] < mh[y]){ 
        p[x] = y;
        set_sizes[y] += set_sizes[x];

    }
    else{ 
        p[x] = y;
        mh[y]++;
        set_sizes[y] += set_sizes[x];
    }
}

int main() {
    int recipes;
    cin >> recipes;

    for (int i = 0; i < 500000; i++) {
        p.push_back(i);
        mh.push_back(0);
        set_sizes.push_back(1);
    }






}