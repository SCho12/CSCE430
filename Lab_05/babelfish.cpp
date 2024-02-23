#include<bits/stdc++.h>
using namespace std;

string words;
string english;
string foreign;
map<string, string> dictionary;

int main() {
    while (getline(cin, words)) {
        if (words == "") {
            break;
        }

        int pos = words.find(" ");
        english = words.substr(0, pos);
        foreign = words.substr(pos+1);

        dictionary[foreign] = english;
        //cout << "============" << endl;
        //cout << "English: " << english << " Foreign: " << foreign << endl;
        //cout << "============" << endl;
    }

    while (cin >> words) {
        if (dictionary[words] == "") {
            cout << "eh" << endl;
        } else {
            //cout << "============" << endl;
            cout << dictionary[words] << endl;
            //cout << "============" << endl;
        }
    }


}
