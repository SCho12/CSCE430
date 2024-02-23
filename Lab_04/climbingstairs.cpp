#include <bits/stdc++.h>
using namespace std;

int main() {
    int req, desk, office;
    cin >> req >> desk >> office;

    int sum = 0;

    sum += office;
    sum += abs(office - desk);
    
    while (sum < req) {
        sum += 2;
    }

    sum += desk;

    cout << sum << endl;

}