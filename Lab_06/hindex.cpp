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

    sort(papers.begin(), papers.end());

    for (int k = 0; k < papers.size(); k++) {
        if (hindex[papers[k]] == 0) {
            hindex[papers[k]] = papers.size() - k;
        }
    }

    int end = papers[papers.size() - 1];
    int size_map = hindex[end];

    for (int i = num_papers; i >= 1; i--) {
        if (hindex[i] == 0) {
            hindex[i] = size_map;
        } else {
            size_map = hindex[i];
        }
    }

    int position;
    for (int j = 1; j <= num_papers; j++) {
        if (hindex[j] >= j) {
            position = j;
        } else if (hindex[j] < j) {
            cout << position << endl;
            break;
        }
    }

}