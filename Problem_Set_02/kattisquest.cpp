#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
            quests[energy].push(gold);
        } else if (op == "query") {
            cin >> q_energy;
            long long int total_gold = 0;
            while (!quests.empty() && q_energy > 0) {
                auto it = quests.lower_bound(q_energy);
                if (it == quests.end() || it->first > q_energy) {
                    if (it != quests.begin()) {
                        --it;
                    } else {
                        break;
                    }
                }
                
                while (!it->second.empty() && q_energy >= it->first) {
                    total_gold += it->second.top();
                    q_energy -= it->first;
                    it->second.pop();
                }

                if (it->second.empty()) {
                    quests.erase(it);
                }
            }
            cout << total_gold << endl;
        }
    }
}