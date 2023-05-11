#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
    1: 2,3
    2: 1,3,4,5
    3: 1,2,5,7,8
    4: 2,5
    5: 2,3,4,6
    6:5
    7: 3,8
    8: 3,7
*/


void bfs(vector<vector<int>> alist, int u) {
    int i = 0;
    vector<bool> discovered(alist.size(), false);
    vector<vector<int>> level(log2(alist.size()) + 1);
    level[i].push_back(u);
    discovered[u] = true;
    while (!level[i].empty() && i < level.size() - 1) {
        for (const int& x : level[i]) {
            for (int y : alist[x]) {
                if (!discovered[y]) {
                    discovered[y] = true;
                    level[i + 1].push_back(y);
                }
            }
        }
        i++;
    }
    for (const vector<int>& s : level) {
        for (int v : s) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> adjlis = {{0}, {2, 3}, {1, 3, 4, 5}, {1, 2, 5, 7, 8}, {2, 5}, {2, 3, 4, 6}, {5}, {3, 8}, {3, 7}};
    bfs(adjlis, 1);
    return 0;
}
