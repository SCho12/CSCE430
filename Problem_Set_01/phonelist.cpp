#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    int num;
    string temp;
    vector<string> numbers;
    vector<string> results;

    for (int i = 0; i < cases; i++) {
        cin >> num;

        for (int j = 0; j < num; j++) {
            cin >> temp;
            numbers.push_back(temp);
        }       

        sort(numbers.begin(), numbers.end());

        bool consistent = true;

        for (int b = 0; b < numbers.size() - 1; b++) {
            if (numbers[b] == numbers[b + 1].substr(0, numbers[b].size())) {
                consistent = false;
                break;
            }
        }

        if (consistent == false) {
            results.push_back("NO");
        } else {
            results.push_back("YES");
        }

        numbers.clear();
    }

    for (int c = 0; c < results.size(); c++) {
        cout << results[c] << endl;
    }
}