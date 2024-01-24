#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_bus;
    int temp;
    vector<int> numbers;
    cin >> num_bus;

    for (int i = 0; i < num_bus; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());
    bool search = false;

    for (int j = 0; j < numbers.size(); j++) {
        if (j >= numbers.size() - 2) {
            cout << numbers[j] << " ";
        } else if (numbers[j + 2] == (numbers[j] + 2)) {
            int start = numbers[j];
            int step = 2;
            cout << start << "-";
            search = true;
            while (search == true) {
                step += 1;
                if (numbers[j + step] == numbers[j] + step) {
                    ;
                } else {
                    step -= 1;
                    cout << numbers[j + step] << " ";
                    search = false;
                    j += step;
                }   
            }
        } else {
            cout << numbers[j] << " ";
        }
    }
}