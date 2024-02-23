#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int pizzas;
        cin >> pizzas;
        int count = 0;

        map<string, vector<int>> foreign;
        map<string, vector<int>> native;
        for (int j = 0; j < pizzas; j++) {
            count++;
            string name;
            cin >> name;

            int num_foreign;
            cin >> num_foreign;


            for (int k = 0; k < num_foreign; k++) {
                string foreign_top;
                cin >> foreign_top;
                foreign[foreign_top].push_back(count);
            }

            int num_native;
            cin >> num_native;

            for (int l = 0; l < num_native; l++) {
                string native_top;
                cin >> native_top;
                native[native_top].push_back(count);
            }
        }

        vector<pair<string, string>> toppings;

        for (const auto& f: foreign) {
            vector<int> for_num = f.second;

            for (const auto& n: native) {
                vector<int> nat_num = n.second;

                if (for_num == nat_num) {
                    toppings.push_back(make_pair(f.first, n.first));
                }
            }
        }

        for (int m = 0; m < toppings.size(); m++) {
            cout << "(" << toppings[m].first << ", " << toppings[m].second << ")" << endl;
        }
        cout << endl;
    }
}