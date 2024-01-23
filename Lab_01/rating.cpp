#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int max = 3;
    int min = -3;
    int total;
    int graded;
    int max_score = 0;
    int min_score = 0;

    cin >> total >> graded;
    int temp;
    vector<int> grades;

    for (int i = 0; i < graded; i++) {
        cin >> temp;
        grades.push_back(temp);
    }

    for (int j = 0; j < total; j++) {
        if (j > int(grades.size() - 1)) {
            max_score += 3;
        } else {
            max_score += grades.at(j);
        }
    }

    for (int k = 0; k < total; k++) {
        if (k > int(grades.size() - 1)) {
            min_score -= 3;
        } else {
            min_score += grades.at(k);
        }
    }

    cout << ((float)min_score)/total << " " << (float(max_score))/total;

}