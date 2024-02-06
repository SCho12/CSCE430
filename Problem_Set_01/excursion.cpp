#include<bits/stdc++.h>
using namespace std;

int main() {

    long long int swaps = 0;
    long long int ones = 0;
    long long int twos = 0;

    string order;
    cin >> order;

    for (int i = 0; i < order.size(); i++) {
        int num = order[i] - 48;
        if (num == 0) {
            swaps += ones;
            swaps += twos;
        } else if (num == 1) {
            swaps += twos;
            ones++;
        } else if (num == 2) {
            twos++;
        }
    }

    cout << swaps << endl;
}