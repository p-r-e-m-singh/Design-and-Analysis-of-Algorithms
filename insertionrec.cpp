#include<iostream>
using namespace std;

void insertionsort(int ar[],int i,int j,int midx,int n){

    if(i==n){
        return;

    }
    if(j==n){
        swap(ar[midx],ar[i]);
        insertionsort(ar,i+1,i+2,i+1,n);
    }
    else{
        if(ar[j]<ar[midx]){
        midx=j;
        }
        insertionsort(ar,i,j+1,midx,n);

    }
}
int main(){
    //Test Case
    int ar[]= {3,-2,6,5,-1,0};
    insertionsort(ar,0,1,0,6);
    //Array Post Recursively sorting
    for(int i:ar){
        cout<<i<<" ";
    }
    return 0;

}