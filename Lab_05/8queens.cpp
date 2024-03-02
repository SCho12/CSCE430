#include<bits/stdc++.h>
using namespace std;

int main() {

    char board[8][8];
    int queen_total = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp;
            if (temp == '*') {
                queen_total++;
            }
        }
    }

    if (queen_total == 8) {
        for (int a = 0; a < 8; a++) {
            int queen_row = 0;
            for (int b = 0; b < 8; b++) {
                if (board[a][b] == '*') {
                    queen_row++;
                }
            }
            if (queen_row > 1) {
                cout << "invalid" << endl;
                return 0;
            }
        }

        for (int p = 0; p < 8; p++) {
            int queen_col = 0;
            for (int q = 0; q < 8; q++) {
                if (board[q][p] == '*') {
                    queen_col++;
                }
            }
            if (queen_col > 1) {
                cout << "invalid" << endl;
                return 0;
            }
        }

        int queen_diag = 0;
        for (int k = -7; k <= 7; k++) {
            queen_diag = 0;
            for (int i = 0; i < 8; i++) {
                int j = i + k;
                if (j >= 0 && j < 8) {
                    if (board[i][j] == '*') {
                        queen_diag++;
                    }
                }
            }
            if (queen_diag > 1) {
                cout << "invalid" << endl;
                return 0;
            }
        }

        for (int k = 0; k <= 14; k++) {
            queen_diag = 0;
            for (int i = 0; i < 8; i++) {
                int j = k - i;
                if (j >= 0 && j < 8) {
                    if (board[i][j] == '*') {
                        queen_diag++;
                    }
                }
            }
            if (queen_diag > 1) {
                cout << "invalid" << endl;
                return 0;
            }
        }

        cout << "valid" << endl;
        return 0;


    } else {
        cout << "invalid" << endl;
        return 0;
    }
}