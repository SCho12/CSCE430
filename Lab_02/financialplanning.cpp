#include<bits/stdc++.h>
using namespace std;

int main() {
    int options;
    long long int retirement;
    long long int daily;
    long long int cost;

    vector<pair <int, pair <long long int, long long int> > > investments;

    cin >> options;
    cin >> retirement;

    for (int i = 0; i < options; i++) {
        cin >> daily;
        cin >> cost;
        investments.push_back(make_pair(cost/(daily + 1), make_pair(daily, cost)));
    }

    sort(investments.begin(), investments.end());

    int current_day = 0;
    int old_day = 0;
    long long int current_profit = 0;
    long long int daily_profit = 0;
    int retire_days = 0;
    int total_days = 0;
    vector<int> days_til;


    for (int j = 0; j < investments.size();) {
        if (current_day == investments[j].first) {
            current_profit += (current_day - old_day) * daily_profit;
            current_profit += (current_day * investments[j].second.first) - investments[j].second.second;
            daily_profit += investments[j].second.first;
            retire_days = ceil((long double)(retirement - current_profit) / (long double)(daily_profit));
            total_days = current_day + retire_days;
            old_day = current_day;
            days_til.push_back(total_days);
            j++;
        } else {
            current_day += 1;
        }
    }
    std::cout << *min_element(days_til.begin(), days_til.end()) << endl;
}