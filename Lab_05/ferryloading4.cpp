#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    int length, cars;

    for (int i = 0; i < cases; i++) {
        int trips = 0;
        cin >> length >> cars;
        //cout << "length: " << length << endl;
        length = length * 100;
        int length_cpy = length;
        queue<pair<int, string>> load;
        int car_length;
        string side;

        for (int j = 0; j < cars; j++) {
            cin >> car_length >> side;
            load.push(make_pair(car_length, side));
        }

        int count = 0;
        bool left = true;
        bool right = false;



        while (!load.empty()) {
            if (count == 0 && load.front().second == "right") {
                trips++;
                count++;
                left = false;
                right = true;
            }

            if (left && load.front().second == "left") {
                //cout << "line 37" << endl;
                //cout << "length: " << length << " load: " << load.front().first << endl;
                if ((length - load.front().first) > 0) {
                    length -= load.front().first;
                    load.pop();
                    if (!load.empty() && load.front().second == "right") {
                        trips++;
                        length = length_cpy;
                        left = false;
                        right = true;
                    } else if (load.empty()) {
                        trips++;
                        count = 0;
                        left = true;
                        right = false;
                        break;
                    }
                } else {
                    //cout << "line 48" << endl;
                    trips++;
                    length = length_cpy;
                    left = false;
                    right = true;
                }
            } else if (left && load.front().second == "right") {
                trips++;
                length = length_cpy;
                left = false;
                right = true;
            }

            if (right && load.front().second == "right") {
                //cout << "line 58" << endl;
                if (length - load.front().first > 0) {
                    length -= load.front().first;
                    load.pop();
                    if (!load.empty() && load.front().second == "left") {
                        trips++;
                        length = length_cpy;
                        left = true;
                        right = false;
                    }  else if (load.empty()) {
                        trips++;
                        count = 0;
                        left = true;
                        right = false;
                        break;
                    }
                } else {
                    //cout << "line 69" << endl;
                    trips++;
                    length = length_cpy;
                    left = true;
                    right = false;
                }
            } else if (right && load.front().second == "left") {
                trips++;
                length = length_cpy;
                left = true;
                right = false;
            }
        }
        //cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        cout << trips << endl;
        trips = 0;
    }
}