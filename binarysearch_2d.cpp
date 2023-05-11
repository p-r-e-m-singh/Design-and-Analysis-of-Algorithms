#include<iostream>
using namespace std;

bool indexoff(int ar[][3],int elem){
    int size=9;
    int lo=0;
    int hi=size-1;
    int mid=-1;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(ar[mid/size][mid%size]==elem){
            return true;
        }
        else if(ar[mid/size][mid%size]>elem){
            hi = mid-1;
        }
        else if(ar[mid/size][mid%size]<elem){
            lo = mid+1;
        }
    }
    return false;
}
int main(){
    int ar[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    bool ans = indexoff(ar,3);
    cout<<ans<<endl;

    return 0;
}