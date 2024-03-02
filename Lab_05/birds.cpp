#include<bits/stdc++.h>
using namespace std;

int main() {
    int length, separation, num_birds;
    cin >> length >> separation >> num_birds;
    vector<int> birds;
    int total = 0;

    if (num_birds > 0) {
        for (int i = 0; i < num_birds; i++) {
            int temp;
            cin >> temp;
            birds.push_back(temp);
        } 
        sort(birds.begin(), birds.end());
        if (birds.size() == 1) {
            int place = birds[0];
            total += (place - 6)/separation;
            total += (length - place - 6)/separation;
        } else {
            int begin = birds[0];
            int end = birds[birds.size() - 1];

            total += (begin - 6)/separation;
            total += (length - end - 6)/separation;
            
            for (int j = 0; j < birds.size() - 1; j++) {
                int first = birds[j];
                int second = birds[j + 1];
                total += ((second - first)/separation) - 1;
            }
        }

        cout << total << endl;
    } else {
        int begin = 6;
        int end = length - 6;
        if (begin == end) {
            total++;
            total += (begin - 6)/separation;
            total += (length - begin - 6)/separation;
        } else {
            total += 2;
            total += (begin - 6)/separation;
            total += (length - end - 6)/separation;
            total += ((end - begin)/separation) - 1;
        }
        cout << total << endl;
    }
}