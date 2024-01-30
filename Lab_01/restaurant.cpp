#include<bits/stdc++.h>
using namespace std;

int main() {

    bool cont = true;
    int cases;
    string order;
    int amount;
    int give_len = 0;
    int take_len = 0;

    while (cont) {
        cin >> cases;
        if (cases == 0) {
            cont = false;
        } else {
            for (int i = 0; i < cases; i++) {
                cin >> order;
                cin >> amount;

                if (order == "DROP") {
                    give_len += amount;
                    cout << "DROP 2 " << amount << endl;
                } 

                if (order == "TAKE") {
                    if (take_len == 0) {
                        take_len += give_len;
                        give_len = 0;
                        cout << "MOVE 2->1 " << take_len << endl;
                        cout << "TAKE 1 " << amount << endl;
                    } else {
                        if (amount > take_len) {
                            int left = amount - take_len;
                            cout << "TAKE 1 " << take_len << endl;
                            take_len = 0;

                            cout << "MOVE 2->1 " << give_len << endl;
                            take_len += give_len;
                            give_len = 0;

                            cout << "TAKE 1 " << left << endl;
                            take_len -= left;
                        } else {
                            cout << "TAKE 1 " << amount << endl;
                            take_len -= amount;
                        }
                    }
                }
            }
            take_len = 0;
            give_len = 0;
            cout << endl;
        }
    }
}