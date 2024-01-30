#include <iostream> 
#include <string> 
using namespace std; 
  
int main() 
{ 
    string n;
    string num;
    int total = 0;

    cin >> n;
  
    for (int i = 0; i < stoi(n); i++) {
        cin >> num;
        total += stoi(num);
    }

    cout << total << endl;
} 