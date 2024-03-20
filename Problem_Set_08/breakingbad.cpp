#include<bits/stdc++.h>
using namespace std;

struct node { // struct for nodes of graph
    string item_name;
    vector<int> neighbors; 
    int color;
    node(string name): item_name(name), color(-1) {} 
};

int main() {
    int num_items;
    cin >> num_items;

    vector<node> items; 
    unordered_map<string, int> idx; // map to store indices for neighbor assignment
    for (int i = 0; i < num_items; i++) {
        string name;
        cin >> name;
        items.push_back(node(name));
        idx[name] = i;
    }

    int num_pairs;
    cin >> num_pairs;

    for (int j = 0; j < num_pairs; j++) { // creation of edges between pairs
        string item1, item2;
        cin >> item1 >> item2;

        // Add indices to neighbors
        items[idx[item1]].neighbors.push_back(idx[item2]);
        items[idx[item2]].neighbors.push_back(idx[item1]);
    }

    queue<int> q; 
    for (int k = 0; k < items.size(); k++) {
        if (items[k].color == -1) {
            q.push(k);
            items[k].color = 1;

            while(!q.empty()) {
                int currentIdx = q.front(); 
                q.pop();
                node& current = items[currentIdx]; 

                for (int neighborIdx : current.neighbors) { 
                    if(items[neighborIdx].color == -1) {
                        items[neighborIdx].color = 1 - current.color;
                        q.push(neighborIdx);
                    } else if (current.color == items[neighborIdx].color) { 
                        cout << "impossible" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    vector<string> list1, list2; 

    for (int b = 0; b < items.size(); b++) {
        if (items[b].color == 1) {
            list1.push_back(items[b].item_name);
        } else {
            list2.push_back(items[b].item_name);
        }
    }


    for (string name : list1) {
        cout << name << " ";
    }
    cout << endl;
    for (string name : list2) {
        cout << name << " ";
    }
    cout << endl;
}
