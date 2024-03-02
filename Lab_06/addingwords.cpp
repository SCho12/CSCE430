#include<bits/stdc++.h>
using namespace std;

int main() {

    map<string, int> dict;
    string equation = "";
    string command;
    cin >> command;

    while (!cin.eof()) {    
        if (command == "def") {
            string word;
            int value;
            cin >> word;
            cin >> value;
            dict[word] = value;
        } else if (command == "clear") {
            dict.clear();
        } else if (command == "calc") {
            cout << "calc" << endl;
            string temp;
            while (temp != "=") {
                cin >> temp;
                equation += temp;
            }
            equation += " =";
        }
    }
}