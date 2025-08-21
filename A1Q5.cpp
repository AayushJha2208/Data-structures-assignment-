#include <iostream>
using namespace std;

int main(){
    int A[4][4]={{3,5,7,2},{0,4,6,3},{5,4,6,5},{4,1,9,0}};
    int sum,i,j;
    for(i=0;i<4;i++){
        sum=0;
        for(j=0;j<4;j++){
            sum+=A[i][j];
        }
        cout << "sum(Row " << i+1 << ") = " << sum << endl;
    }
    for(i=0;i<4;i++){
        sum=0;
        for(j=0;j<4;j++){
            sum+=A[j][i];
        }
        cout << "sum(Colmun " << i+1 << ") = " << sum << endl;
    }
    return 0;
}
