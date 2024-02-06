#include<bits/stdc++.h>
using namespace std;

int main() {
    int guests;
    cin >> guests;

    map<long long int, priority_queue<int> > party;
    long long int awkwardness = guests;


    for (int i = 0; i < guests; i++) {
        long long int language;
        cin >> language;
        party[language].push(i);
    }

    for (map<long long int, priority_queue<int> >::iterator it=party.begin(); it != party.end(); ++it) {
        if (it->second.size() > 1) {
            int max = it->second.top();
            it->second.pop();
            int min = it->second.top();
            int gap = max - min;
            if (gap < awkwardness) {
                awkwardness = gap;
            }
        }
    }

    cout << awkwardness << endl;
}