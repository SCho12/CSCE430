#include<bits/stdc++.h>
using namespace std;

inline int LSOne(const int x) {
    return x & (-x);
}

class FT {
    vector<long long> a;
    int n;

    public:
    FT(int x) {
        n = x;
        a.resize(x + 1, 0);

    }

    void incr(int elem, long long val) {
        while (elem <= n) {
            a[elem] += val;
            elem = elem + LSOne(elem);
        }
    }

    long long rsq(int elem) {
        long long summation = 0;
        while (elem > 0) {
            summation += a[elem];
            elem -= LSOne(elem);
        }
        return summation;
    }

    long long rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }
};

int main() {

    FT gem1(200000);
    FT gem2(200000);
    FT gem3(200000);
    FT gem4(200000);
    FT gem5(200000);
    FT gem6(200000);

    int gem1_ct = 0;
    int gem2_ct = 0; 
    int gem3_ct = 0;
    int gem4_ct = 0;
    int gem5_ct = 0;
    int gem6_ct = 0;

    vector<FT> trees = {gem1, gem2, gem3, gem4, gem5, gem6};
    vector<int> counts = {gem1_ct, gem2_ct, gem3_ct, gem4_ct, gem5_ct, gem6_ct};


    int num_gems, queries;
    cin >> num_gems >> queries;

    vector<int> values;
    for (int i = 0; i < 6; i++) {
        int temp;
        cin >> temp;
        values.push_back(temp);
    }

    string line;
    cin >> line;

    for (int j = 0; j < line.size(); j++) {
        if (line[j] == '1') {
            gem1_ct++;
            gem1.incr(gem1_ct, 1);
        } else if (line[j] == '2') {
            gem2_ct++;
            gem2.incr(gem2_ct, 1);
        } else if (line[j] == '3') {
            gem3_ct++;
            gem3.incr(gem3_ct, 1);
        } else if (line[j] == '4') {
            gem4_ct++;
            gem4.incr(gem4_ct, 1);
        } else if (line[j] == '5') {
            gem5_ct++;
            gem5.incr(gem5_ct, 1);
        } else if (line[j] == '6') {
            gem6_ct++;
            gem6.incr(gem6_ct, 1);
        }
    }


    for (int k = 0; k < queries; k++) {
        int command, begin, end;
        cin >> command >> begin >> end;

        if (command == 2) {
            values[begin - 1] = end;
        } else if (command == 1) {
            
        }
    }




}