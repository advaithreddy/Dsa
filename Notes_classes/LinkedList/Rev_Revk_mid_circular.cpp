#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node {
public:
    int data;
    Node *next;
    Node(int d){
        this-> data = d;
        this -> next = NULL;
    }

    ~Node();
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
    cout<<endl;
}

void solverecu(Node* &head, Node* curr, Node* prev){
    if(head == NULL){
        head = prev;
        return;
    }

    solverecu(head, curr-> next, prev);
    curr-> next = prev;
}


void reverse(Node* &head){

    if(head == NULL || head-> next == NULL){
        cout<<"No need to reverse \n Anyway ";
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr!=NULL){
        forward = curr-> next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

Node* recurreverse(Node* &head){
    if(head == NULL || head-> next == NULL){
        cout<<" No need to reverse \n anyway ";
    }

    Node* node = recurreverse(head->next);
    node-> next = head;
    head-> next = NULL;
    return head;
}

int getLength(Node* head){
    Node* temp = head;
    int cnt =0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int printpos(Node* &head, int p){
    Node* temp = head;
    int c = 1;
    while(c<p){
        temp = temp-> next;
        c++;
    }
//    head = temp;
//    while(temp!=NULL){
//        cout<<temp-> data<<" ";
//        temp = temp->next;
//    }
    return temp->data;
}

int fastslow(Node* head){
    if(head == NULL || head-> next == NULL){
        return head->data;
    }

    if(head -> next -> next==NULL){
        return head->next->data;
    }

    Node* fast = head->next;
    Node* slow = head;
    while(fast !=NULL){
        fast = fast-> next;
        if(fast !=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data-1;
}


Node *kReverse(Node* head, int k){
    // base case
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* forward = NULL;
    Node* prev = NULL;
    int cnt = 0;
    while(curr !=NULL && cnt < k){
        forward = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    // Now recursion call time
    if(head != NULL){
        head -> next = kReverse(forward, k);
    }

    // return this prev as head
    return prev;
}

bool circular(Node* &head){
    // Empty list then return true
    if(head == NULL){
        return true;
    }
    // If only one node ;
    if(head -> next == NULL){
        return false;
    }

    // Multiple nodes i.e., > 1 nodes ;
    Node* temp = head->next;
    while(temp!= head && temp!= NULL){
        temp = temp-> next;
    }
    if(temp == NULL){
        return false;
    }
    if(temp == head){
        return true;
    }
    return false;
}

// Inserttion in circular list
void push(Node* head, int data)
{

    // Create a new node and make head
    // as next of it.
    Node* ptr1 = new Node(data);

    // If linked list is not NULL then
    // set the next of last node
    if (head != NULL) {
        // Find the node before head and
        // update next of it.
        Node* temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else

        // For the first node
        ptr1->next = ptr1;

    head = ptr1;
}


int main(){
    Node* head = NULL;
//
//    insert(head, 1, 1);
//    insert(head, 2, 2);
//    insert(head, 3, 3);
//    insert(head, 4, 4);
//    insert(head, 5, 5);
//    insert(head, 6, 6);
//    cout<<"Linked list "<<endl;
//    print(head);
//    reverse(head);
//    cout<<"After reverse "<<endl;
//    print(head);
//    int middle = getLength(head)/2 + 1;
//    int ans = printpos(head, middle);
//    cout<<" Middle node value "<<ans;
//    cout<<endl;
//
//    int k;
//    cout<<"Enter the nodes value : \n";
//    cin>>k;
//    cout<<"Reversed by k nodes \n";
//    head = kReverse(head, k);
//    print(head);
    push(head, 10);
    push(head, 15);
    push(head, 20);
    push(head, 21);
    push(head, 80);
    cout<<"Checking if your linked list is circular or not \n";
    if(circular(head)){
        cout<<"Yes is circular \n";
    }else{
        cout<<"No it is not circular \n";
    }

    return 0;
}