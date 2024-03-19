#include<iostream>
using namespace std;

// Implementing stack using an array
class stack{
public:
    int size;
    int top;
    int *arr;

    stack(int size): size(size), top(-1), arr(new int[size]){}

    // operatins to be done
    // push
    void push(int ele){
        // stack overflow
        if(top >= size-1){
            cout<<"Stack Overflow";
        }else{
            top++;
            arr[top] = ele;
        }
    }

    // pop
    void pop(){
        // stack underflow
        if(top == -1){
            cout<<"Stack undeflow";
        }else{
            int ele = arr[top];
            top--;
            cout<<ele;
        }
    }

    void seetop(){
        if(top == -1) cout<<"Stack is empty!!";
        else cout<<arr[top];
    }

    void peak(){
        for(int i = top;i>=0;i--){
            cout<<arr[i]<<"\n";
        }
    }
};


// stack using a linked list
// first make the node
struct node{
    int data;
    node* next;
    
    // constructor
    node(int value): data(value), next(NULL){}
};

// stack ll
class stackll {
private:
    node* top; // top pointer cause this is not an array we will deal with pointers here
public:
    // call the stack constructor
    stackll(): top(nullptr){}

    // operations
    bool isEmpty(){
        return top == nullptr; // if top is null then the stack is empty
    }

    void pushll(int value){
        // insert the value into the node
        // and we will not have any stack overflow here cause it is not of a fixed size
        struct node* new_node = new node(value);
        // now point the node
        new_node-> next = top;
        top = new_node;
    }

    void popll(){
        if(isEmpty()){
            cout<<"Stack is empty!!";
        }else{
            node* temp = top; // temporarly to delete
            top = top->next;
            cout<<temp->data;
            delete temp;
        }
    }

    void topll(){
        if(isEmpty()){
            cout<<"Stack is empty!!";
        }else{
            cout<<top->data;
        }
    }

    void peakll(){
        if(isEmpty()){
            cout<<"Stack is Empty!";
        }else{
            node* temp = top;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }
};

signed main(){

    // stack st(4); // an array has been built

    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.pop();
    // st.seetop();
    // st.peak();

    // stack with Linked list
    stackll st;

    st.pushll(5);
    st.pushll(6);
    st.pushll(7);
    st.pushll(8);
    st.popll();
    st.topll();
    st.peakll();

    return 0;
}