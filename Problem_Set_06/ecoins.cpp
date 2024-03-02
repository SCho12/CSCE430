#include<bits/stdc++.h>
using namespace std;

#define MAXINT 300000

int main() {
    int problems;
    cin >> problems;

    while (problems--) {
        int num_coins, emod;
        cin >> num_coins >> emod;

        vector<int> conventional(num_coins), infotech(num_coins);
        for (int i = 0; i < num_coins; i++) {
            cin >> conventional[i] >> infotech[i];
        }

        vector<vector<int>> dp(emod + 1, vector<int>(emod + 1, MAXINT));
        dp[0][0] = 0;

        for (int k = 0; k < num_coins; k++) {
            for (int i = 0; i + conventional[k] <= emod; i++) {
                for (int j = 0; j + infotech[k] <= emod; j++) {
                    if (dp[i][j] != MAXINT) {
                        dp[i + conventional[k]][j + infotech[k]] = min(dp[i + conventional[k]][j + infotech[k]], dp[i][j] + 1);
                    }
                }
            }
        }

        int minCoins = MAXINT;
        for (int i = 0; i <= emod; i++) {
            for (int j = 0; j <= emod; j++) {
                if (i * i + j * j == emod * emod && dp[i][j] < minCoins) {
                    minCoins = dp[i][j];
                }
            }
        }

        if (minCoins == MAXINT) {
            cout << "not possible\n";
        } else {
            cout << minCoins << "\n";
        }
    }

    return 0;
}
