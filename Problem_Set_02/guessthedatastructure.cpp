#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases;
    vector<int> in; // queue order
    vector<int> out; // output
    vector<int> rev; // stack order
    priority_queue<int> pq;
    vector<int> pq_order; // pq order
    stack<int> st;

    int operation;
    int value;

    while(cin >> testcases) {
        for (int i = 0; i < testcases; i++) {
            cin >> operation >> value;
            if (operation == 1) {
                in.push_back(value);
                pq.push(value);
                st.push(value);
            } else if (operation == 2) {
                out.push_back(value);
                if (!st.empty()) {
                    rev.push_back(st.top());
                    st.pop();
                }
                if (!pq.empty()) {
                    pq_order.push_back(pq.top());
                    pq.pop();
                }
            }
        }

        while (!pq.empty()) {
            pq.pop();
        }

        while (!st.empty()) {
            st.pop();
        }

        if (out.size() < in.size()) {
            in = {in.begin(), in.begin() + out.size()};
        }

        if (out == in) {
            if (out == rev) {
                cout << "not sure" << endl;
            } else if (out == pq_order) {
                cout << "not sure" << endl;
            } else {
                cout << "queue" << endl;
            }
        } else if (out == rev) {
            if (out == in) {
                cout << "not sure" << endl;
            } else if (out == pq_order) {
                cout << "not sure" << endl;
            } else {
                cout << "stack" << endl;
            }
        } else if (out == pq_order) {
            if (out == in) {
                cout << "not sure" << endl;
            } else if (out == rev) {
                cout << "not sure" << endl;
            } else {
                cout << "priority queue" << endl;
            }
        } else {
            cout << "impossible" << endl;
        }

        in.clear();
        out.clear();
        rev.clear();
        pq_order.clear();
    }
}