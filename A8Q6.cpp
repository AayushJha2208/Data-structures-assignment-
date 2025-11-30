#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue(){ size = 0; }

    void insert(int val){
        size++;
        int idx = size;
        arr[idx] = val;

        while(idx > 1 && arr[idx/2] < arr[idx]){
            swap(arr[idx], arr[idx/2]);
            idx /= 2;
        }
    }

    void deleteMax(){
        if(size == 0){
            cout << "Empty Queue\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(true){
            int left = 2*i, right = 2*i+1, largest = i;

            if(left <= size && arr[left] > arr[largest]) largest = left;
            if(right <= size && arr[right] > arr[largest]) largest = right;
            if(largest == i) break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    int getMax(){ return arr[1]; }

    void display(){
        for(int i=1; i<=size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    PriorityQueue pq;
    pq.insert(50);
    pq.insert(30);
    pq.insert(40);
    pq.insert(10);
    pq.insert(20);

    cout << "Priority Queue: ";
    pq.display();

    pq.deleteMax();
    cout << "After deleting max: ";
    pq.display();

    return 0;
}
