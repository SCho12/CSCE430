#include<bits/stdc++.h>
using namespace std;

int main() {

    string moves; 
    vector<string> move_list;

    while (cin >> moves) {
        move_list.push_back(moves);
    }

    const int rows = 1001;
    const int cols = 1001;
    std::vector<std::vector<std::string>> game(rows, std::vector<std::string>(cols));


    for (int a = 0; a < rows; a++) {
        for (int b = 0; b < cols; b++) {
            game[a][b] = " ";
        }
    }

    game[500][500] = "*";

    int max_x = 500;
    int min_x = 500;
    int max_y = 500;
    int min_y = 500;
    int vert = 500;
    int hori = 500;

    for (int i = 0; i < move_list.size(); i++) {
        if (move_list[i] == "left") {
            hori -= 1;
            if (hori < min_x) {
                min_x = hori;
            }
            if (i == move_list.size() - 1) {
                game[hori][vert] = "E";
                break;
            }
            if (game[hori][vert] == " ") {
                game[hori][vert] = "*";
            }
        } else if (move_list[i] == "right") {
            hori += 1;
            if (hori > max_x) {
                max_x = hori;
            }
            if (i == move_list.size() - 1) {
                game[hori][vert] = "E";
                break;
            }
            if (game[hori][vert] == " ") {
                game[hori][vert] = "*";
            }
        } else if (move_list[i] == "up") {
            vert += 1;
            if (vert > max_y) {
                max_y = vert;
            }
            if (i == move_list.size() - 1) {
                game[hori][vert] = "E";
                break;
            }
            if (game[hori][vert] == " ") {
                game[hori][vert] = "*";
            }
        } else if (move_list[i] == "down") {
            vert -= 1;
            if (vert < min_y) {
                min_y = vert;
            }
            if (i == move_list.size() - 1) {
                game[hori][vert] = "E";
                break;
            }
            if (game[hori][vert] == " ") {
                game[hori][vert] = "*";
            }
        }
    }

    game[500][500] = "S";

    // cout << game[496][501] << game[497][501] << game[498][501] << endl;

    for (int s = 0; s < ((max_x - min_x) + 3); s++) {
        cout << "#";
    }
    cout << endl;

    for (int y = max_y; y >= min_y; y--) {
        cout << "#";
        for (int x = min_x; x <= max_x; x++) {
            cout << game[x][y];
        }
        cout << "#";
        cout << endl;
    }

    for (int t = 0; t < ((max_x - min_x) + 3); t++) {
        cout << "#";
    }
    cout << endl;
}