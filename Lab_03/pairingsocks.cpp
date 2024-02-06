#include<bits/stdc++.h>
using namespace std;


int main() {

    int n;
    stack<int> pile;
    stack<int> aux;
    vector<int> socks;
    int move = 0;
    map<int, int> occur;

    cin >> n;


    for (int i = 0; i < 2*n; i++) {
        int sock;
        cin >> sock;
        occur[sock] = 0;
        socks.push_back(sock);
    }

    for (int a = 0; a < socks.size(); a++) {
        occur[socks[a]] += 1;
    }

    reverse(socks.begin(), socks.end());

    for (int j = 0; j < socks.size(); j++) {
        pile.push(socks[j]);
    }

    bool loop = true;
    bool impossible = false;
    aux.push(pile.top());
    pile.pop();
    move += 1;

    while (loop) {
        if (pile.empty()) {
            loop = false;
        } else if (pile.top() == aux.top()) {
            pile.pop();
            aux.pop();
            move += 1;
        } else {
            if (occur[pile.top()] % 2 != 0) {
                impossible = true;
                loop = false;
            } else {
                aux.push(pile.top());
                pile.pop();
                move += 1;
            }
        }
    }

    loop = true;

    while (loop) {
        if (aux.empty()) {
            loop = false;
        } else if (pile.top() == aux.top()) {
            pile.pop();
            aux.pop();
            move += 1;
        } else {
            if (occur[aux.top()] % 2 != 0) {
                impossible = true;
                loop = false;
            } else {
                pile.push(aux.top());
                aux.pop();
                move += 1;
            }
        }
    }

    if (pile.empty() && aux.empty()) {
        cout << move << endl;
    }
}