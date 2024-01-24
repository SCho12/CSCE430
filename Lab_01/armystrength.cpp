#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_cases;
    vector<string> victors;

    cin >> num_cases;

    int zilla_num;
    int mecha_num;

    vector<int> godzilla;
    vector<int> mecha;

    for (int i = 0; i < num_cases; i++) {

        cin >> zilla_num;
        cin >> mecha_num;

        int temp;

        for (int j = 0; j < zilla_num; j++) {
            cin >> temp;
            godzilla.push_back(temp);
        }

        for (int k = 0; k < mecha_num; k++) {
            cin >> temp;
            mecha.push_back(temp);
        }

        int zilla_max = 0;
        for (int a = 0; a < godzilla.size(); a++) {
            if (godzilla[a] > zilla_max) {
                zilla_max = godzilla[a];
            }
        }

        int mecha_max = 0;
        for (int b = 0; b < mecha.size(); b++) {
            if (mecha[b] > mecha_max) {
                mecha_max = mecha[b];
            }
        }

        if (zilla_max > mecha_max) {
            victors.push_back("Godzilla");
        } else if (mecha_max > zilla_max) {
            victors.push_back("MechaGodzilla");
        } else if (zilla_max == mecha_max) {
            victors.push_back("Godzilla");
        }
        

        zilla_max = 0;
        mecha_max = 0;
        godzilla.clear();
        mecha.clear();

    }

    for (int k = 0; k < victors.size(); k++) {
        cout << victors[k] << endl;
    }
}