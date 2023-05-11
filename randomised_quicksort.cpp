#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int ar[], int l, int r,int pass) {
    int nos=0,noc=0;
        int pvidx = (rand()%(r-l+1))+l;
        int pivot = ar[pvidx];
        swap(ar[r],ar[pvidx]);
        int i = l - 1;
        
        for (int j = l; j < r; j++) {
            if (ar[j] < pivot) {
                i++;
                swap(ar[i], ar[j]);
                nos++;
                
            }
            noc++;
        }
        
        i++;
        swap(ar[i], ar[r]);
         cout<<"No of swapping in : "<<pass<<"th pass : "<<nos<<endl;
         cout<<"No of comparisons in : "<<pass<<"th pass : "<<noc<<endl;
        return i;
}

void quicksort(int ar[], int l, int r,int i) 
{
    if (l < r) {
        
        int pi = partition(ar, l, r,i);
        quicksort(ar, l, pi - 1,++i);
        quicksort(ar, pi + 1, r,++i);
    }
}

int main() 
{

    int ar[] = { 4, 3, 8, 2, 1 };
    srand(time(0));
    quicksort(ar, 0, 4,1);
    for (int x : ar) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
