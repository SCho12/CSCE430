#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int num_q;
    cin >> num_q;
    vector<string> key;
    string temp;
    int correct = 0;

    for (int i = 0; i < num_q; i++) {
        cin >> temp;
        key.push_back(temp);
    }

    vector<string> answers;

    for (int j = 1; j < int(key.size()); j++) {
        answers.push_back(key.at(j));
    }

    for (int k = 0; k < int(answers.size()); k++) {
        if (answers.at(k) == key.at(k)) {
            correct += 1;
        }
    }

    cout << correct;
}