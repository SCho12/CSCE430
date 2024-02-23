#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_shares = 0;
    long double tot_price = 0;
    long double avg_price = 0;
    int shares;
    int price;

    while(!cin.eof()) {
        string command;
        cin >> command;

        if (command == "buy") {

            cin >> shares;
            cin >> price;
            num_shares += shares;
            tot_price += shares * price;
            //cout << "total price: " << tot_price << endl;
            avg_price = tot_price / num_shares;
            //cout << "average price: " << avg_price << endl;

        } else if (command == "sell") {

            cin >> shares;
            cin >> price;
            num_shares -= shares;
            tot_price = num_shares * avg_price;
            //cout << "number of shares: " << num_shares << endl;

        } else if (command == "split") {

            cin >> shares;
            num_shares *= shares;
            avg_price /= shares;
            tot_price = num_shares * avg_price;
            //cout << "average price: " << avg_price << endl;

        } else if (command == "merge") {

            cin >> shares;
            avg_price *= shares;
            //cout << "average price: " << avg_price << endl;
            num_shares /= shares;
            tot_price = num_shares * avg_price;
            //cout << "number of shares: " << num_shares << endl;

        } else if (command == "die") {
            cin >> price;
            if (price > avg_price) {
                double profit = price - avg_price;
                cout << setprecision(15) << num_shares * (price - profit * 0.3) << endl;
            } else {
                cout << setprecision(15) << num_shares * price << endl;
            }
            break;
        }
    }
}