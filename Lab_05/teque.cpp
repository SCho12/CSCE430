#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int operations;
    cin >> operations;

    deque<int> first;
    deque<int> second;

    for (int i = 0; i < operations; i++) {
        string command;
        int val;

        cin >> command;
        cin >> val;

        if (command == "push_back") {
            second.push_back(val);
            if (second.size() - first.size() > 1) {
                int temp = second.front();
                second.pop_front();
                first.push_back(temp);
            }
        } else if (command == "push_middle") {
            if ((second.size() + 1) - first.size() > 1) {
                int temp = second.front();
                second.pop_front();
                first.push_back(temp);
            }
            second.push_front(val);
        } else if (command == "push_front") {
            first.push_front(val);
            if (first.size() - second.size() > 1) {
                int temp = first.back();
                first.pop_back();
                second.push_front(temp);
            }
        } else if (command == "get") {
            if (val < first.size()) {
                cout << first[val] << endl;
            } else {
                cout << second[val - first.size()] << endl;
            }
        }
    }
}