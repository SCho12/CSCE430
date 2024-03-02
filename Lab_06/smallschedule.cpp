#include<bits/stdc++.h>
using namespace std;

int main() {
    int long_time, machines, one_slots, q_slots;
    cin >> long_time >> machines >> one_slots >> q_slots;

    map<int, int> line;

    int num_longs = q_slots / machines;
    int long_left = q_slots % machines;

    int remain_ones = machines - long_left;
    int index = machines - remain_ones;

    if (num_longs > 0) {
        for (int i = 0; i < machines; i++) {
            line[i] += (num_longs * long_time);
        }
    }

    if (long_left > 0) {
        for (int j = 0; j < long_left; j++) {
            line[j] += (long_time);
        }
    }

    if (one_slots > 0 && index != 0) {
        for (int k = index; k < machines; k++) {
            int count = 0;
            while (count != long_time) {
                if (one_slots == 0) {
                    break;
                } else {
                    line[k]++;
                    count++;
                    one_slots--;
                }
            }
        } 
    }

    int leftover_ones = one_slots / machines;
    int modulo_ones = one_slots % machines;

    for (int a = 0; a < machines; a++) {
        line[a] += (leftover_ones);
    }

    for (int b = 0; b < modulo_ones; b++) {
        line[b]++;
    }


    map<int, int>::iterator it;
    int max = 0;
    for (it = line.begin(); it != line.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }


    cout << max << endl;
}