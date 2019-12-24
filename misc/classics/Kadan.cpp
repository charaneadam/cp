#include <bits/stdc++.h>

using namespace std;

int kadan(vector<int> &a, int k=0) {
    int n = (int) a.size();
    int maxSum[n];
    maxSum[0] = a[0];
    int curr_sum = a[0];
    for (int i = 1; i < n; i++) {
        curr_sum = max(a[i], curr_sum + a[i]);
        maxSum[i] = curr_sum;
    }
    curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += a[i];
    int best_sum = curr_sum;
    for (int i = k; i < n; i++) {
        curr_sum = curr_sum + a[i] - a[i - k];
        best_sum = max(best_sum, curr_sum);
        best_sum = max(best_sum, curr_sum + maxSum[i - k]);
    }
    return best_sum;
}

int main() {
    vector<int> arr = {-6, 12, -7, 0, 14, -7, 5};
    assert(kadan(arr, 1) == 19);
    assert(kadan(arr, 0) == 19);
    arr = {-5, -8, -21};
    assert(kadan(arr, 1) == -5);
    assert(kadan(arr, 0) == 0);
    arr = {3, 2, -6, 1, 1, 9, -22, 8};
    assert(kadan(arr, 1) == 11);
    assert(kadan(arr, 0) == 11);
}