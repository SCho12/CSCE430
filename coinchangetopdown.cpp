#include<bits/stdc++.h>
using namespace std;

#define MAXINT 1000000

vector<int> val;

int dp(int a, int b) {
    if (a == 0) return 0;
    if (b < 0) return MAXINT;
    if (a < 0) return MAXINT;
    static map<pair<int,int>, int> mydp;
    if (mydp.count(make_pair(a,b)) > 0) {
        return mydp[make_pair(a,b)];
    }
    int retval;
    retval = min(dp(a-val[b], b) + 1, dp(a, b - 1));
    mydp[make_pair(a,b)] = retval;
    return retval;
}



int main() {

    int numc;
    cin >> numc;
    val.resize(numc);
    int i, j, x;
    for (i = 0; i < numc; i++) {
        cin >> val[i];
    }

    int amt;
    cin >> amt;

    while (amt > 0) {
        cout << "The min number of coins for " << amt << " is " << dp(amt, numc - 1) << endl;
        cin >> amt;
    }






}