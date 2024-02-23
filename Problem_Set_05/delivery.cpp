#include<bits/stdc++.h>
using namespace std;

int main() {

    int addresses, capacity;
    cin >> addresses >> capacity;
    long long int distance = 0;

    vector<pair<int, int> > left;
    vector<pair<int, int> > right;

    for (int i = 0; i < addresses; i++) {
        int distance, take;
        cin >> distance >> take;
        if (distance < 0) {
            left.push_back(make_pair(distance, take));
        } else {
            right.push_back(make_pair(distance, take));
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), greater<pair<int, int> >());

    int l_offset = 0;
    for (int j = 0; j < left.size(); j++) {
        int pile = left[j].second;
        pile = pile - l_offset;
        int trips = (pile + capacity - 1) / capacity;
        l_offset = (trips * capacity) - pile;
        distance += 2 * ((-1 * left[j].first) * trips);
    }

    int r_offset = 0;
    for (int k = 0; k < right.size(); k++) {
        int pile = right[k].second;
        pile = pile - r_offset;
        int trips = (pile + capacity - 1) / capacity;
        r_offset = (trips * capacity) - pile;
        distance += 2 * (right[k].first * trips);
    }
    
    cout << distance << endl;
}