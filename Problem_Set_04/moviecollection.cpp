#include<bits/stdc++.h>
using namespace std;

inline int LSOne(const int x) {
    return x & (-x);
}

class FT {
    vector<long long> a;
    int n;

    public:
    FT(int x) {
        n = x;
        a.resize(x + 1, 0);

    }

    void incr(int elem, long long val) {
        while (elem <= n) {
            a[elem] += val;
            elem = elem + LSOne(elem);
        }
    }

    long long rsq(int elem) {
        long long summation = 0;
        while (elem > 0) {
            summation += a[elem];
            elem -= LSOne(elem);
        }
        return summation;
    }

    long long rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }
};

int main() {

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        FT tree(500000);
        int movies, requests;
        cin >> movies >> requests;
        int count = 1;
        map<int, int> positions;

        for (int j = 1; j <= movies; j++) {
            tree.incr(j, 1);
            positions[j] = movies - j + 1;
        }

        int pick;
        for (int k = movies + 1; k <= movies + requests; k++) {
            cin >> pick;
            cout << movies - tree.rsq(positions[pick]) << " ";
            tree.incr(positions[pick], -1);
            tree.incr(k, 1);
            positions[pick] = k;
        }

        cout << endl;
    }
}