#include<bits/stdc++.h>
using namespace std;

int main() {
    int difference;
    int people = 0;
    int men = 0;
    int women = 0;
    string line;
    cin >> difference;
    cin >> line;
    
    int index1 = 0;
    int index2 = 1;
    
    for (int i = 0; i < line.size(); i++) {
        char first = line[index1];
        char second = line[index2];
        if (abs(men - women) < difference) {
            if (first == 'M') {
                men += 1;
                people += 1;
                index1 = index2;
                index2 += 1;
            } else {
                women += 1;
                people += 1;
                index1 = index2;
                index2 += 1;
            }
        } else if (abs(men - women) == difference) {
            if (men > women) {
                if (first == 'W') {
                    women += 1;
                    people += 1;
                    index1 = index2;
                    index2 += 1;
                } else if (second == 'W') {
                    women += 1;
                    people += 1;
                    index2 += 1;
                } else {
                    break;
                }
            } else if (women > men) {
                if (first == 'M') {
                    men += 1;
                    people += 1;
                    index1 = index2;
                    index2 += 1;
                } else if (second == 'M') {
                    men += 1;
                    people += 1;
                    index2 += 1;
                } else {
                    break;
                }
            }
        }
    }
    cout << people << endl;
}