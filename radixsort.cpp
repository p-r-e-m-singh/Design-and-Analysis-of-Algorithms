#include<iostream>
#include<climits>
using namespace std;
//Make sure to chose the place/position carefully 
//Put its benefit in next class
void countsrt(int ar[],int n,int p){
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        maxx = max(maxx,(ar[i]/p)%10);
    }
    int freq[maxx+1]={0};
    for(int i=0;i<n;i++){
        freq[(ar[i]/p)%10]++;
    }
    for(int i=1;i<=maxx;i++){
        freq[i] +=freq[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(ar[i]/p)%10]]=ar[i];
    }
    for(int i=0;i<n;i++){
        ar[i]=ans[i];
    }
}
void radixsort(int ar[],int n){
    int maxx = ar[0];
    for(int i=1;i<n;i++){
        maxx = max(ar[i],maxx);
    }
    for(int power=1;maxx/power>0;power *= 10){
        countsrt(ar,n,power);
    }

}
int main(){
    int ar[] = {33,145,21,772};
    int n=4;
    radixsort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}