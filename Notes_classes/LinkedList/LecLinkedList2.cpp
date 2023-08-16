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
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free with data "<<val<<endl;
    }
};


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int length(Node* &head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertdbll(Node* &head, int d){
    Node* node1 = new Node(d);
    node1 -> next = head;
    if(head!=NULL){
        head -> prev = node1;
    }
    head = node1;
}

void inserttail(Node* &head, int d){
    if (head == NULL){
        insertdbll(head, d);
        return;
    }

    Node* node = new Node(d);
    Node* temp = head;
    while(temp->next !=NULL){
        temp= temp->next;
    }
    temp->next = node;
    node-> prev = temp;
}

void insertP(Node* &head, int posi , int d){
    if(posi == 1){
        insertdbll(head, d);
        return;
    }

    Node* temp= head;
    int cnt =1;
    while(cnt<posi-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        inserttail(head, d);
        return;
    }

    Node* node = new Node(d);
    node-> next = temp->next;
    temp->next -> prev = node;
    temp->next = node;
    node-> prev = temp;

}

void deletedbll(Node* &head, int posi){
    if(posi == 1){
        Node* temp = head;
        head = temp-> next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt =1;
        while(cnt<posi){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr->next == NULL){
            prev->next = NULL;
            curr->prev = NULL;
            delete curr;
            return;
        }

        prev -> next = curr->next;
        curr->next -> prev = curr->prev;
        curr->next = NULL;
        curr-> prev = NULL;
        delete curr;
    }
}

int main(){
    fast_io;
    Node* head = NULL;

    insertdbll(head, 12);
    insertdbll(head, 14);
    insertdbll(head, 15);
    print(head);
    inserttail(head, 20);
    print(head);
    int posi;
    cin>>posi;
    insertP(head, posi, 21);
    print(head);
    int pos;
    cout<<"Enter delete "<<endl;
    cin>>pos;
    deletedbll(head, pos);
    print(head);
    cin>>pos;
    deletedbll(head, pos);
    print(head);
    cin>>pos;
    deletedbll(head, pos);
    print(head);



    // serach
//    vector<int>v;
//    int k;
//    cin>>k;
//    //we donot use given data
//    Node* temp=head;
//    while(temp!=NULL){
//        v.push_back(temp->data);
//        temp=temp->next;
//    }
//
//    vector<int>::iterator it;
//    find(v.begin(), v.end(),k);
//    if(it == v.end()){
//        cout<<"NO"<<endl;
//    }else{
//        cout<<"YES"<<endl;
//    }

    return 0;
}