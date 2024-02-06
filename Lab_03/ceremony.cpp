#include<bits/stdc++.h>
using namespace std;

int main() {
    int buildings;
    cin >> buildings;

    vector<int> floors;
    for (int i = 0; i < buildings; i++) {
        int temp;
        cin >> temp;
        floors.push_back(temp);
    }

    sort(floors.begin(), floors.end());

    vector<pair<int, int> > demolition;
    demolition.push_back(make_pair(0, floors.size()));

    int num = 1;
    for (int j = 0; j < floors.size(); j++) {
        demolition.push_back(make_pair(floors[j], floors.size() - num));
        num++;
    }

    int demo_max = 1000001;

    for (int k = 0; k < demolition.size(); k++) {
        int total = demolition[k].first + demolition[k].second;
        if (total < demo_max) {
            demo_max = total;
        }
    }

    cout << demo_max << endl;

}