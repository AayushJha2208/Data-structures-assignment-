#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i=0; i<n; i++) cin >> arr[i];

    int result=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) result++;
        }
    }

    cout << "Number of inversions = " << result << endl;

    return 0;
}
