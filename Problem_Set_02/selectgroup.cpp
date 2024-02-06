#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> teams;
    vector<vector<string> > names;

    string op;
    int counter = 0;
    while (cin >> op) {
        if (op == "group") {
            string team_name;
            int num_members;

            cin >> team_name;
            teams[team_name] = counter;
            counter += 1;

            cin >> num_members;
            vector<string> names_of;

            string member;
            for (int i = 0; i < num_members; i++) {
                cin >> member;
                names_of.push_back(member);
            }

            names.push_back(names_of);
            names_of.clear();
        }
    }
}

// reverse polish notation == prefix sum