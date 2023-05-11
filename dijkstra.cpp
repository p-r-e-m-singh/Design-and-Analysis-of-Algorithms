
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getMin(vector<int> dist , vector<bool> visited){
    int key = 0 ; 
    int min = INT_MAX ; 
    for(int i=0;i < dist.size(); i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ; 
            key = i ; 
        }
    }
    return key ; 
}

vector<int> dijkstra(vector<vector<int>>& adj,int n,int s){
    vector<int> result(n,INT_MAX);
    vector<int> parent(n);
    vector<bool> visited(n,false);

    parent[s]=-1;
    result[s]=0;

    for(int i=0;i<n;i++){
        int x = getMin(result,visited);
        visited[x]=true;
        for(int y=0; y<n; y++){
            if(adj[x][y]!=0 && !visited[y] && result[y]>result[x]+adj[x][y]){
                result[y]=result[x]+adj[x][y];
                parent[y]=x;
            }
        }
    }
    return parent;
}

int main(){
    vector<vector<int>> adjlist = {
        {0, 1, 2, 4},
        {1, 0, 2, 0},
        {2, 2, 0, 1},
        {4, 0, 1, 0}
    };
    int vertices = 4;
    int src=0;
    vector<int> res = dijkstra(adjlist,vertices,src);
    for(int x: res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
