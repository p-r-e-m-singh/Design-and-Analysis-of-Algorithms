#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> primsmst(vector<vector<int>> adj,int v,int e){
    vector<vector<int>> resultedge;
    int srcminv=INT_MAX;
    for(int i=0;i<v;i++){
        if(adj[i][0]!=0)
        srcminv = min(adj[i][0],srcminv);
    }
    vector<int> traversededge = {srcminv};
    while (traversededge.size() < v){
        int minwtedge = INT_MAX, correctedge = -1;
        for(int i=0; i<traversededge.size(); i++){
            int u = traversededge[i];
            for(int j=0; j<v; j++){
                int w = adj[u][j];
                if(w != 0 && find(traversededge.begin(), traversededge.end(), j) == traversededge.end()){
                    if(w < minwtedge){
                        minwtedge = w;
                        correctedge = j;
                    }
                }
            }
        }
        traversededge.push_back(correctedge);
        resultedge.push_back({correctedge, traversededge[traversededge.size()-2]});
    }
    return resultedge;
}


int main(){
    vector<vector<int>> adj = {
        {0, 5, 1, 3, 4},
        {5, 0, 0, 6, 0},
        {1, 0, 0, 2, 0},
        {3, 6, 2, 0, 2},
        {4, 0, 0, 2, 0}
    };
    vector<vector<int>> result = primsmst(adj, 5, 7);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<2; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
