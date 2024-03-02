#include <bits/stdc++.h>
using namespace std;


int main() {

    int cases;
    cin >> cases;
    vector<int> sequence;

    for (int i = 0; i < cases; i++) {
        cout << "Case #" << i + 1 << ": " << endl;

        int num, size;
        cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> num;
            sequence.push_back(num);
        }


        vector<int> sub;
        vector<int> set1;
        vector<int> set2;
        bool equal = false;
        map<int, vector<vector<int>> > sums;
        for (int k = 0; k < (1 << size); k++) {
            for (int l = 0; l < size; l++) {
                if ((k & (1 << l)) != 0) {
                    sub.push_back(sequence[l]);
                }
            }
            int total = accumulate(sub.begin(), sub.end(), 0);
            if (sums[total].size() == 0) {
                sums[total].push_back(sub);
            } else {
                set1 = sums[total][0];
                set2 = sub;
                equal = true;
                break;
            }
            sub.clear();
        }

        if (equal) {
            for (int a = 0; a < set1.size(); a++) {
                cout << set1[a] << " ";
            }
            cout << endl;

            for (int b = 0; b < set2.size(); b++) {
                cout << set2[b] << " ";
            }
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }

        sequence.clear();
    }
    return 0;
}