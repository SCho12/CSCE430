#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<int> p; // Parents
vector<int> mh; // Max height

/*
How can we identify a union find problem?
 - Look for problems where things are joined in one direction
 - No intersections, but rather keep collecting things into a single set
 - They are disjoint sets, a pair of sets which does not have any common element
*/

// x is the set that we want
int findSet(int x){ 
    if (p[x] == x) return x;
    p[x] = findSet(p[x]); // This is the path compression!
    return p[x];
}

// Here is how you do it non-recursively
int findSet(int x){
    if (p[x] == x) return x;
    stack<int> pointersToUpdate;
    while (p[x] != x){
        pointersToUpdate.push(x);
        x = p[x];
    }
    
    int setNumber = x;
    
    while (!pointersToUpdate.empty()){
        p[pointersToUpdate.top()] = setNumber;
        pointersToUpdate.pop();
    }

    return setNumber;
}

void merge(int a, int b){
    int x, y;
    x = findSet(a);
    y = findSet(b);

    if (x == y) return; // there is no reason to merge!

    if (mh[x] > mh[y]){ // x has a height greater than y's
        p[y] = x;
    }
    else if (mh[x] < mh[y]){ // y has a height greater than x's
        p[x] = y;
    }
    else{ // They have the same height, so we can set either to be the parent and increment the height of the new parent
        p[x] = y;
        mh[y]++;
    }
}


int main(){
    p.resize(10);
    mh.resize(10, 1);
    for (int i = 0; i < 10; i++){
        p[i] = i; // everything will start out pointing to itself
    }

    string s; int a; int b;
    while (true){
        cin >> s;
        if (s == "F"){ // Find
            cin >> a;
            cout << findSet(a) << endl;
        }
        else if (s == "U"){ // union
            cin >> a >> b;
            merge(a, b);
        }
    }
}