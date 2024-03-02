#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<string> word_list;
    set<string> unique;
    while (!cin.eof()) {
        string words;
        cin >> words;
        if (words != "") {
            word_list.push_back(words);
        }
    }

    vector<string> compound_list;
    for (int i = 0; i < word_list.size(); i++) {
        for (int j = 0; j < word_list.size(); j++) {
            string compound = "";
            if (word_list[i] != word_list[j]) {
                compound = word_list[i] + word_list[j];
                compound_list.push_back(compound);
            }
        }
    }

    sort(compound_list.begin(), compound_list.end());

    for (int k = 0; k < compound_list.size(); k++) {
        unique.insert(compound_list[k]);
    }

    set<string>::iterator it;
    for (it = unique.begin(); it != unique.end(); it++) {
        cout << *it << endl;
    }
}