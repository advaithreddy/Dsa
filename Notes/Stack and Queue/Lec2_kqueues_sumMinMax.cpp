#include<bits/stdc++.h>
using namespace std;

class KQueue{
    int* arr;
    int* front;
    int* rear;
    int* next;
    int n;
    int k;
    int freespot;
public:
    KQueue(int k, int n){
        this->k = k;
        this->n = n;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize front
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize next array
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        freespot = 0;
    }

    bool isFull(){
        return (freespot == -1);
    }

    bool isEmpty(int qn){
        return (front[qn] == -1);
    }


    void enqueue(int data, int qn){
        // Overflow
        if(isFull()){
            cout<<"Queue Overflow"<<"\n";
            return;
        }
        // Find first Free index
        int i = freespot;
        // Update Freespot
        freespot = next[i];

        // Check if first element
        if(front[qn] == -1){
            front[qn] == i;
        }else{
            // link new element to previous element
            next[rear[qn]] = i;
        }
        // Update next
        next[i] = -1;
        // update rear
        rear[qn] = i;
        // push
        arr[i] = data;
    }


    void dequeue(int qn){
        if(isEmpty(qn)){
            cout<<"Queue is Empty Cannot Delete\n";
            return;
        }

        // Pop
        // find index to pop
        int i = front[qn];
        // front ko age badao
        front[qn] = next[i];
        // manage free
        next[i] = freespot;
        freespot  =i;
        cout<<"Popped element: "<<arr[i]<<"\n";
    }
};

int solve(int * arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    // For first window
    int sum =0;
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Now for remaining window
    for(int i=k;i<n;i++){
        sum += arr[maxi.front()] + arr[mini.front()];

        // Removal
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }


        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Now include last window
    sum += arr[maxi.front()] + arr[mini.front()];

    return sum;
}


int main(){

    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout<<" Sum of min and max of subarrays : "<< solve(arr,7,k)<<"\n";


    return 0;
}