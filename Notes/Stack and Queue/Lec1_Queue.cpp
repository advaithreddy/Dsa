#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int back;
public:
    Queue(int n){
        this.   size  = n;
        arr = new int[size];
        front =  0;
        back = 0;
    }

    bool isEmpty(){
        if(front != 0){
            return false;
        }
        return true;
    }

    void enqueue(int data){
        if(back == size-1){
            cout<<"Queue is Full\n";
        }

        arr[back] = data;
        back++;
    }

    int dequeue(){
        if(front == back){
            cout<<"Queue is Empty"<<"\n";
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        front++;

        if(front == back){
            front = 0;
            back =0;
        }
        return ans;
    }

    int qfront(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<"\n";
        }
        return arr[front];
    }

    int rear(){
        if(isEmpty()) {
            cout << "Queue is Empty" << "\n";
        }
        return arr[back];
    }

    int qsize(){
        return back-front;
    }

};

void interLeaveQueue(queue<int>& q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    // Initialize an empty queue of int type
    queue<int> temp;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, queue: 11 12 13 14 15
    for (int i = 0; i < halfSize; i++) {
        temp.push(q.front());
        q.pop();
    }

    // enqueue back the queue elements alternatively
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!temp.empty()) {
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }
}

int main(){
//    // Normal Queue STL
//    queue<int> q;
//    q.push(17);
//    q.push(14);
//    cout<<q.front()<<"\n";            // [17,  14]
//    q.pop();                          // front
//    q.push(40);                    // [14, 40, 45]
//    q.push(45);
//    cout<<q.back()<<"\n";              //         back
//    cout<<q.size()<<"\n";             //     size 3


    // Implementation of Queue Manually
//    Queue q(5);
//    q.enqueue(17);
//    q.enqueue(14);
//    cout<<q.qfront()<<"\n";
//    q.dequeue();
//    q.enqueue(40);
//    q.enqueue(45);
//    cout<<q.rear()<<"\n";
//    cout<<q.qsize()<<"\n";


    // Interleave first half queue second half
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }


    return 0;
}
