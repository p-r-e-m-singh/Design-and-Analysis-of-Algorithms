#include<bits/stdc++.h>
using namespace std;

//Only for non-negative numbers
//Not for large-sized array
//Applicable only in case of Whole number Array

void countsort(int ar[],int n){

    int maxx=INT_MIN;
    for(int x=0;x<n;x++){
        maxx=max(maxx,ar[x]);
    }
    int freq[maxx+1]={0};
    for(int x=0;x<n;x++){
        freq[ar[x]]++;
    }
    for(int i=1;i<maxx+1;i++){
        freq[i]+= freq[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[ar[i]]]=ar[i];
    }
    for(int i=0;i<n;i++){
        ar[i]=ans[i];
    }
    
}
int main(){

    int ar[]={3,6,4,1};
    countsort(ar,4);
    for(int i=0;i<4;i++){
        cout<<ar[i]<<" ";
    }

}