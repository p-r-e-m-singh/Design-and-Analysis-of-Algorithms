#include<iostream>
#include<math.h>
using namespace std;

void max_heapify(int ar[],int n){
    if (ar!=NULL && n!=0)
    {
        for (int i = (n/2-1); i >= 0; i--)
        {
            int q = ceil(n/2);
            if(/*ar[i+q]!=NULL &&*/ ar[i+q]>ar[i] || ar[i+q-1]>ar[i]){
                if(ar[i+q]>ar[i+q-1]){
                    swap(ar[i],ar[i+q]);
                }
                else{
                    swap(ar[i],ar[i+q-1]);
                }
            }
        
        }
    }
    else
    {
        printf("%s","Array Empty");
    }
    
    
    
    
}

void heapsort(int ar[],int n){
    max_heapify(ar,n);
    for (int i = 0; i < n; i++)
    {
        swap(ar[n-i-1],ar[0]);
        max_heapify(ar,n-i-1);
    }
    
}

int main(){
    int ar[] = {3,98,136,8,2};
    heapsort(ar,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}