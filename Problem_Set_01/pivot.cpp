#include<bits/stdc++.h>
using namespace std;

int main() {
    int total;
    int temp;
    cin >> total;
    vector<int> sequence;
    int pivots = 0;

    for (int i = 0; i < total; i++) {
        cin >> temp;
        sequence.push_back(temp);
    }

    int max = *max_element(sequence.begin(), sequence.end());
    int min = *min_element(sequence.begin(), sequence.end());

    vector<bool> lesser;
    vector<bool> greater;
    int min_check = min;
    int max_check = max;

    for (int j = 0; j < sequence.size(); j++) {
        if (j == 0) {
            if (sequence[j] == min) {
                lesser.push_back(true);
            } else {
                lesser.push_back(false);
                min_check = sequence[j];
            }
        } else {
            if (sequence[j] > min_check) {
                lesser.push_back(true);
                min_check = sequence[j];
            } else {
                lesser.push_back(false);
            }
        }
    }

    for (int k = sequence.size() - 1; k > -1; k--) {
        if (k == sequence.size() - 1) {
            if (sequence[k] == max) {
                greater.push_back(true);
            } else {
                greater.push_back(false);
                max_check = sequence[k];
            }
        } else {
            if (sequence[k] < max_check) {
                greater.push_back(true);
                max_check = sequence[k];
            } else {
                greater.push_back(false);
            }
        }
    }

    reverse(greater.begin(), greater.end());

    for (int a = 0; a < greater.size(); a++) {
        if (greater[a] == true && lesser[a] == true) {
            pivots += 1;
        }
    }

    cout << pivots;
    
}