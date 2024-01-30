#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<pair <int, int> > stars;
    int num;
    cin >> num;

    for (int i = 2; i < num; i++) {
        for (int j = i - 1; j < i + 1; j++) {
            if (num % (i + j) == 0 || num % (i + j) == i) {
                stars.push_back(make_pair(i, j));
            }
        }
    }

    cout << num << ":" << endl;
    for (int a = 0; a < stars.size(); a++) {
        cout << stars[a].first << "," << stars[a].second << endl;
    }

}