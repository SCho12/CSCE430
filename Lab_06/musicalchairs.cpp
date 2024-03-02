#include<bits/stdc++.h>
using namespace std;

int main() {
    int teachers;
    cin >> teachers;

    vector<pair<int, int> > opus;

    for (int i = 0; i < teachers; i++) {
        int song;
        cin >> song;
        opus.push_back(make_pair(song, i));
    }

    pair<int, int> start = opus[0];
    int index = 0;
    vector<pair<int, int> >::iterator it;
    while(opus.size() != 1) {
        int position = ((start.first + index) - 1) % opus.size();
        if (position == opus.size() - 1) {
            opus.erase(opus.begin() + position);
            index = 0;
            start = opus[0];
        } else {
            it = opus.erase(opus.begin() + position);
            index = distance(opus.begin(), it);
            start = opus[index];
        }
    }

    std::cout << opus[0].second + 1 << endl;
}