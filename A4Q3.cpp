#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q1;
    queue<int> q2;
    int sz;
    cout << "\nHow many elements to enter ?";
    cin >> sz;
    int s = (sz+1)/2;
    int el;
    for(int i=0;i<sz;i++){
        cout << "\nEnter a element: ";
        cin >> el;
        q1.push(el);
    }
    while(s>0){
        el = q1.front();
        q1.pop();
        q2.push(el);
        s--;
    }
    while(!q2.empty()){
        el = q2.front();
        q2.pop();
        q1.push(el);
        cout<<el<<endl;
        if(q2.empty() && sz%2!=0) break;
        el = q1.front();
        q1.pop();
        q1.push(el);
        cout << el<<endl;
    }
    return 0;
}

