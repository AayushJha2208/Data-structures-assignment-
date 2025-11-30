#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() { size = 0; }

    void heapify(int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left < size && arr[left] > arr[largest])
            largest = left;
        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void insert(int val){
        size++;
        arr[size-1] = val;
        int i = size-1;
        while(i > 0 && arr[i/2] < arr[i]){
            swap(arr[i], arr[i/2]);
            i = i/2;
        }
    }

    void deleteMax(){
        if(size == 0){
            cout << "Empty Queue\n";
            return;
        }

        arr[0] = arr[size-1];
        size--;
        heapify(0);
    }

    int getMax(){
        if(size == 0) return -1;
        return arr[0];
    }
    void inckey(int i, int val){
        arr[i]=val;
        while(arr[i/2]<arr[i]){
            swap(arr[i], arr[i/2]);
            i/=2;
        }
    }
    void display(){
        for(int i=0; i<size; i++) cout << arr[i] << " ";
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
    pq.insert(25);
    pq.display();
    pq.inckey(4,50);
    pq.display();
    cout << "Max element: " << pq.getMax() << endl;
}
