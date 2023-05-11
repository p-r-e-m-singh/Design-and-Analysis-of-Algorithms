#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;

vector<vector<int>> primsmst(vector<vector<int>> adj,int v,int e){
    vector<vector<int>> resuleedge(e-1,vector<int>(2));
    int srcminv=INT_MAX;
    for(int i=0;i<v;i++){
        srcminv = min(adj[i][0],srcminv);
    }
    vector<int> traversededge = {srcminv};
    for (int x=0;x<traversededge.size()  && traversededge.size()<v ;x++){
        int minwtedge = INT_MAX,correctedge=traversededge[x];
        for(int i=0;i<v && traversededge[x]!=i && adj[traversededge[x]][i]!=0;i++){
            if(adj[traversededge[x]][i]<minwtedge && (find(traversededge.begin(), traversededge.end(), i)==traversededge.end())){
                correctedge = i;
                minwtedge=adj[traversededge[x]][i];
            }
        }
        traversededge.push_back(correctedge);
        resuleedge.push_back({traversededge[x],correctedge});

    }
    return resuleedge;

}


int main(){
    vector<vector<int>> adj = {{0,5,1,3,4},{5,0,0,6,0},{1,0,0,2,0},{3,0,2,0,2},{4,0,0,2,0}} ;
    vector<vector<int>> result = primsmst(adj,5,7);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<2;j++){
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}