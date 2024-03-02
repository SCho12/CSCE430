#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> maxheight;
vector<int> set_size;
int num_sets = 0;

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        p[x] = find(p[x]);
        return p[x];
    }
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        if (maxheight[a] == maxheight[b]) {
            p[b] = a;
            maxheight[a]++;
            set_size[a] += set_size[b];
        } else if (maxheight[a] > maxheight[b]) {
            p[b] = a;
            set_size[a] += set_size[b];
        } else {
            p[a] = b;
            set_size[b] += set_size[a];
        }
        num_sets--;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<char> board(rows * cols);
    p.resize(rows * cols);
    maxheight.resize(rows * cols, 1);
    set_size.resize(rows * cols, 1);

    for (int i = 0; i < rows * cols; i++) {
        cin >> board[i];
        if (board[i] == '#') {
            p[i] = i;
            num_sets++;
        }
    }

    for (int j = 0; j < rows * cols; j++) {
        if (board[j] == '#') {
            if (j % cols != 0 && board[j - 1] == '#') {
                merge(j, j - 1);
            }

            if (j >= cols && board[j - cols] == '#') {
                merge(j, j - cols);
            }

            if (j >= cols && j % cols != 0 && board[j - cols - 1] == '#') {
                merge(j, j - cols - 1);
            }

            if (j >= cols && (j + 1) % cols != 0 && board[j - cols + 1] == '#') {
                merge(j, j - cols + 1);
            }
        }
    }

    cout << num_sets << endl;
}
