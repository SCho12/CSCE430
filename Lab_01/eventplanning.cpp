#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int participants;
    int budget;
    int num_hotels;
    int weeks;
    int price;
    int rooms;
    vector<int> costs;
    vector<int> room_list;

    cin >> participants;
    cin >> budget;
    cin >> num_hotels;
    cin >> weeks;

    for (int i = 0; i < num_hotels; i++) {
        cin >> price;
        
        for (int j = 0; j < weeks; j++) {
            cin >> rooms;
            room_list.push_back(rooms);
        }

        for (int k = 0; k < int(room_list.size()); k++) {
            if (room_list.at(k) >= participants) {
                costs.push_back(participants * price);
                break;
            }
        }
    }

    if (costs.size() == 0) {
        cout << "stay home";
    } else {
        int min = costs.at(0);
        for (int a = 0; a < costs.size(); a++) {
            if (costs.at(a) < min) {
                min = costs.at(a);
            }
        }
        if (min > budget) {
            cout << "stay home";
        } else {
            cout << min;
        }
    }
}