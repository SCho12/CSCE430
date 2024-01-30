#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <cctype>
#include<cstring>
#include<iomanip>
using namespace std;

int main() {
    string message;
    cin >> message;

    double message_size = message.size();

    double whitespace_count = 0;
    double lowercase_count = 0;
    double uppercase_count = 0;
    double symbol_count = 0;

    for (int i = 0; i < message.size(); i++) {
        if (message[i] == '_') {
            whitespace_count += 1;
        } else if (isupper(message[i])) {
            uppercase_count += 1;
        } else if (islower(message[i])) {
            lowercase_count += 1;
        } else {
            symbol_count += 1;
        }
    }

    cout << setprecision(15) << whitespace_count/message_size << endl;
    cout << setprecision(15) << lowercase_count/message_size << endl;
    cout << setprecision(15) << uppercase_count/message_size << endl;
    cout << setprecision(15) << symbol_count/message_size << endl;
}