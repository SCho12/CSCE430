#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int a;
    long long int b;

    while (cin >> a >> b) {
        if (a == 0 || b == 0) {
            break;
        } else {
            long long int tempA = a;
            long long int tempB = b;

            map<long long int, long long int> steps;
            long long int stepA;
            long long int stepB;
            long long int countA = 0;
            long long int countB = 0;

            steps[tempA] = 0;
            bool a_one = false;

            if (tempA == 1) {
                a_one = true;
            } else {
                while (tempA != 1) {
                    if (tempA % 2 == 0) {
                        countA++;
                        tempA = tempA / 2;
                        steps[tempA] = countA;
                    } else {
                        countA++;
                        tempA = (3 * tempA) + 1;
                        steps[tempA] = countA;
                    }
                }
            }

            if (tempB == 1 && a_one) {
                cout << a << " needs " << steps[tempB] << " steps, " << b << " needs " << countB <<" steps, they meet at " << tempB << endl;
            } else if (tempB == 1) {
                cout << a << " needs " << countA << " steps, 1 needs 0 steps, they meet at 1" << endl; 
            } else {
                while (tempB != 1) {
                    if (steps.count(tempB)) {
                        cout << a << " needs " << steps[tempB] << " steps, " << b << " needs " << countB <<" steps, they meet at " << tempB << endl;
                        break;
                    } else if (tempB % 2 == 0) {
                        countB++;
                        tempB = tempB / 2;
                    } else {
                        countB++;
                        tempB = (3 * tempB) + 1;
                    }
                }

                if (a_one) {
                    cout << "1 needs 0 steps, " << b << " needs " << countB <<" steps, they meet at 1" << endl;
                }
            }
        }
    }
}