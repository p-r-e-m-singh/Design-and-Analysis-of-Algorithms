#include<bits/stdc++.h>
using namespace std;
//For more flaot numbers vaue addition needs to be done

//AT stage 1 its satisfying only o-1 ranged float numbers

void bucketsort(float ar[],int n){
    vector<vector<float>> obj(n,vector<float> ());
    for(int i = 0 ;i<n;i++){

        obj[ar[i]*n].push_back(ar[i]);
    }

    for(int i=0;i<n;i++){
        sort(obj[i].begin(),obj[i].end());

    }
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<obj[i].size();j++){
            ar[k++] = obj[i][j];
        }
    }

    
}
int main(){
    float ar[] = {0.12,0.45,0.66,0.12};
    int n = 4;
    bucketsort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}