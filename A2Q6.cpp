#include <iostream>
using namespace std;
void printTriplet(int a[][3]) {
    int n = a[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i][0] << "   " << a[i][1] << "   " << a[i][2] << endl;
    }
}

void transpose(int a[][3], int b[][3]) {
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;
    int k = 1;
    for (int col = 0; col < a[0][1]; col++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == col) {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void add(int a[][3], int b[][3], int c[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n";
        return;
    }
    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }
    c[0][2] = k - 1;
}

void multiply(int a[][3], int b[][3], int c[][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }
    int bT[20][3];
    transpose(b, bT);
    int pa = a[0][2], pb = bT[0][2];
    int k = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    int i = 1;
    while (i <= pa) {
        int row = a[i][0];
        int j = 1;
        while (j <= pb) {
            int col = bT[j][0];
            int sum = 0;
            int ii = i, jj = j;
            while (ii <= pa && a[ii][0] == row && jj <= pb && bT[jj][0] == col) {
                if (a[ii][1] < bT[jj][1]) ii++;
                else if (a[ii][1] > bT[jj][1]) jj++;
                else {
                    sum += a[ii][2] * bT[jj][2];
                    ii++; jj++;
                }
            }
            if (sum != 0) {
                c[k][0] = row;
                c[k][1] = col;
                c[k][2] = sum;
                k++;
            }
            while (j <= pb && bT[j][0] == col) j++;
        }
        while (i <= pa && a[i][0] == row) i++;
    }
    c[0][2] = k - 1;
}

int main() {
    int A[20][3] = {
        {4, 4, 4},
        {0, 0, 5},
        {1, 1, 8},
        {2, 3, 3},
        {3, 0, 6}
    };

    int B[20][3] = {
        {4, 4, 3},
        {0, 0, 4},
        {1, 2, 7},
        {2, 3, 9}
    };

    cout << "Matrix A:\n"; printTriplet(A);
    cout << "\nMatrix B:\n"; printTriplet(B);

    int T[20][3], SUM[20][3], MUL[20][3];

    transpose(A, T);
    cout << "\nTranspose of A:\n"; printTriplet(T);

    add(A, B, SUM);
    cout << "\nA + B:\n"; printTriplet(SUM);

    multiply(A, B, MUL);
    cout << "\nA * B:\n"; printTriplet(MUL);

    return 0;
}
