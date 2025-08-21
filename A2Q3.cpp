#include <iostream>
using namespace std;

int func1(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2; // sum of 1..n+1
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return total - sum;
}

int func2(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }
    return low + 1;
}
int main(){
    int n,i;
    cout<<"Enter the number of elements in array";
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cout << "\narr[" << i << "]";
        cin >> arr[i];
    }
    int missing_num = func1(arr,n);
    cout << "\nmissing number found in linear time : " << missing_num;
    missing_num = func2(arr,n);
    cout << "\nmissing number found in logarithmic time : " << missing_num;
}