#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int ar[], int l, int r){
    int pivot = ar[(rand() %(r-l+1)) + l];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(ar[j] < pivot){
            i++;
            swap(ar[i], ar[j]);
        }
    }
    i++;
    swap(ar[i], ar[r]);
    return i;
}

int randomised_select(int ar[], int l, int r, int i){
    if(l < r){
        int pivot = partition(ar, l, r);
        int k = pivot - l+1;
        if(i == k){
            return ar[pivot];
        }
        else if(i < k){
            return randomised_select(ar, l, pivot - 1, i);
        }
        else{
            return randomised_select(ar, pivot + 1, r, i - k - 1);
        }
    }
    return ar[l];
}

int main(){
    int ar[] = {0, 4, 5, 8, 2}; // 0-based array
    int result = randomised_select(ar, 0, 4, 5);
    cout << result << endl;
    return 0;
}
