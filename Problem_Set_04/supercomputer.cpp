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
    int nbits, queries;
    cin >> nbits >> queries;

    FT tree(nbits);
    map<int, int> flips;
    char op;
    while(queries--) {
        cin >> op;
        if (op == 'F') {
            int index;
            cin >> index;
            if (flips[index] % 2 == 0) {
                tree.incr(index, 1);
                flips[index]++;
            } else {
                tree.incr(index, -1);
                flips[index]++;
            }
        } else if (op == 'C') {
            int first, last;
            cin >> first >> last;
            cout << tree.rsq(first, last) << endl;
        }
    }

}