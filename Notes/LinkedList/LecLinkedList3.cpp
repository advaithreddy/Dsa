#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory got free at "<<val<<endl;
    }
};

void insertcll(Node* &tail, int element, int n){
    // Just assuming the element will be in the list
    if(tail == NULL){
        Node* node1 = new Node(n);
        tail = node1;
        node1 -> next = node1;
    }else{
        // non empty list assume element is present
        Node* curr = tail;
        while (curr-> data != element){
            curr = curr -> next;
        }

        // if come out of this loop then we founfd the element
        Node* temp = new Node(n);
        temp-> next = curr-> next;
        curr -> next = temp;
    }
}

void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    do {
        cout<<tail->data<<" -> ";
        tail = tail-> next;
    }while(tail != temp);
    cout<<endl;
}

void deleten(Node* &tail, int v){
    //empty list
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }else{
        // non empty
        // Assuming val present in linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != v){
            prev = curr;
            curr = curr-> next;
        }
        prev -> next = curr-> next;

        // 1 Node ll
        if(curr == prev){
            tail = NULL;
        }
        // 2 Node ll
        if(tail == prev){
            tail = prev;
        }
        curr-> next = NULL;
        delete curr;
    }

}

int main(){
    fast_io;
    Node* tail = NULL;

    insertcll(tail,3,14);
    print(tail);
    deleten(tail, 14);
    print(tail);



    return 0;
}