#include<iostream>
using namespace std;
void merge(int ar[],int l,int mid,int r){
    //Constructing two arrays to store the arrays
    int a = mid-l+1;
    int b = r-mid;
    int ar1[a],ar2[b];
    for (int i = 0; i < a; i++)
    {
        ar1[i]=ar[l+i];
    }
    for (int i = 0; i <b; i++)
    {
        ar2[i]=ar[mid+i+1];
    }
    int i=0,j=0,k=l;
    while (i<a && j<b)
    {
        if(ar1[i]<ar2[j]){
            ar[k++]=ar1[i++];
        }
        else
        {
            ar[k++]=ar2[j++];
        }
        
    }
    while (i<a)
    {
        ar[k++]=ar1[i++];
    }
    while (j<b)
    {
        ar[k++]=ar2[j++];
    }

    

    
    
    
}
void mergesort(int ar[],int l,int r){ //l:leftmost index ; r: rightmost index
    if(l<r){
        int mid = (l+r)/2;
        mergesort(ar,l,mid);  //division of arrays
        mergesort(ar,mid+1,r);
        merge(ar,l,mid,r); //Merging of array

    }
    else
    {
        return;
    }
    
}
int main(){
    int ar[] = {3,4,2,190,443,5};
    mergesort(ar,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}