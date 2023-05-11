#include<iostream>
#include<vector>
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
const int size=8;
vector<bool> explored(size,false);
void dfs(vector<vector<int>> alist, int u){
    explored[u]=true;
    cout<<u<<"-> ";
    for(int x: alist[u]){
        if(!explored[x]){
            dfs(alist,x);
        }
    }


}
int main(){

    vector<vector<int>> adjlis = {{0},{2,3},{1,3,4,5},{1,2,5,7,8},{2,5},{2,3,4,6},{5},{3,8},{3,7}};
    for(vector<int> i: adjlis){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    dfs(adjlis,1);
    return 0;
}