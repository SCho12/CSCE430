#include<bits/stdc++.h>
using namespace std;

int main() {
    int commands; 
    cin >> commands;

    map<int, priority_queue<int> > quests;
    string op;
    int energy, gold, q_energy;

    for (int i = 0; i < commands; i++) {
        cin >> op;
        if (op == "add") {
            cin >> energy;
            cin >> gold;
        } else if (op == "query") {
            cin >> q_energy;
        }
    }








}