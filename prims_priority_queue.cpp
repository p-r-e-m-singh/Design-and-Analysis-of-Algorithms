#include<bits/stdc++.h>
using namespace std;
void prims(vector<vector<int>>& adj,int v){
    vector<int> Q(v);
    vector<int> parent(v, -1); // Initialize parent array with -1
    for(int i=0;i<v;i++){
        Q[i] = INT_MAX; // Initialize Q vector with INT_MAX
    }
    Q[0]=0;
    vector<bool> explored(v,false);
    while(!Q.empty()){
        auto minIt = min_element(Q.begin(), Q.end());
        int u = distance(Q.begin(), minIt);
        Q.erase(minIt); // Remove minimum element from Q
        explored[u]=true;
        for(int i=0;i<adj[u].size();i++){
            if(explored[i]==false && adj[u][i]<Q[i]){
                Q[i] = adj[u][i];
                parent[i]=u;
            }
        }
    }
    for(int pie: parent){
        cout<<pie<<" ";
    }
}
int main(){
    vector<vector<int>> adj = {
        {0, 5, 1, 3, 4},
        {5, 0, 0, 6, 0},
        {1, 0, 0, 2, 0},
        {3, 6, 2, 0, 2},
        {4, 0, 0, 2, 0}
    };

     prims(adj, 5);

    return 0;
}
