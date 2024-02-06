#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string cookie;
    priority_queue<int> below; // max queue for below median that holds smallest cookies
    priority_queue<int, vector<int>, greater<int> > above; // min queue for above median that holds biggest cookies
    int median;

    while(cin >> cookie) {
        if (cookie != "#") {
            below.push(stoi(cookie));
            int top = below.top();
            above.push(top);
            below.pop();
            if (above.size() > below.size() + 1) {
                int offset = above.top();
                above.pop();
                below.push(offset);
            }    
            if (below.size() > above.size() + 1) {
                int offset = below.top();
                below.pop();
                above.push(offset);
            }
        } else {
            if (above.size() > below.size()) {
                cout << above.top() << endl;
                above.pop();
            } else if (above.size() == below.size()) {
                cout << above.top() << endl;
                above.pop();
                int offset = below.top();
                below.pop();
                above.push(offset);
            }
        }
    }
}