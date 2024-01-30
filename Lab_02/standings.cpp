#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    vector<int> places;
    vector<long long int> badness;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int teams = 0;
        int preferred = 0;
        long long int bad_sum = 0;
        string name;
        cin >> teams;
        
        for (int j = 0; j < teams; j++) {
            cin >> name;
            cin >> preferred;
            places.push_back(preferred);
        }

        sort(places.begin(), places.end());

        for (int k = 0; k < places.size(); k++) {
            bad_sum += abs((k + 1) - places[k]);
        }

        badness.push_back(bad_sum);
        places.clear();
    }

    for (int a = 0; a < badness.size(); a++) {
        cout << badness[a] << endl;
    }
}