#include<bits/stdc++.h>
using namespace std;

int main() {

    string current_time;
    string explosion_time;

    cin >> current_time;
    cin >> explosion_time;

    int cur_hh = stoi(current_time.substr(0, 2));
    int cur_mm = stoi(current_time.substr(3, 2));
    int cur_ss = stoi(current_time.substr(6, 2));

    int exp_hh = stoi(explosion_time.substr(0, 2));
    int exp_mm = stoi(explosion_time.substr(3, 2));
    int exp_ss = stoi(explosion_time.substr(6, 2));

    string expected_ss = "";
    string expected_mm = "";
    string expected_hh = "";

    if (exp_ss < cur_ss) {
        exp_ss += 60;
        exp_mm -= 1;
        int temp_ss = exp_ss - cur_ss;

        if (temp_ss < 10) {
            expected_ss += "0";
        }

        expected_ss += to_string(temp_ss);
    } else {
        int temp_ss = exp_ss - cur_ss;

        if (temp_ss < 10) {
            expected_ss += "0";
        }

        expected_ss += to_string(temp_ss);
    }

    if (exp_mm < cur_mm) {
        exp_mm += 60;
        exp_hh -= 1;
        int temp_mm = exp_mm - cur_mm;

        if (temp_mm < 10) {
            expected_mm += "0";
        }

        expected_mm += to_string(temp_mm);
    } else {
        int temp_mm = exp_mm - cur_mm;

        if (temp_mm < 10) {
            expected_mm += "0";
        }

        expected_mm += to_string(temp_mm);
    }


    if (exp_hh < cur_hh) {
        exp_hh += 24;
        int temp_hh = exp_hh - cur_hh;

        if (temp_hh < 10) {
            expected_hh += "0";
        }

        expected_hh += to_string(temp_hh);
    } else {
        int temp_hh = exp_hh - cur_hh;

        if (temp_hh < 10) {
            expected_hh += "0";
        }

        expected_hh += to_string(temp_hh);
    }

    if (explosion_time == current_time) {
        cout << "24:00:00";
    } else {
        cout << expected_hh + ":" + expected_mm + ":" + expected_ss;
    }


}