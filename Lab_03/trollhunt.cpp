#include<bits/stdc++.h>
using namespace std;

int main() {
    int bridges, knights, per;
    cin >> bridges >> knights >> per;
    int groups = knights / per;
    bridges -= 1;
    cout << ceil((float)bridges / (float)groups) << endl;
}