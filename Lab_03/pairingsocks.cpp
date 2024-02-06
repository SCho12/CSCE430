#include<bits/stdc++.h>
using namespace std;


int main() {

    int n;
    stack<int> pile;
    stack<int> aux;
    vector<int> socks;
    int move = 0;
    cin >> n;


    for (int i = 0; i < 2*n; i++) {
        int sock;
        cin >> sock;
        socks.push_back(sock);
    }

    reverse(socks.begin(), socks.end());

    for (int j = 0; j < socks.size(); j++) {
        pile.push(socks[j]);
    }

    aux.push(pile.top());
    pile.pop();
    move += 1;

    while(!pile.empty()) {
        if (pile.top() == aux.top()) {
            pile.pop();
            aux.pop();
            move++;
            if (aux.empty() && !pile.empty()) {
                aux.push(pile.top());
                pile.pop();
                move++;
            }
        } else {
            aux.push(pile.top());
            pile.pop();
            move++;
        }
    }

    if (pile.empty() && aux.empty()) {
        cout << move << endl;
    } else if (!aux.empty()) {
        cout << "impossible" << endl;
    }
}