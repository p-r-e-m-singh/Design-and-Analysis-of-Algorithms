//Make the graph directed and then check it
#include<bits/stdc++.h>
using namespace std;
map<int,int> parent;
void dfs_visit(vector<int> V,vector<vector<int>> adj,int s){
    for(int z:adj[s]){
        if(z!=0 && parent.find(z)==parent.end()){
            parent.insert(make_pair(z,s));
            dfs_visit(V,adj,z);
        }
    }
}
void dfssearch(vector<int> V,vector<vector<int>> adj){
    
    for (int s:V){
        if(parent.find(s)==parent.end()){
            parent.insert(make_pair(s,-1));
            dfs_visit(V,adj,s);
        }
    }
}
int main(){
    vector<vector<int>> adj = {{0,1,1,1,0},{1,0,0,0,0},{1,0,0,1,0},{1,0,1,0,1},{0,0,0,1,0}};
    vector<int> V = {0,1,2,3,4};
    dfssearch(V,adj);
    for (auto it = parent.begin(); it != parent.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;

}
