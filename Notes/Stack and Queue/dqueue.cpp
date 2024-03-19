#include<iostream>
using namespace std;

// Deque using an array -> circular array
// Deque can only work with circular array cause operations will be on both sides
class deque{
public:
    int size;
    int* arr;
    int front;
    int rear;

    // construct
    deque(int value): size(value), arr(new int[value]), front(-1), rear(-1){}

    // operations
    // isFull and isEmpty
    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (front == 0 && rear == size-1) || (front == rear+1);
    }

    // operations
    // insert front
    void insertFront(int value){
        if(isFull()){
            cout<<"Deque is Full";
        }

        if(isEmpty()){
            front = rear = 0;
        }else if(front == 0){
            // I have an element at the rear but from first this is the first element
            front = size-1;
        }else{
            front--;
        }

        arr[front] = value;
    }

    void insertRear(int value){
        if(isFull()){
            cout<<"Deque is full!";
        }

        // again 3 conditions
        if(isEmpty()){
            front = rear = 0;
        }else if(rear == size-1){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = value;
    }

    void deleteFront(){
        if(isEmpty()){
            cout<<"Deque is Empty!!";
        }else{
            int ele = arr[front];
            // again check some conditions here
            
            if(front == size-1){
                front = 0;
            }else if(front == rear){
                front = rear = -1; // to reset
            }else{
                front++;
            }
            cout<<ele;
        }
    }

    void deleteRear(){
        if(isEmpty()){
            cout<<"Deque is empty";
        }
        int ele = arr[rear];
        // conditions
        if(front == rear){
            front = rear = -1;
        }else if(rear == 0){
            rear = size - 1;
        }else{
            rear--;
        }
        cout<<ele;
    }

    void getFront(){
        // if not empt
        cout<<arr[front];
    }

    void getRear(){
        // if not empt
        cout<<arr[rear];
    }
};

// Deuqe using doubly linked list
class node{
public:
    int data;
    node* next;
    node* prev;

    // construct
    node(int data): data(data), next(nullptr), prev(nullptr){}
};

// build the deque class
class dequell{
private:
    node* front;
    node* rear;
public:
    dequell(): front(nullptr), rear(nullptr){}

    // Operations
    // isEmpty
    bool isEmptyll(){
        return front == nullptr;
    }

    // insertfront
    void insertf(int value){
        node* new_node = new node(value);
        if(isEmptyll()){
            front = rear = new_node;
        }else{
            front->prev = new_node;
            new_node->next = front;
            front = new_node; // or front = front->prev
        }
    }

    void insertr(int value){
        node* new_node = new node(value);
        if(isEmptyll()){
            front = rear = new_node;
        }else{
            rear->next = new_node;
            new_node->prev = rear;
            rear = new_node; // or rear = rear->next;
        }
    }

    void getf(){
        cout<<front->data;
    }

    void getr(){
        cout<<rear->data;
    }

    void deletef(){
        if(isEmptyll()){
            cout<<"Deque is empty";
        }else{
            int ele = front->data;
            node* temp = front;
            if(front == rear){
                front = rear = nullptr;
            }else{
                front = front->next;
                temp->next = nullptr;
                front->prev = nullptr;
            }
            cout<<temp->data;
            delete temp;
        }
    }

    void deleter(){
        if(isEmptyll()){
            cout<<"Deque is empty";
        }else{
            int ele = rear->data;
            node* temp = rear;
            if(front == rear){
                front = rear = nullptr;
            }else{
                rear = rear->prev;
                temp->prev = nullptr;
                rear->next = nullptr;
            }
            cout<<temp->data;
            delete temp;
        }
    }
};

signed main(){

    // deque dq(5);

    // dq.insertFront(1);
    // dq.insertFront(2);
    // dq.insertFront(3);
    // dq.insertRear(8);
    // dq.insertRear(9);

    // dq.getFront();
    // dq.getRear();

    // dq.deleteFront();
    // dq.deleteRear();
    // dq.deleteRear();

    // dq.getFront();
    // dq.getRear();


    dequell dq;

    dq.insertf(1);
    dq.insertf(2);
    dq.insertf(3);
    dq.insertr(8);
    dq.insertr(9);

    dq.getf();
    dq.getr();

    dq.deletef();
    dq.deleter();
    dq.deleter();

    dq.getf();
    dq.getr();

    return 0;
}