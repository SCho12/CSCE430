#include<bits/stdc++.h>
using namespace std;

bool paired(stack<char> test) {

    int open = 0;
    int close = 0;

    if (test.top() == ')') {
        return false;
    }

    while(!test.empty()) {
        if (test.top() == '(') {
            open++;
            test.pop();
        } else {
            close++;
            test.pop();
        }
    }

    if (open == close) {
        return true;
    } else {
        return false;
    }
    
}


// (()))(

int main() {

    stack<char> temp;

    string parenth = "(()))(";

    for (int i = parenth.size() - 1; i >= 0; i--) {
        temp.push(parenth[i]);
    }

    cout << paired(temp) << endl;
    
}