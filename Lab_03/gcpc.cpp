#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num_teams, num_events;
    cin >> num_teams >> num_events;

    unordered_map<int, pair<int, int> > allTeams;
    vector<int> isAbove;

    for (int i = 1; i <= num_teams; i++) {
        allTeams[i] = make_pair(0, 0);
    }

    for (int i = 0; i < num_events; i++) {
        int team, penalty;
        cin >> team >> penalty;
        allTeams[team].first++;
        allTeams[team].second += penalty;

        if (team == 1) {
            int oneSolve = allTeams[1].first;
            int onePenalty = allTeams[1].second;
            int k = 0; 
            for (int j = 0; j < isAbove.size(); j++) {
                if (oneSolve < allTeams[isAbove[j]].first ||
                    (oneSolve == allTeams[isAbove[j]].first && onePenalty > allTeams[isAbove[j]].second)) {
                    isAbove[k++] = isAbove[j];
                }
            }
            isAbove.resize(k); 
        } else {
            int solve = allTeams[team].first;
            int pen = allTeams[team].second;
            if (solve > allTeams[1].first ||
                (solve == allTeams[1].first && pen < allTeams[1].second)) {
                bool found = false;
                for (int t : isAbove) {
                    if (t == team) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    isAbove.push_back(team);
                }
            }
        }
        cout << isAbove.size() + 1 << endl;
    }
}
