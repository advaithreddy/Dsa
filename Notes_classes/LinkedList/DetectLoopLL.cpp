#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0)

class Node {
public:
    int data;
    Node *next;
    Node(int d){
        this-> data = d;
        this -> next = NULL;
    }
};

void insert(Node* &head, int p, int v){
    if(p==1){
        Node* node = new Node(v);
        node -> next = head;
        head = node;
        return;
    }
    Node* temp = head;
    int cnt=1;
    while(cnt<p-1){
        temp = temp->next;
        cnt++;
    }
    Node* node1 = new Node(v);
    node1 -> next = temp -> next;
    temp-> next = node1;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp-> next;
    }
    cout<<"NULL";
    cout<<endl;
}


// Approach 1 Basic TC = O(n) SC = O(n);
bool detectloop(Node* &head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited[temp] == true){
            cout<< "Present at "<<temp->data<<"\n";
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Approcah 2 Floyds Loop detection algorithm TC = O(n) SC = (1)
Node* loopdetect(Node* &head){
    // Tyep of base case;
    if( head == NULL){
        return NULL;
    }

    Node* rabbit = head;
    Node* turtle = head;
    while(turtle !=NULL && rabbit!=NULL){
        rabbit = rabbit->next;
        if(rabbit!= NULL){
            rabbit = rabbit->next;
        }
        turtle = turtle -> next;
        if(rabbit == turtle){
            return rabbit;
        }
    }
    return NULL;
}

// Approaach 3 Floyd first node TC = O(n) SC=(1)
Node* floydfirstnode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* inter = loopdetect(head);
    Node* turtle = head;
    while(turtle!=inter){
        turtle = turtle->next;
        inter = inter->next;
    }
    return turtle;
}

void removeloop(Node* &head){
    if(head == NULL){
        return;
    }
    if(head->next == head){
        head->next = NULL;
    }
    Node* start = floydfirstnode(head);
    Node* temp =start;
    while(temp->next != start){
        temp = temp->next;
    }
    temp ->next = NULL;
}

int main(){
    Node* head = NULL;
    insert(head, 1, 1);
    insert(head, 2, 3);
    insert(head, 3, 4);
    print(head);
    head ->next ->next = head->next;
    if(loopdetect(head) != NULL){
        cout<<"Cycle is present\n";
    }else{
        cout<< "We dont have a cycle \n";
    }
    Node* loop = floydfirstnode(head);
    cout<< "First node of the loop is "<<loop->data<<"\n";
    removeloop(head);
    print(head);
    return 0;
}