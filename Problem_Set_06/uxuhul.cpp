#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    map<int, string> choices = {{0, "NNN"}, {1, "NNY"}, {2, "NYN"}, {3, "NYY"}, {4, "YNN"}, {5, "YNY"}, {6, "YYN"}, {7, "YYY"}};
    int i, j, k;

    for (i = 0; i < cases; i++) {
        int priests;
        cin >> priests;

        vector<vector<int>> preferences(priests, vector<int>(8));

        for (j = 0; j < priests; j++) {
            for (k = 0; k < 8; k++) {
                cin >> preferences[j][k];
            }
        }

        vector<vector<int>> dp(priests, vector<int>(8));

        int base = priests - 1;
        for (int a = 0; a < 8; a++) {
            int choice1 = a ^ 4;
            int choice2 = a ^ 2;
            int choice3 = a ^ 1;

            // cout << "choice 1: " << choice1 << endl;
            // cout << "choice 2: " << choice2 << endl;
            // cout << "choice 3: " << choice3 << endl;

            int pref1 = preferences[base][choice1];
            int pref2 = preferences[base][choice2];
            int pref3 = preferences[base][choice3];

            int most_pref;
            most_pref = min(pref1, pref2);
            most_pref = min(most_pref, pref3);

            if (most_pref == pref1) {
                dp[base][a] = choice1;
            } else if (most_pref == pref2) {
                dp[base][a] = choice2;
            } else if (most_pref == pref3) {
                dp[base][a] = choice3;
            }
        }

        for (j = priests - 2; j >= 0; j--) {
            for (k = 0; k < 8; k++) {
                int choice1 = k ^ 4;
                int choice2 = k ^ 2;
                int choice3 = k ^ 1;

                //cout << "k: " << k << endl;
                //cout << "choice 1: " << choice1 << endl;
                //cout << "choice 2: " << choice2 << endl;
                //cout << "choice 3: " << choice3 << endl;

                int subchoice1 = dp[j + 1][choice1];
                int subchoice2 = dp[j + 1][choice2];
                int subchoice3 = dp[j + 1][choice3];


                //cout << "line 65" << endl;
                int pref1 = preferences[j][subchoice1];
                int pref2 = preferences[j][subchoice2];
                int pref3 = preferences[j][subchoice3];
                //cout << "line 69" << endl;

                int most_pref;
                most_pref = min(pref1, pref2);
                most_pref = min(most_pref, pref3);

                if (most_pref == pref1) {
                    dp[j][k] = subchoice1;
                } else if (most_pref == pref2) {
                    dp[j][k] = subchoice2;
                } else if (most_pref == pref3) {
                    dp[j][k] = subchoice3;
                }
            }
        }

        cout << choices[dp[0][0]] << endl;
    }
}