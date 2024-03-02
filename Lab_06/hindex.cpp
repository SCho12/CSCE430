#include<bits/stdc++.h>
using namespace std;


int main() {
    int num_papers;
    cin >> num_papers;

    vector<int> papers;
    map<int, int > hindex;

    for (int i = 0; i < num_papers; i++) {
        int temp;
        cin >> temp;
        papers.push_back(temp);
    }

    sort(papers.begin(), papers.end(), greater<int>());

    bool greater = true;
    for (int i = 0; i < papers.size();) {
        if (papers[i] >= i + 1) {
            i++;
        } else {
            greater = false;
            cout << i << endl;
            break;
        }
    }

    if (greater) {
        cout << num_papers << endl;
    }

}