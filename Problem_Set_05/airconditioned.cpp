#include<bits/stdc++.h>
using namespace std;

int main() {

    int cases;
    cin >> cases;

    int upperRoom = 0;
    int numRooms = 0;
    vector<pair<int, int>> temps;

    for (int i = 0; i < cases; i++) {
        int lower, upper;
        cin >> lower >> upper;
        temps.push_back(make_pair(lower, upper));
    }
    
    sort(temps.begin(), temps.end());

    for (int j = 0; j < temps.size(); j++) {
        if (temps[j].first > upperRoom) {
            numRooms++;
            upperRoom = temps[j].second;
        } else {
            upperRoom = min(upperRoom, temps[j].second);
        }
    }

    cout << numRooms << endl;
}