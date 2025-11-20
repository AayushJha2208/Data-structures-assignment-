#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={2,5,3,6,1,10,8};
    int n = 7;
    for (int i = 0; i < n/2; ++i) {
        int min = i;
        int max = n-i-1;
        for (int j=i+1;j<n-i-1;++j) {
            if(arr[j]<arr[min]) min=j;
            if(arr[max]<arr[j]) max=j;
        }
        swap(arr[i], arr[min]);
        swap(arr[n-i-1], arr[max]);
    }
    cout << "\nSorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}