#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_squares;
    int frog_index;
    int magic_num;
    int hops = 0;
    vector< pair<int, bool > > board;

    cin >> num_squares;
    cin >> frog_index;
    cin >> magic_num;

    for (int i = 0; i < num_squares; i++) {
        int temp;
        cin >> temp;
        board.push_back(make_pair(temp, false));
    }

    bool condition = true;

    while (condition) {

        if (board[frog_index - 1].first == magic_num && condition) {
            cout << "magic" << endl;
            cout << hops << endl;
            condition = false;  
        }

        int value = board[frog_index - 1].first;

        if (board[frog_index - 1].second == true && condition) {
            cout << "cycle" << endl;
            cout << hops << endl;
            condition = false;
        } else {
            board[frog_index - 1].second = true;
        }

        if (value == magic_num && condition) {
            cout << "magic" << endl;
            cout << hops << endl;
            condition = false;
        }

        frog_index = frog_index + value;
        hops += 1;
        
        if ((frog_index - 1) < 0 && condition) {
            cout << "left" << endl;
            cout << hops << endl;
            condition = false;
        } else if ((frog_index - 1) > board.size() - 1 && condition) {
            cout << "right" << endl;
            cout << hops << endl;
            condition = false;
        }
    }
}