#include<iostream>
using namespace std;

// Circular queue using array
// build circular queue class
class cqueue{
public:
    int size;
    int* arr;
    int front;
    int rear;

    // construct
    cqueue(int size): size(size), arr(new int[size]), front(-1), rear(-1){}

    // operations
    //isEmpty and isFull
    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear+1)%size == front; // i.e front == rear+1
    }
    // enqueue is inserting at the rear
    void enqueue(int value){
        if(isFull()){
            cout<<"Cannot insert new element";
        }else{
            // conditions
            if(isEmpty()){
                front = rear = 0;
            }else if(rear == size-1){
                rear = 0;
            }else{
                rear++;
            }
            arr[rear] = value;
        }
    }

    // dqueue is deleting from front
    void dqueue(){
        if(isEmpty()){
            cout<<"Queue is empty";
        }else{
            int ele = arr[front];
            if(front == rear){
                front = rear = -1;
            }else if(front == size-1){
                front = 0;
            }else{
                front++;
            }
            cout<<ele;
        }
    }

    void peak(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }

    void first(){
        cout<<arr[front];
    }

    void last(){
        cout<<arr[rear];
    }
};

// Circular queue using circular linked list
// struct for node
struct node{
    int data;
    node* next;
    
    node(int data): data(data), next(nullptr){}
};

class cqueuell{
private:
    node* front;
    node* rear;
public:
    cqueuell(){
        this->front = nullptr;
        this->rear = nullptr;
    }

    // operaitons
    // isEmpty
    bool isEmptyll(){
        return front == nullptr;
    }

    void enqueuell(int value){
        node* new_node = new node(value);
        if(isEmptyll()){
            front = rear = new_node;
        }else{
            rear->next = new_node;
            new_node->next = front;
            rear = new_node;
        }
    }

    void dqueuell(){
        if(isEmptyll()){
            cout<<"cannot delete";
        }else{
            int ele = front->data;
            node* temp = front;
            if(front == rear){
                front = rear = nullptr;
            }else{
                rear->next = front->next;
                front = front->next;
                temp->next = nullptr;
            }
            cout<<ele;
            delete temp;
        }
    }

    void firstll(){
        cout<<front->data;
    }

    void lastll(){
        cout<<rear->data;
    }

    void peakll(){
        if(isEmptyll()){
            cout<<"Nothing to show";
        }else{
            node* temp = front;
            int cnt = 1;
            while(temp != rear){
                cout<<temp->data<<" ";
                temp = temp->next;
                if(cnt <= 1){
                    rear = rear->next;
                    cnt++;
                }
            }
        }
    }
};

signed main(){

    // cqueue cq(5);

    // cq.enqueue(1);
    // cq.enqueue(2);
    // cq.enqueue(3);
    // cq.enqueue(4);
    // cq.enqueue(5);

    // cq.first();
    // cq.last();

    // cq.dqueue();
    // cq.dqueue();

    // cq.first();
    // cq.last();

    // cq.peak();

    cqueuell cq;

    cq.enqueuell(1);
    cq.enqueuell(2);
    cq.enqueuell(3);
    cq.enqueuell(4);
    cq.enqueuell(5);

    cq.firstll();
    cq.lastll();

    cq.dqueuell();
    cq.dqueuell();

    cq.firstll();
    cq.lastll();

    cq.peakll();

    return 0;
}