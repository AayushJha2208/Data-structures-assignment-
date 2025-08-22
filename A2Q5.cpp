#include <iostream>
using namespace std;

// int main(){
//     cout << "Enter 6x6 diagonal matrix diagonal elements: " << endl;
//     int arr[6];
//     for (int i=0;i<6;i++){
//         cout << "\nmatrix["<<i<<"]["<<i<<"] : ";
//         cin >> arr[i];
//     }
// }


// int main(){
//     cout << "Enter 6x6 diagonal matrix diagonal elements: " << endl;
//     int arr1[6],arr2[5],arr3[5],i;
//     for (i=1;i<6;i++){
//         cout << "\nmatrix["<<i-1<<"]["<<i-1<<"] : ";
//         cin >> arr1[i];
//         cout << "\nmatrix["<<i-1<<"]["<<i<<"] : ";
//         cin >> arr2[i];
//         cout << "\nmatrix["<<i<<"]["<<i-1<<"] : ";
//         cin >> arr3[i];
//     }
//     cout << "\nmatrix["<<i-1<<"]["<<i-1<<"] : ";
//     cin >> arr1[i];
// }

int main(){
    cout << "Enter 6x6 lower triangular matrix element: " << endl;
    int arr[21];
    for(int i=0;i<6;i++){
        for(int j=0;j<i+1;j++){
            cout << "\nmatrix["<<i<<"]["<<j<<"] : ";
            cin >> arr[i+j];
        }
    }
}