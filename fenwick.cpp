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
    int n, q;
    scanf("%d %d\n", &n, &q);
    FT mytree(n);
    int a, b;
    char c;
    while(q--) {
        scanf("%c", &c);
        if (c == '+') {
            scanf("%d %d\n", &a, &b);
            mytree.incr(a+1, b);
        } else {
            scanf("%d\n", &a);
            printf("%lld\n", mytree.rsq(a));
        }
    }
 
}