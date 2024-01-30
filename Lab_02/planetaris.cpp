#include<bits/stdc++.h>
using namespace std;

int main() {
    int systems;
    int ships;
    int wins = 0;
    int temp;
    vector<int> battles;

    cin >> systems;
    cin >> ships;

    for (int i = 0; i < systems; i++) {
        cin >> temp;
        battles.push_back(temp);
    }

    sort(battles.begin(), battles.end());

    for (int j = 0; j < battles.size(); j++) {
        int victory = battles[j] + 1;
        if (ships >= victory) {
            wins += 1;
            ships -= victory;
        }
    }

    cout << wins;
}