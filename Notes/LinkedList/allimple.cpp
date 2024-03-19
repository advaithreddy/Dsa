#include<iostream>
using namespace std;

// struct for the node for sll and circular ll
struct node{
    int data;
    node* next;

    // construct
    node(int value): data(value), next(nullptr){}
};

// single linked list
class singlell{
private:
    node* head;

public:
    singlell(): head(nullptr){}

    // operations -> 
    // insert at the beginning
    // if i write these functions outside class then i need to send head as an argument
    void insertAtHeadSll(int data){
        node* new_node = new node(data);
        if(head == nullptr){
            head = new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }

    // delete
    void deleteAtHeadSll(){
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int position){
        if(position == 1){
            deleteAtHeadSll();
            return;
        }

        int cnt = 1;
        node* curr = head;
        node* prev = nullptr;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }


    void peakSll(){
        node* temp = head;
        while(temp != nullptr){
            cout<<temp->data;
            if(temp->next != nullptr){
                cout<<" -> ";
            }
            temp = temp->next;
        }
        cout<<endl;
    }

    void insertAtTailSll(int data){
        node* new_node = new node(data);
        if(head == nullptr){
            head = new_node;
            return;
        }

        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insertAtPosition(int data,int position){
        if(position == 1){
            insertAtHeadSll(data);
            return;
        }

        node* new_node = new node(data);
        node* temp = head;
        int cnt = 1;
        while(cnt < (position-1)){
            temp = temp->next;
            cnt++;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }
};

// circular single linked list
class circularll{
private:
    node* head;
public:
    circularll(): head(nullptr){}

    // operations
    // insert at head
    void insertAtHeadCll(int data){
        node* new_node = new node(data);
        if(head == nullptr){
            new_node->next = new_node;
        }else{
            node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            new_node->next = head;
            temp->next = new_node;
        }
        head = new_node;
    }

    void insertAtTailCll(int data){
        node* new_node = new node(data);
        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }


    void insertAtPositionCll(int data, int position){
        if(position == 1){
            insertAtHeadCll(data);
            return;
        }

        node* new_node = new node(data);
        int cnt = 1;
        node* temp = head;
        while(cnt < (position - 1)){
            temp = temp->next;
            cnt++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void peakCll(){
        node* fixed = head;
        node* move = head;
        do{
            cout<<move->data;
            if(move->next != fixed){
                cout<<" -> ";
            }
            move = move->next;
        }
        while(move != fixed);
        cout<<endl;
    }

    void deleteAtPositionCll(int position){
        int cnt = 1;
        node* curr = head;
        node* prev = nullptr;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
};

// strcuture for doubly linked list
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data): data(data), next(nullptr), prev(nullptr){}
};

// doubly linked list
class doublell{
private:
    Node* head;
public:
    doublell(): head(nullptr){}

    // operations
    // insert at head and insert at tail
    void insertAtHeadDll(int data){
        Node* new_node = new Node(data);
        if(head != nullptr){
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
    }

    void insertAtTailDll(int data){
        Node* new_node = new Node(data);
        if(head == nullptr){
            new_node->next = head;
            new_node->prev = head;
            head = new_node;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    // insert at position
    void insertAtPositionDll(int data, int position){
        if(position == 1){
            insertAtHeadDll(data);
            return;
        }

        int cnt = 1;
        Node* temp = head;
        while(cnt < (position-1)){
            temp = temp->next;
            cnt++;
        }
        if(temp->next == nullptr){
            insertAtTailDll(data);
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    // delete
    void deleteAtPositionDll(int position){
        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
    }

    void peakDll(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data;
            if(temp->next != nullptr){
                cout<<" -> ";
            }
            temp = temp->next;
        }
        cout<<endl;
    }
};

// circulat doubly linked list
class circulardll{
private:
    Node* head;
public:
    circulardll(): head(nullptr){}

    // operations
    // insert at head
    void insertAtHeadCdll(int data){
        Node* new_node = new Node(data);
        if(head == nullptr){
            new_node->next = new_node;
            new_node->prev = new_node;
        }else{
            Node* tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            new_node->next = head;
            head->prev = new_node;
            tail->next = new_node;
            new_node->prev = tail;
        }
        head = new_node;
    }

    void insertAtTailCdll(int data){
        Node* new_node = new Node(data);
        if(head == nullptr){
            new_node->next = head;
            new_node->prev = head;
            head = new_node;
        }else{
            Node* tail = head;
            while(tail->next != head){
                // or simply tail = head->prev;
                tail = tail->next;
            }
            new_node->next = tail->next;
            tail->next = new_node;
            new_node->prev = tail;
            head->prev = new_node;
        }
    }

    int sizeCdll(){
        int cnt = 0;
        Node* fixed = head;
        Node* temp = head;
        do{
            temp = temp->next;
            cnt++;
        }
        while(temp != fixed);
        return cnt;
    }

    void insertAtPositionCdll(int data, int position){
        if(position==1){
            insertAtHeadCdll(data);
            return;
        }
        int size = sizeCdll();
        if(position == size + 1){
            insertAtTailCdll(data);
            return;
        }

        Node* new_node = new Node(data);
        Node* temp = head;
        int cnt = 1;
        while(cnt < (position-1)){
            temp = temp->next;
            cnt++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteAtPositionCdll(int position){
        Node* prev = nullptr;
        Node* curr = head;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
    }

    void peakCdll(){
        Node* fixed = head;
        Node* temp = head;
        if(head != nullptr){
            do{
                cout<<temp->data;
                if(temp->next != fixed){
                    cout<<" -> ";
                }
                temp = temp->next;
            }while(temp != fixed);
        }else{
            cout<<"Nothing to show";
        }
        cout<<endl;
    }
};


signed main(){

    // // Singly linked list
    // singlell sl;
    // sl.insertAtHeadSll(2);
    // sl.insertAtHeadSll(1);
    // sl.insertAtTailSll(3);
    // sl.peakSll();

    // sl.deleteAtHeadSll();
    // sl.peakSll();

    // sl.insertAtHeadSll(4);
    // sl.peakSll();

    // sl.insertAtPosition(5,2);
    // sl.insertAtPosition(6,3);
    // sl.peakSll();

    // sl.deleteAtPosition(3);
    // sl.peakSll();

    // circularll cl;
    // cl.insertAtHeadCll(4);
    // cl.insertAtHeadCll(3);
    // cl.insertAtHeadCll(5);
    // cl.peakCll();

    // cl.insertAtTailCll(10);
    // cl.peakCll();

    // cl.insertAtPositionCll(19,5);
    // cl.insertAtPositionCll(33,3);
    // cl.peakCll();

    // cl.deleteAtPositionCll(2);
    // cl.deleteAtPositionCll(4);
    // cl.peakCll();

    // doublell dl;
    // dl.insertAtHeadDll(4);
    // dl.insertAtHeadDll(3);
    // dl.insertAtHeadDll(5);
    // dl.peakDll();

    // dl.insertAtTailDll(10);
    // dl.peakDll();

    // dl.insertAtPositionDll(19,5);
    // dl.insertAtPositionDll(33,3);
    // dl.peakDll();

    // dl.deleteAtPositionDll(2);
    // dl.deleteAtPositionDll(4);
    // dl.peakDll();

    circulardll cdl;
    cdl.insertAtHeadCdll(4);
    cdl.insertAtHeadCdll(3);
    cdl.insertAtHeadCdll(5);
    cdl.peakCdll();

    cdl.insertAtTailCdll(10);
    cdl.peakCdll();

    cdl.insertAtPositionCdll(19,5);
    cdl.insertAtPositionCdll(33,3);
    cdl.peakCdll();

    cdl.deleteAtPositionCdll(2);
    cdl.deleteAtPositionCdll(4);
    cdl.peakCdll();

    return 0;
}