#include<bits/stdc++.h>
using namespace std;

int main() {
    int options;
    long long int retirement;
    int daily;
    int cost;

    vector<pair <int, pair <int, int> > > investments;

    cin >> options;
    cin >> retirement;

    for (int i = 0; i < options; i++) {
        cin >> daily;
        cin >> cost;
        investments.push_back(make_pair(cost/daily + 1, make_pair(daily, cost)));
    }

    sort(investments.begin(), investments.end());

    int current_day = 1;
    int current_profit = 0;
    int daily_profit = 0;
    int days = 0;


    for (int j = 0; j < investments.size() - 1;) {
        if (current_day == investments[j].first) {
            current_profit += (current_day * investments[j].second.first) - investments[j].second.second;
            daily_profit += investments[j].second.first;
            days = ceil(float(retirement - current_profit) / float(daily_profit));
            
            if (days + current_day > investments[j + 1].first) {
                int old_day = days + current_day;
                current_day = investments[j + 1].first;
                current_profit += (old_day - current_day) * daily_profit;
                current_profit += (old_day - current_day) * ((current_day * investments[j + 1].second.first) - investments[j + 1].second.second);
                daily_profit += investments[j + 1].second.first;
                days = ceil(float(retirement - current_profit) / float(daily_profit));
            } else {
                cout << days + current_day << endl;
                break;
            }
            j++;
        } else {
            current_day += 1;
        }
    }
}