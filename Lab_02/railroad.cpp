#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <cctype>
#include<cstring>
#include<iomanip>
#include <cmath>
using namespace std;

int main() {
    int junctions;
    int switches;

    cin >> junctions;
    cin >> switches;

    int junction_paths = junctions * 4;
    int switch_paths = switches * 3;

    int total_paths = junction_paths + switch_paths;

    if (total_paths % 2 == 0) {
        cout << "possible";
    } else {
        cout << "impossible";
    }
}