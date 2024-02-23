#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        vector<string> parts;
        int downs;
        int num;
        cin >> num;

        string sequence;
        cin >> sequence;

        int pos;
        pos = sequence.find("/");
        parts.push_back(sequence.substr(0, pos));
        parts.push_back(sequence.substr(pos + 1, sequence.size() - 1));

        long long int numerator = stoll(parts[0]);
        long long int denominator = stoll(parts[1]);

        if (denominator == 1) {
            denominator = numerator + 1;
            numerator = 1;
            cout << num << " " << numerator << "/" << denominator << endl;
        } else {
            downs = numerator/denominator;
            numerator = numerator % denominator;
            denominator = denominator - numerator;
            numerator = numerator + denominator;
            denominator = denominator + numerator * downs;
            cout << num << " " << numerator << "/" << denominator << endl;
        }
    }
}