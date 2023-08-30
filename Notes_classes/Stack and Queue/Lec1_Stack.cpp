#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    // data
     int size;
     int top;
     int *arr;
    // behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top =-1;
    }

    // Making Operations
    // Push, pop, empty, top

    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        }else{
            cout<<"Stack Overflow\n";
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"No element in the stack\n";
        }
    }

    void empty(){
        if(top == -1){
            cout<<"Stack is empty\n";
        }else{
            cout<<"Stack is not empty\n";
        }
    }

    void peak(){
        if(top>=0){
            cout<<"Top element is\t"<<arr[top];
        }else{
            cout<<"Stack is empty\n";
        }
    }

    void print(){
        cout<<"Top of the Stack\n";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<"\n";
        }
        cout<<"Bottom of the Stack\n";
    }
};

// Stack using linked list
class node{
    int data;
    node* next;

    node(int n){
        this->data = n;
        this->next = NULL;
    }

    void insert(node* head, int n){
        node* temp = new node(n);
        temp ->next = head;
        head = temp;
    }
};

class stackll{
    int size;
    int top;
    node* head;
};

template <typename T> T myMax(T x, T y){
    return (x>y)?x : y;
}

int main(){

    cout<<myMax<int>(4,5)<<"\n";
    cout<<myMax<char>('f','a')<<"\n";
    cout<<myMax<double>(9.00,5.34)<<"\n";

    return 0;
}