#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, commands;
    vector<pair<pair<set<int>, long long int>, bool>> sets;
    map<int, int> indices;
    long long int index = 0;

    while(cin >> num >> commands) {
        for (int i = 1; i < num + 1; i++) {
            set<int> temp;
            temp.insert(i);
            indices[i] = index;
            index++;
            sets.push_back(make_pair(make_pair(temp, i), false));
        }

        for (int j = 0; j < commands; j++) {
            int command;
            cin >> command;
            if (command != 3) {
                int set1, set2;
                cin >> set1 >> set2;

                if (command == 1) {
                    int set1index = indices[set1];
                    int set2index = indices[set2];

                    bool set1IsLarger = sets[set1index].first.first.size() > sets[set2index].first.first.size();
                    int largerIndex = set1IsLarger ? set1index : set2index;
                    int smallerIndex = set1IsLarger ? set2index : set1index;

                    if (set1index != set2index) {
                        
                        for (const int& num : sets[smallerIndex].first.first) {
                            sets[largerIndex].first.first.insert(num);
                            indices[num] = largerIndex;
                        }
                        
                        sets[largerIndex].second += sets[smallerIndex].second;
                        sets[smallerIndex].second = true;
                    }
                } else if (command == 2) {
                    int set1index = indices[set1];
                    int set2index = indices[set2];

                    if (set1index != set2index) {
                        sets[set1index].first.first.erase(set1);
                        sets[set1index].first.second -= set1;

                        sets[set2index].first.first.insert(set1);
                        sets[set2index].first.second += set1;
                        indices[set1] = set2index;
                    }
                }
            } else {
                int set_num;
                cin >> set_num;
                int set_index = indices[set_num];
                cout << sets[set_index].first.first.size() << " " << sets[set_index].first.second << endl;
            }
        }

        sets.clear();
        indices.clear();
        index = 0;
    }
}