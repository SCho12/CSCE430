#include<bits/stdc++.h>
using namespace std;


int main() {
    int group_size;
    vector<int> rolls;
    map<int, pair<int, int> > results; // roll, <index, occurences>

    results.insert({1, {0, 0}});
    results.insert({2, {0, 0}});
    results.insert({3, {0, 0}});
    results.insert({4, {0, 0}});
    results.insert({5, {0, 0}});
    results.insert({6, {0, 0}});


    cin >> group_size;
    int index = -1;

    for (int i = 0; i < group_size; i++) {
        int roll;
        cin >> roll; 
        results[roll].first = i + 1;
        results[roll].second += 1;
    }

    for (int j = 1; j < 7; j++) {
        if (results[j].second == 1) {
            index = results[j].first;
        }
    }

    if (index == -1) {
        cout << "none" << endl;
    } else {
        cout << index << endl;
    }
}