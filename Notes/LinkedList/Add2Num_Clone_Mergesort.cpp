#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
public:
    int data;
    Node *next;
    Node* random;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
        this -> random = NULL;
    }
//    ~Node();
};

void insert(Node* &head, int data){
    Node *new_node = new Node(data);
    new_node -> next = head;
    head = new_node;
}

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Add 2 numbers Linked list
Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertattail(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);
    if(head== NULL){
        head = temp;
        tail = temp;
        return;
    }else{
        tail ->next = temp;
        tail = temp;
    }
}

Node* add(Node* &head1, Node* &head2){
    int carry = 0;
    Node* head = NULL;
    Node* tail = NULL;
    while(head1!=NULL && head2!= NULL){
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        // Create node and insert
        insertattail(head,tail, digit);
        carry = sum/10;
        head1 =head1->next;
        head2= head2->next;
    }
    while(head1!=NULL){
        int sum = carry + head1->data;
        int digit = sum%10;
        // Create node and insert
        insertattail(head,tail, digit);
        carry = sum/10;
        head1 = head1->next;
    }
    while(head2!=NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        // Create node and insert
        insertattail(head,tail, digit);
        carry = sum/10;
        head2 = head2->next;
    }
    while(carry!=0){
        int sum = carry;
        int digit = sum%10;
        // Create node and insert
        insertattail(head,tail, digit);
        carry = sum/10;
    }
    return head;
}

Node* twosum(Node* head1,Node* head2){
    // Step 1-  Reverse input LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);
    // Step 2- Add from left by taking pointers;
    Node* ans = add(head1,head2);
    //Step 3- Again reverse the LL;
    Node* head = reverseLL(ans);
    return head;
}

//Clone a linked list;
// Approach 1 using map
Node* clone(Node* &head){
    // Step - 1 Create a Clone list;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp!=NULL){
        insertattail(cloneHead, cloneTail,temp->data);
        temp = temp->next;
    }

    // Step - 2 Create a map
    unordered_map<Node*,Node*> oldtoNewnode;

    Node* OriginalNode = head;
    Node* cloneNode = cloneHead;
    while(OriginalNode!=NULL && cloneNode!=NULL){
        oldtoNewnode[OriginalNode] = cloneNode;
        OriginalNode = OriginalNode->next;
        cloneNode = cloneNode->next;
    }

    //Step - 3 marking the random pointers
    OriginalNode = head;
    cloneNode = cloneHead;
    while(OriginalNode!=NULL){
        cloneNode ->random = oldtoNewnode[OriginalNode ->random];
        OriginalNode = OriginalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}
// Approach 2 check in GFG without using map;


// Merge Sort
// Tortise and heir method to find middle element in LL
Node* findmid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merges(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp ->next = left;
            temp = left;
            left = left->next;
        }else{
            temp ->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left!=NULL){
        temp ->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp ->next = right;
        temp = right;
        right = right->next;
    }
    dummy = dummy ->next;
    return dummy;
}

Node* mergesort(Node* head){
    //base case
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* mid = findmid(head);

    // Create nodes for left and right parts
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursive Calls
    left = mergesort(left);
    right = mergesort(right);

    // Merge both halves;
    Node * result = merges(left,right);

    return result;
}

// Flatten a linked list
// H.W

int main(){
    Node* head = NULL;
    insert(head, 3);
    insert(head, 9);
    insert(head, 1);
    print(head);
    cout<<" After sorting: "<<"\n";
    mergesort(head);
    print(head);


//    Node* head1 = NULL;
//    Node* head2 = NULL;
//    insert(head1,5);
//    insert(head1, 4);
//    cout<< " Linked list 1 "<<endl;
//    print(head1);
//    insert(head2, 5);
//    insert(head2, 4);
//    insert(head2, 3);
//    cout<< " Linked list 2 \n";
//    print(head2);
//    reverseLL(head2);
//    print(head2);
//    Node* ans = twosum(head1, head2);
//    cout<< " After sum "<<"\n";
//    print(ans);

    return 0;
}
