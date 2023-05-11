/* W: maximum weight of knapsack
   w[i] :  weight of each object
   v[i] :  value of each object
   n: Number of objects
*/
#include<iostream>
#include<vector>
using namespace std;

const int n=5,W = 10;

int knapsack(int j,int w[],int v[], vector<int>& res){
    int ww =W;
    int M[j+1][ww+1];
    bool picked[j+1]={false};
    for(int i=0;i<=ww;i++){
        M[0][i]=0;
    }
    for (int i=1;i<=j;i++){
        for(int k=0;k<=ww;k++){
            if(w[i]>k){
                M[i][k] = M[i-1][k];
            }
            else{
                M[i][k] = max(M[i-1][k],v[i]+M[i-1][k-w[i]]);
                if(M[i-1][k]<v[i]+M[i-1][k-w[i]] ){
                    picked[i]=true ;
                }
            }
            

        }
    }
    for(int i=1;i<j;i++){
        if(picked[i]==true){
            res.push_back(i);
        }
    }
    return M[j][ww];

}


int main(){
    int wt[] = {2, 2, 3, 4, 5};
    int val[] = {6, 10, 12, 16, 20};
    vector<int> result;
    int valresult  = knapsack(n,wt,val,result);
    cout<<valresult<<endl;
    for(int x: result){
        cout<<x<<" ";
    }
    return 0;
}
