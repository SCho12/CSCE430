#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > subsets(vector<int> seq) {
    set<vector<int> > unique;
    vector<int> subset;
    vector<vector<int> > result;

    unique.insert(subset);

    for (int i = 0; i < seq.size(); i++) {
        int N = unique.size();
        for (auto it = unique.begin(); it != unique.end() && N > 0; it++) {
            subset = *it;
            subset.push_back(seq[i]);
            result.push_back(subset);
            N--;
        }
        unique.insert(result.begin(), result.end());
        result.clear();
    }

    for (auto sets: unique) {
        result.push_back(sets);
    }

    return result;
}

int main() {

    int cases;
    cin >> cases;
    vector<int> sequence;

    for (int i = 0; i < cases; i++) {
        cout << "Case #" << i+1 << ":" << endl;
        int nelements;
        cin >> nelements;

        for (int j = 0; j < nelements; j++) {
            int num;
            cin >> num;
            sequence.push_back(num);
        }

        vector<vector<int> > sets = subsets(sequence);
        map<int, vector<int> > subs;  

        for (int k = 0; k < sets.size(); k++) {
            subs[accumulate(sets[k].begin(), sets[k].end(), 0)].push_back(k);
        }

        for (auto l = subs.begin(); l != subs.end(); l++) {
            if (l->second.size() > 1) {
                vector<int> set1 = sets[l->second[0]];
                vector<int> set2 = sets[l->second[1]];

                for (int a = 0; a < set1.size(); a++) {
                    cout << set1[a] << " ";
                }
                cout << endl;

                for (int b = 0; b < set2.size(); b++) {
                    cout << set2[b] << " ";
                }
                cout << endl;
            }

        }
    }
    return 0;
}