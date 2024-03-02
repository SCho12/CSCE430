#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> maxheight;
vector<int> money;

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        p[x] = find(p[x]);
        return p[x];
    }
}

void merge(int x, int y) {
    int a, b;
    a = find(x);
    b = find(y);
    if (a == b) return;
    if (maxheight[a] == maxheight[b]) {
        p[b] = a;
        maxheight[a]++;
        money[a] += money[b];
        money[b] = 0;
    } else if (maxheight[a] > maxheight[b]) {
        p[b] = a;
        maxheight[a]++;
        money[a] += money[b];
        money[b] = 0;
    } else {
        p[a] = b;
        money[b] += money[a];
        money[a] = 0;
    }
}


int main() {
    int friends, friendships;
    cin >> friends >> friendships;

    p.resize(friends);
    maxheight.resize(friends);
    money.resize(friends);

    for (int i = 0; i < friends; i++) {
        p[i] = i;
        maxheight[i] = 1;
    }

    for (int j = 0; j < friends; j++) {
        int temp;
        cin >> temp;
        money[j] = temp;
    }

    for (int k = 0; k < friendships; k++) {
        int friend1, friend2;
        cin >> friend1 >> friend2;
        merge(friend1, friend2);
    }

    for (int p = 0; p < money.size(); p++) {
        if (money[p] != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << "POSSIBLE" << endl;
    return 0;
}