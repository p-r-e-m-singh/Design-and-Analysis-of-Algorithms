#include <iostream>
using namespace std;


int partition(int ar[], int l, int r) {
    if (l < r) {
        int pivot = ar[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (ar[j] < pivot) {
                i++;
                swap(ar[i], ar[j]);
            }
        }
        cout << "Array before pivot swapping\n";
        for (int x = l; x <= r; x++) {
            cout << ar[x] << " ";
        }
        cout << endl;
        i++;
        swap(ar[i], ar[r]);
        return i;
    }
    // Handle the case l>=r
    return l;
}

void quicksort(int ar[], int l, int r) {
    if (l < r) {
        int pi = partition(ar, l, r);
        quicksort(ar, l, pi - 1);
        quicksort(ar, pi + 1, r);
    }
}

int main() {
    int ar[] = { 4, 3, 8, 2, 1 };
    quicksort(ar, 0, 4);
    for (int x : ar) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
