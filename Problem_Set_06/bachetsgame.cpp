#include<bits/stdc++.h>
using namespace std;

int main() {
    int stones;
    while (cin >> stones) {
        int num_moves;
        cin >> num_moves;

        int i, j;
        vector<int> moves;
        moves.resize(num_moves);

        for (i = 0; i < num_moves; i++) {
            cin >> moves[i];
        }

        sort(moves.begin(), moves.end());

        vector<bool> DP;
        DP.resize(stones + 1);
        DP[0] = false;
        DP[1] = true;

        for (i = 2; i <= stones; i++) {
            DP[i] = false;
            for (j = 0; j < moves.size(); j++) {
                if (i >= moves[j] && DP[i - moves[j]] == false) {
                    DP[i] = true;
                    break;
                }
            }
        }

        if (DP[stones] == true) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }
}