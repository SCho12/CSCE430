#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int length, cars;
        cin >> length >> cars;
        length *= 100; 

        queue<int> left, right;
        bool isLeft = true; 
        int trips = 0;

        for (int j = 0; j < cars; j++) {
            int car_length;
            string side;

            cin >> car_length >> side;

            if (side == "left") {
                left.push(car_length);
            } else {
                right.push(car_length);
            }
        }

        int temp = length;
        bool empty = true;
        while (!left.empty() || !right.empty()) {
            temp = length; 
            empty = true;
            if (isLeft) {
                while (!left.empty() && temp >= left.front()) {
                    temp -= left.front();
                    left.pop();
                    empty = false;
                }
            } else {
                while (!right.empty() && temp >= right.front()) {
                    temp -= right.front();
                    right.pop();
                    empty = false;
                }
            }
            
            if (!left.empty() || !right.empty() || !empty) {
                isLeft = !isLeft; 
                trips++; 
            }
        }

        if (empty && !isLeft) {
            trips--;
        }

        cout << trips << endl;
    }
    
    return 0;
}
