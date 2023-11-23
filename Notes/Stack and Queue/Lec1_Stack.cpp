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

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
    
    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class Stackll {
private:
    Node* top; // Points to the top of the stack

public:
    // Constructor
    Stackll() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmptyll() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void pushll(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int popll() {
        if (isEmptyll()) {
            cout << "Stack underflow\n";
            return -1; // Assuming -1 as an indicator of an empty stack
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    // Function to get the top element of the stack without removing it
    int peekll() {
        if (isEmptyll()) {
            cout << "Stack is empty\n";
            return -1; // Assuming -1 as an indicator of an empty stack
        }
        return top->data;
    }
};

// Example usage
int main() {
    Stackll myStack;

    myStack.pushll(10);
    myStack.pushll(20);
    myStack.pushll(30);

    cout << "Top element: " << myStack.peekll() << endl;

    cout << "Popped element: " << myStack.popll() << endl;
    cout << "Popped element: " << myStack.popll() << endl;

    cout << "Top element: " << myStack.peekll() << endl;

    return 0;
}


