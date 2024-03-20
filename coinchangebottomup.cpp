#include<vector>
#include<iostream>
using namespace std;

#define MAXINT 1000000

vector<int> val;

int main() {

    int numc;
    cin >> numc;
    val.resize(numc);
    int i, j, x;
    for (i = 0; i < numc; i++) {
        cin >> val[i];
    }

    int maxamt = 10000000 / numc;
    vector<vector<int> > dp(maxamt+1);
    for (i = 0; i <= maxamt; i++) {
        dp[i].resize(numc);
    }

    for (j = 0; j < numc; j++) dp[0][j] = 0;
    for (i = 1; i <= maxamt; i++) {
        for(j = 0; j < numc; j++) {
            int minval = MAXINT;
            if (i - val[j] >= 0) minval = min(minval, dp[i-val[j]][j] + 1);
            if (j > 0) minval = min(minval, dp[i][j-1]);
            dp[i][j] = minval;
        }
    }

    int amt;
    cin >> amt;
  
    while (amt > 0) {
        if (amt > maxamt) {
            cout << "Too big!" << endl;
        } else {
            cout << "The min number of coins for " << amt << " is " << dp[amt][numc - 1] << endl;
            cin >> amt;
        }
    }
}