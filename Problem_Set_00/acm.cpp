#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {

    string data;
    string time;
    string problem;
    string outcome;
    bool read = true;
    int num_correct = 0;

    while (read == true) {
        
        getline(cin, data);
        stringstream ss(data);
        ss >> time;
        if (time == "-1") {
            read = false;
        } else {
            ss >> problem >> outcome;
            // cout << "Time: " << time << endl;
            // cout << "Problem: " << problem << endl;
            // cout << "Outcome: " << outcome << endl;
        }

    }
    // cout << "exited" << endl;
}