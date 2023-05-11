#include<bits/stdc++.h>
using namespace std;

struct edge {
    int wt,src,des;
};

vector<edge> kruskals(vector<edge>& edges, int n){
    vector<edge> mst;
    vector<int> parent(n);
    //Make Union-Find
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    sort(edges.begin(),edges.end(),[](edge a,edge b){
        return a.wt<b.wt;
    });
    for(edge x:edges ){
        //Find
        int source = parent[x.src];
        int destination = parent[x.des];
        if(source!=destination){
            mst.push_back(x);
            for(int i=0;i<n;i++){
                // UNIOn(A,B)
                if(parent[x.des]==destination){
                    parent[x.des]=source;
                }
            }
         }
    }

        
    return mst;
}
int main() {
    // Example graph with 5 nodes and 7 edges
    vector<edge> edges = 
                        {{2 ,0, 1},
                        {3 ,0 ,2},
                        {1 ,1,2},
                        {4 ,1 ,3},
                        {5, 2 ,3}};
    int n = 4;

    // Find MST using Kruskals's algorithm
    vector<edge> mst = kruskals(edges, n);

    // Print MST edges and their weights
    for(edge edg : mst) {
        cout << edg.src << " - " << edg.des << " : " << edg.wt << endl;
    }

    return 0;
}
