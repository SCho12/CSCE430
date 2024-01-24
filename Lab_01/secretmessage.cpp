#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_messages;
    cin >> num_messages;

    string message;
    string padded = "";
    string secret = "";
    vector<string> messages;
    int message_sq;

    for (int i = 0; i < num_messages; i++) {
        cin >> message;
        padded = message;
        message_sq = ceil(sqrt(message.size()));
        for (int j = message.size(); j < message_sq * message_sq; j++) {
            padded += "*";
        }
        vector<vector<string>> matrix(message_sq, vector<string>(message_sq));
        int counter = 0;
        for (int j = 0; j < message_sq; j++) {
            for (int k = 0; k < message_sq; k++) {
                matrix[j][k] = padded[counter];
                counter += 1;
            }
        }

        
        for (int a = 0; a < message_sq; a++) {
            for (int b = message_sq - 1; b > -1; b--) {
                if (matrix[b][a] != "*") {
                    secret += matrix[b][a];
                }   
            }
        }

        messages.push_back(secret);

        secret = "";
        padded = "";

        for (int p = 0; p < message_sq; p++) {
            for (int q = 0; q < message_sq; q++) {
                matrix[p][q] = "";
            }
        }
    }

    for (int r = 0; r < messages.size(); r++) {
        cout << messages[r] << endl;
    }
}