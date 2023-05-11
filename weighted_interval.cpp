#include<iostream>
using namespace std;
const int n = 4; // numbering is in the form 0,1,2,3
int p[n];
int M[] = {0};

int weighted_opt(int size, int s[], int f[], int w[]) {
    if (size < 0) {
        return 0;
    } else if (M[size] == 0) {
        M[size] = max(weighted_opt(size-1, s, f, w), w[size] + weighted_opt(p[size], s, f, w));
    }
    return M[size];
}

int main() {
    int start_times[] = {1, 2, 4, 6};
    int finish_times[] = {3, 5, 7, 8};
    int weights[] = {5, 1, 3, 2};

    // Initialize p to -1
    for (int i = 0; i < n; i++) {
        p[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish_times[i] <= start_times[j]) {
                p[j] = i;
                break;
            }
        }
    }

    int result = weighted_opt(n - 1, start_times, finish_times, weights);
    cout << result;

    return 0;
}
