#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> words;
    map<int, string> values;

    string command;
    while(cin >> command) {
        if (command == "clear") {
            words.clear();
            values.clear();
        } else if (command == "def") {
            string word;
            string num;
            cin >> word;
            cin >> num;

            if (words[word] == "") {
                words[word] = num;
                values[stoi(num)] = word;
            } else {
                int prev = stoi(words[word]);
                values[prev] = "";
                words[word] = num;
                values[stoi(num)] = word;
            }
        } else if (command == "calc") {
            string equation = "";
            string temp;
            vector<string> pieces;

            while(temp != "=") {
                cin >> temp;
                equation += (temp + " ");
                pieces.push_back(temp);
            }
            
            bool unknown = false;
            int total = 0;
            bool add = true;
            bool sub = false;
            for (int i = 0; i < pieces.size() - 1; i++) {
                if (pieces[i] != "+" && pieces[i] != "-") {
                    if (words[pieces[i]] == "") {
                        //cout << "line 46" << endl;
                        //cout << "piece: " << pieces[i] << endl;
                        //cout << "words[piece]: " << words[pieces[i]] << endl;
                        unknown = true;
                        break;
                    }  else {
                        if (add) {
                            total += stoi(words[pieces[i]]);
                        } else if (sub) {
                            total -= stoi(words[pieces[i]]);
                        }
                    }
                } else if (pieces[i] == "+") {
                    add = true;
                    sub = false;
                } else if (pieces[i] == "-") {
                    sub = true;
                    add = false;
                }
            }

            //cout << "total: " << total << endl;

            if (unknown) {
                equation += "unknown";
                cout << equation << endl;
            } else if (values[total] == "") {
                equation += "unknown";
                cout << equation << endl;
            } else {
                equation += values[total];
                cout << equation << endl;
            }
        }
    }
}