#include<bits/stdc++.h>
using namespace std;

// Linked List C++


// Structure for Single Linked List
struct node{
    int data;
    node* next;

    node(int value){
        this->data = value;
        this->next = nullptr;
    }
};


class SingleLL{
private:
    node* head;
public:
    SingleLL(){
        this->head = nullptr;
    }

    void append(int data){
        node* new_node = new node(data);

        if(head == nullptr){
            head = new_node;
        }else{
            node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }


    // head -> data | 1 | next -> data | 2 | next -> data | 3 | next -> data | 4 | next -> null
    void display(){
        node* temp = head;
        cout<<"head -> ";
        while(temp != nullptr){
            cout<<" data | ";
            cout<<temp->data;
            cout<<" | next -> ";
            temp = temp->next;
        }
        cout<<" null";
        cout<<endl;
    }


    
};


// Structure for Doubly Linked list
struct Node
{
    string data;
    Node* next;
    Node* prev; 

    Node(string value){
        this->data = value;
        this->next = nullptr;
        this->prev = NULL;
    }
};

class DoublLL{
private:
    Node* head;
    Node* tail;
public:
    DoublLL(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    void append(string data){
        Node* new_node = new Node(data);

        if(head == nullptr){
            head = new_node;
            tail = new_node;
        }else{
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            tail = new_node;
        }
    }

    void display(){
        Node* temp = head;
        cout<<"null ";
        while(temp != nullptr){
            cout<<"<- prev | ";
            cout<<" data : ";
            cout<<temp->data;
            cout<<" | next -> ";
            temp = temp->next;
        }
        cout<<" null";
        cout<<endl;
    }
    // null <- next | data : Popi | prev -> new_node or null
    void displayback(){
        Node* temp = tail;=
        cout<<"null ";
        while (temp!= nullptr)
        {
            cout<<"<- next | ";
            cout<<" data : ";
            cout<<temp->data;
            cout<<" | prev -> ";
            temp = temp->prev;
        }
        cout<<" null";
        cout<<endl;
    }
};



int main() {
    cout<<"________________ SINGLE LINKED LIST ________________\n";
    // Single linked list
    SingleLL ll;
    // head -> nullptr;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    // 1->2->3->4
    ll.display();
    cout<<endl;

    cout<<"_____________________ DOUBLE LINKED LIST _____________________\n";
    // Double Linked List
    DoublLL dll;
    // head -> nullptr

    dll.append("Ryan");
    dll.append("Advath");
    dll.append("Jhon");
    dll.append("POpi");
    cout<<"From forward\n";
    // Ryan -> Advaih -> Jhon -> popi
    dll.display();
    cout<<endl;
    cout<<"From Backward\n";
    // Popi -> Jhon -> Advaith -> Ryan
    dll.displayback();


    return 0;
}
