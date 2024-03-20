#include<iostream>
#include<vector>

using namespace std;

int main() {
    int rows, closed;
    cin >> rows >> closed;

    vector<vector<int> > rooms(rows + 1, vector<int>(2));

    int i, j, k;
    int total = 0;

    for (i = 1; i <= rows; i++) {
        cin >> rooms[i][0];
        cin >> rooms[i][1];
        total += (rooms[i][0] + rooms[i][1]);
    }

    vector<int> end(2);
    cin >> end[0] >> end[1];

    vector<vector<vector<int> > > dp(rows + 1, vector<vector<int> >(3, vector<int>(closed + 1, 1e7)));
    // dp(i, j, k) = row i, 0/1/2 (for none/left/right) and k closed cells
    dp[0][0][0] = 0;

    for (i = 1; i <= rows; i++) {
        dp[i][0][0] = 0;
        for (k = 1; k <= closed; k++) {
            
            // empty
            dp[i][0][k] = min(dp[i - 1][0][k], dp[i - 1][1][k]);
            dp[i][0][k] = min(dp[i][0][k], dp[i - 1][2][k]);

            // left
            dp[i][1][k] = min(dp[i - 1][1][k - 1], dp[i - 1][0][k - 1]) + rooms[i][0];

            // right
            dp[i][2][k] = min(dp[i - 1][2][k - 1], dp[i - 1][0][k - 1]) + rooms[i][1];
            // if (k > i) {
            //     dp[i][j][k] = -1;
            // } else if (i == 1 && k == 0) {
            //     dp[i][j][k] = rooms[1][0] + rooms[1][1];
            // } else if (i == 1 && j == 2 && k == 1) {
            //     dp[i][j][k] = max(rooms[1][0], rooms[1][1]);
            // } else if (i == 1 && j == 0 && k == 1) {
            //     dp[i][j][k] = rooms[1][0];
            // } else if (i == 1 && j == 1 && k == 1) {
            //     dp[i][j][k] = rooms[1][1];
            // } else {
            //     int option1 = dp[i - 1][2][k] + rooms[i][0] + rooms[i][1];
            //     int option2 = dp[i - 1][0][k - 1] + rooms[i][0];
            //     int option3 = dp[i - 1][1][k - 1] + rooms[i][1];
            //     int option_max = max(option1, option2);
            //     option_max = max(option_max, option3);
            //     dp[i][j][k] = option_max;
            // }
        }
    }
    // cerr << "total : " << total << endl;
    // cerr << "dp : " << dp[1][2][1] << endl;

    int total_min;
    total_min = min(dp[rows][2][closed], dp[rows][1][closed]);
    total_min = min(total_min, dp[rows][0][closed]);
    cout << total - total_min << endl;
}