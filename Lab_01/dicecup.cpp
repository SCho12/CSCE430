#include<bits/stdc++.h>
using namespace std;

int main() {
    int dice1;
    int dice2;

    cin >> dice1 >> dice2;

    vector<int> results(dice1 + dice2, 0);

    for (int i = 1; i < dice1 + 1; i++) {
        for (int j = 1; j < dice2 + 1; j++) {
            int face = i + j;
            results[face] = results[face] + 1;
        }
    }

    int max = 0;
    for (int k = 0; k < results.size(); k++) {
        if (results.at(k) > max) {
            max = results.at(k);
        }
    }

    for (int m = 0; m < results.size(); m++) {
        if (results.at(m) == max) {
            cout << m << endl;
        }
    }
}