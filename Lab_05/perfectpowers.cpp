#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int number;
    while(cin >> number) {
        if (number == 0) {
            break;
        }
        if (number > 0) {
            int power = 32;
            int answer = 1;
            for (int i = power; i >= 2; i--) {
                long double root = pow(number, 1.0/i);
                long long int re = round(root);
                long long int p = pow(re, i);
                if (p == number) {
                    answer = i;
                    break;
                }
            }
            cout << answer << endl;
        } else if (number < 0) {
            int power = 31;
            int answer = 1;
            for (int i = power; i >= 3; i-=2) { 
                long double root = pow(-number, 1.0/i);
                //cout << "root: " << root << endl;
                long long int re = round(root);
                //cout << "re: " << re << endl;
                long long int p = pow(re, i);
                //cout << "p: " << p << endl;
                if (p == -number) {
                    answer = i;
                    break;
                }
            }
            cout << answer << endl; 
        }
    }
    return 0;
}
