#include<iostream>
using namespace std;

// Implementation of queue using array
class queue{
public:
    int size;
    int *arr;
    int front;
    int rear;

    // constructor
    queue(int size): size(size), arr(new int[size]), front(-1), rear(-1){}

    // operations
    // is empty is full
    bool isEmpty(){
        return rear == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    // now th remaining operations
    // enqueue - pushing the value from behind
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue is full!!";
            return ;
        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = value;
    }

    // dequeue is deleting from the front
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return ;
        }
        int ele = arr[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front++;
        }
        cout<<ele;
    }

    // peak
    void peak(){
        if(isEmpty()){
            cout<<"Queue is empty!";
        }else{
            for(int i=front; i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }

    void first(){
        // ifnot empty;
        cout<<arr[front];
    }

    void last(){
        // if not empty
        cout<<arr[rear];
    }
};

// Queue using linked list
class node{
public:
    int data;
    node* next;

    // construct
    node(int data): data(data), next(nullptr){}
};

// make the queue class
class queuell{
private:
    node* front;
    node* rear;
public:
    queuell(): front(nullptr), rear(nullptr){}

    // operations
    // isEmpty 
    bool isEmptyll(){
        return front == nullptr;
    }

    // enqueue
    void enqueuell(int value){
        node* new_node = new node(value);
        if(isEmptyll()){
            front = rear = new_node;
        }else{
            rear->next = new_node;
            rear = new_node;
        }
    }

    // dequeue
    void dequeuell(){
        if(isEmptyll()){
            cout<<"Queue is empty";
        }else{
            node* temp = front;
            int ele = temp->data;
            front = front->next;
            delete temp;
            cout<<ele;
            if(front == nullptr){ // if front is nothing that means full queue is deleted so set rear accordingly
                rear == nullptr;
            }
        }
    }

    void firstll(){
        // if not empty
        cout<<front->data;
    }

    void lastll(){
        // if not empty
        cout<<rear->data;
    }

    void peakll(){
        node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        delete temp;
    }
};



signed main(){

    // queue q(5);

    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);

    // q.dequeue();
    // q.first();
    // q.last();
    // q.peak();

    queuell q;

    q.enqueuell(1);
    q.enqueuell(2);
    q.enqueuell(3);
    q.enqueuell(4);
    q.enqueuell(5);

    q.dequeuell();
    q.firstll();
    q.lastll();
    q.peakll();

    return 0;
}