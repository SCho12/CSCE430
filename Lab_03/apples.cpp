#include<bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    map<string, int> count;

    vector<vector<char>> apples(cols);
    // cout << "apples size: " << apples.size() << endl;

    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < cols; j++) {
            char app;
            cin >> app;
            apples[j].insert(apples[j].begin(), app);
        }
    }

    // cout << apples[0][0] << endl;
    // cout << apples[0][1] << endl;
    // cout << apples[0][2] << endl;
    // cout << apples[0][3] << endl;
    // cout << "======" << endl;
    // cout << apples[1][0] << endl;
    // cout << apples[1][1] << endl;
    // cout << apples[1][2] << endl;
    // cout << apples[1][3] << endl;
    // cout << "======" << endl;
    // cout << apples[2][0] << endl;
    // cout << apples[2][1] << endl;
    // cout << apples[2][2] << endl;
    // cout << apples[2][3] << endl;
    // cout << "======" << endl;
    // cout << apples[3][0] << endl;
    // cout << apples[3][1] << endl;
    // cout << apples[3][2] << endl;
    // cout << apples[3][3] << endl;
    // cout << "======" << endl;
    // cout << apples[4][0] << endl;
    // cout << apples[4][1] << endl;
    // cout << apples[4][2] << endl;
    // cout << apples[4][3] << endl;

    // cout << "======\n=======" << endl;

    // for (int x = 0; x < cols; x++) {
    //     for (int y = 0; y < rows; y++) {
    //         cout << apples[x][y];
    //     }
    //     cout << endl;
    // }


    vector<char> temp;
    for (int a = 0; a < cols; a++) {
        int count = 0;
        for (int b = 0; b < rows; b++) {
            if (apples[a][b] == 'a') {
                count += 1;
            } else if (apples[a][b] == '#') {
                for (int i = 0; i < count; i++) {
                    temp.push_back('a');
                }
                for (int j = temp.size(); j < b; j++) {
                    temp.push_back('.');
                }
                temp.push_back('#');
                count = 0;
            }
        }
        // cout << "rows is: " << rows << endl;
        // cout << "cols is: " << cols << endl;
        // cout << "count is: " << count << endl;
        for (int i = 0; i < count; i++) {
            temp.push_back('a');
        }

        for (int j = temp.size(); j < rows; j++) {
            temp.push_back('.');
        }

        apples[a] = temp;
        temp.clear();
    }

    for (int s = 0; s < apples.size(); s++) {
        reverse(apples[s].begin(), apples[s].end());
    }

    // cout << "======\n=======" << endl;
    // cout << apples[0][0] << endl;
    // cout << apples[0][1] << endl;
    // cout << apples[0][2] << endl;
    // cout << apples[0][3] << endl;
    // cout << "======" << endl;
    // cout << apples[1][0] << endl;
    // cout << apples[1][1] << endl;
    // cout << apples[1][2] << endl;
    // cout << apples[1][3] << endl;
    // cout << "======" << endl;
    // cout << apples[2][0] << endl;
    // cout << apples[2][1] << endl;
    // cout << apples[2][2] << endl;
    // cout << apples[2][3] << endl;
    // cout << "======" << endl;
    // cout << apples[3][0] << endl;
    // cout << apples[3][1] << endl;
    // cout << apples[3][2] << endl;
    // cout << apples[3][3] << endl;
    // cout << "======" << endl;
    // cout << apples[4][0] << endl;
    // cout << apples[4][1] << endl;
    // cout << apples[4][2] << endl;
    // cout << apples[4][3] << endl;
    // cout << "======\n=======" << endl;

    for (int p = 0; p < rows; p++) {
        for (int q = 0; q < cols; q++) {
            cout << apples[q][p];
        }
        cout << endl;
    }
}