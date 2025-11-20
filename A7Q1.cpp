#include <bits/stdc++.h>
using namespace std;

// Selection Sort
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//mergesort
void mergesort(vector<int>& arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int mid = (lo + hi) / 2;

    mergesort(arr, lo, mid);
    mergesort(arr, mid + 1, hi);

    vector<int> temp;
    int i = lo, j = mid + 1;

    while (i <= mid && j <= hi)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= hi)
        temp.push_back(arr[j++]);

    for (int k = lo; k <= hi; k++){
        arr[k] = temp[k - lo];
    }
}

void quicksort(vector<int>& arr, int lo, int hi)
{
    if (lo >= hi) return;
    int pv = arr[lo];
    int j = lo;
    for(int i=lo+1;i<=hi;i++){
        if(arr[i] <= pv){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[lo]);
    quicksort(arr, lo, j - 1);
    quicksort(arr, j + 1, hi);
    
}

int main() {
    int  choice;

    vector<int> arr={2,5,4,3,6,1,10,8};

    
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(arr);
            break;
        case 2:
            bubbleSort(arr);
            break;
        case 3:
            insertionSort(arr);
            break;
        case 4:
            mergesort(arr,0,7);
            break;
        case 5:
            quicksort(arr,0,7);
            break;
        default:
            cout << "Invalid choice.\n";
            return 0;
    }

    cout << "\nSorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
