//Implement on a directed graph
#include <iostream>
#include <array>
#include <map>
#include <vector>
using namespace std;

bool isNotInMap(std::map<int, int>& m, int key) {
    return m.find(key) == m.end();
}
void bfssearch(int V[], int adj[][5], int s) {
    int n = 5;
    map<int,int> level;
    map<int, int> parent;
    level.insert({s,0});
    parent.insert({s, -1});  // initialize parent of source to -1
    int i = 1;
    vector<int> frontier = {s};
    while (frontier.size()>0) {
        vector<int> nextt;
        for (int x : frontier) {
            for (int y : adj[x]) {
                if (y != 0 && isNotInMap(parent,y)) {
                    // check if y is not already visited and not in parent map
                    level.insert({y,i});
                    parent.insert(std::make_pair(y, x));
                    nextt.push_back(y);
                }
            }
        }
        frontier=nextt;
        i++;
    }
    cout<<"Parent of nodes : "<<endl;
    for (auto it = parent.begin(); it != parent.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    cout<<endl<<"Level of nodes : "<<endl;
    for (auto it = level.begin(); it != level.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}

int main() {
    int vertices[] = {0, 1, 2, 3, 4};
    int adj[][5] = {{0, 1, 1, 1, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 1, 0},
                    {1, 0, 1, 0, 1},
                    {0, 0, 0, 1, 0}};
    int src = 0;

    bfssearch(vertices, adj, src);
    return 0;
}
