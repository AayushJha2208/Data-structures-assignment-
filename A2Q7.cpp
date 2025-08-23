#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];

    int i=0, j=0, k=l;
    long long inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv_count += (n1 - i); // remaining L[i..] are > R[j]
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv_count;
}

long long countInversions(int arr[], int l, int r) {
    long long inv_count = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv_count += countInversions(arr, l, m);
        inv_count += countInversions(arr, m+1, r);
        inv_count += mergeAndCount(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i=0; i<n; i++) cin >> arr[i];

    long long result = countInversions(arr, 0, n-1);
    cout << "Number of inversions = " << result << endl;

    return 0;
}
