#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numstrings;
    cin >> numstrings;
    vector<list<string>> strings(numstrings);

    for (int i = 0; i < numstrings; i++) {
        string temp;
        cin >> temp;
        strings[i].push_back(temp);
    }

    for (int j = 0; j < strings.size() - 1; j++) {
        int a, b;
        cin >> a >> b;
        strings[a - 1].splice(strings[a - 1].end(), strings[b - 1]);
    }

    for (int k = 0; k < strings.size(); k++) {
        if (!strings[k].empty()) {
            for (auto str = strings[k].begin(); str != strings[k].end(); ++str) {
                cout << *str;
            }
        }
    }
}