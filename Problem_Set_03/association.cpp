#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> maxheight;
vector<int> set_size;

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        p[x] = find(p[x]);
        return p[x];
    }
}

void merge(int x, int y) {
    int a, b;
    a = find(x);
    b = find(y);
    if (a == b) return;
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

}

int main() {
    // Initialization
    int recipes;
    cin >> recipes;
    int potions = 0;
    p.resize(500000);
    maxheight.resize(500000);
    set_size.resize(500000);
    for (int i = 0; i < 500000; i++) {
        p[i] = i;
        maxheight[i] = 1;
        set_size[i] = 1;
    }

    for (int j = 0; j < recipes; j++) {
        int ingredients;
        cin >> ingredients;

        vector<int> appears; // set each ingredient is in
        map<int, int> set_count; // map to help count number of occurrences
        set<int> ingr_sets; // sets needed to merge
        for (int k = 0; k < ingredients; k++) {
            int ingr;
            cin >> ingr;
            appears.push_back(find(ingr));
            set_count[find(ingr)]++;
            ingr_sets.insert(find(ingr));
        }

        bool possible = true;
        sort(appears.begin(), appears.end());

        for (const int &set_num: ingr_sets) {
            if (set_size[set_num] != set_count[set_num]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            potions += 1;
            for (int a = 0; a < appears.size() - 1; a++) {
                merge(appears[a], appears[a + 1]);
            }
        }
    }
    cout << potions << endl;
}