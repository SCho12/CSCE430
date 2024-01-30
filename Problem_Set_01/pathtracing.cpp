#include<bits/stdc++.h>
using namespace std;

int main() {

    string moves; 
    vector<string> move_list;

    while (!cin.eof()) {
        cin >> moves;
        move_list.push_back(moves);
    }



    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << endl;
    }

}