#include<bits/stdc++.h>
using namespace std;

bool isPossible(int midpoint, int locos, map<int, bool> idx, int wagons) {
    int num_trains = wagons;
    int num_locos = locos;
    int train_counter = 0;
    bool has_freight = false;

    for (int i = 0; i < wagons; i++) {

        if (num_locos < 0) {
            return false;
        }

        train_counter++;

        if (idx[i]) {
            has_freight = true;
        }

        if (train_counter < midpoint && has_freight) {
            continue;
        } else if (train_counter == midpoint && has_freight) {
            num_trains -= train_counter;
            train_counter = 0;
            has_freight = false;
            num_locos--;
        } else {
            num_trains -= train_counter - 1;
            train_counter = 1;
            num_locos--;
        }
    }

    return true;

}


int main() {
    
    int cases;
    cin >> cases;

    while (cases--) {

        int num_wagons, freights, locomotives;
        cin >> num_wagons >> freights >> locomotives;

        map<int, bool> indices;

        for (int i = 0; i < freights; i++) {
            int temp;
            cin >> temp;
            indices[temp - 1] = true;
        }

        int mid;
        int low = 1;
        int high = num_wagons;

        while (low < high) {
            mid = (low + high) / 2;
            if (isPossible(mid, locomotives, indices, num_wagons)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        cout << high << endl;
    }
}