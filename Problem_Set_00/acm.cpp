#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    string data;
    string time;
    string problem;
    string outcome;
    vector<string> list;
    bool read = true;
    int num_correct = 0;
    int time_total = 0;

    while (read == true) {
        
        getline(cin, data);
        stringstream ss(data);
        ss >> time;
        if (time == "-1") {
            read = false;
        } else {
            ss >> problem >> outcome;
            list.push_back(problem);
            if (outcome == "right") {
                time_total += stoi(time) + ((std::count(list.begin(), list.end(), problem) - 1) * 20);
                num_correct += 1;
            }
        }

    }
    cout << num_correct << " " << time_total;
}