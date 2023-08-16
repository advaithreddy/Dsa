#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
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


// Remove dup of sorted list
Node* removedup(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr->next!=NULL){
        if(curr->data != curr->next ->data){
            curr = curr->next;
        }else{
            Node* node1 = curr->next ->next;
            Node* deletenode = curr->next;
            delete deletenode;
            curr->next = node1;
        }
    }
    return head;
}


// Remove of unsorted list
// Approach 1 using loops TC = O(n^2) SC= O(1)
void remove1(Node* head){
    Node* ptr1, *ptr2, *dum;
    ptr1 = head;
    while(ptr1!=NULL&& ptr1 ->next !=NULL){
        ptr2 = ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->data == ptr2->next ->data){
                dum = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dum;
            }else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1 ->next;
    }
}


// Approach 2 Using sorting method TC = O(nlogn) SC = O(1);  bekar approach
void unsortlist(Node* head){
    Node* curr = head;
    Node* index = NULL;
    while(curr!=NULL){
        index = curr->next;
        while(index!=NULL){
            if(curr->data == index->data){
                curr->next = index->next;
                free(index);
                index = curr->next;
            }else{
                index = index->next;
            }
        }
        curr = curr->next;
    }
}


// Approach 3 using hashing TC = O(n) SC = O(n);
void removedupunsortmap(Node* &head){
    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        if(seen.find(curr->data)!=seen.end()){
            prev ->next = curr->next;
            delete curr;
        }else{
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

// Multiply two numbers
int multiply(Node* head1, Node* head2){
    int M = 1000000007;
    int n1 = 0, n2 = 0;
    while(head1 || head2){
        if(head1) {
            n1 = ((n1) * 10) % M + head1->data;
            head1 = head1 ->next;
        }
        if(head2){
            n2 = ((n2)*10)%M + head2->data;
            head2 = head2->next;
        }
    }
    return ((n1%M)*(n2%M))%M;
}


// Sort 0s 1s and 2s
// Using count method TC = O(n) and SC = O(1)
Node* sort012(Node* &head){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            count0++;
        }else if(temp ->data == 1){
            count1++;
        }else{
            count2++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        if(count0!=0){
            temp->data =0;
            count0--;
        }else if(count1!=0){
            temp->data = 1;
            count1--;
        }else{
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}
// Approach 2 Data replacement is not allowed so using change links  TC = O(n) SC = O(1)
void insertattail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}


Node* sortlist(Node* &head){
    Node* head0 = new Node(-1);
    Node* tail0 = head0;
    Node* head1 = new Node(-1);
    Node* tail1 = head1;
    Node* head2 = new Node(-1);
    Node* tail2 = head2;

    Node* curr = head;
    // create separate list for 0 1 and 2
    while(curr!=NULL){
        int val = curr->data;
        if(val == 0){
            insertattail(tail0,curr);
        }else if(val == 1){
            insertattail(tail1, curr);
        }else{
            insertattail(tail2,curr);
        }
        curr = curr->next;
    }
    // merge 3 dummy list
    if(head1->next!=NULL){
        tail0 ->next  = head1 ->next;
    }else{
        tail0->next = head2->next;
    }

    tail1 ->next = head2 ->next;
    tail2 ->next = NULL;

    head = head0 ->next;
    //delete dummy nodes
    delete head0;
    delete head1;
    delete head2;

    return head;
}

// Merge 2 sorted linked lists
Node* solve(Node* head1, Node* head2){
    Node* curr1 = head1;
    Node* next1 = curr1->next;
    Node* curr2 = head2;
    Node* next2 = curr2->next;

    while(next1!=NULL && curr2!=NULL){
        if((curr2->data <= next1 ->data)&& (curr2->data >= curr1->data)){
            curr1 ->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
            }
        }
    }
    return head1;
}

Node* mergesorted(Node* &head1, Node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data <= head2->data){
        return solve(head1, head2);
    }else{
        return solve(head2,head1);
    }
}

//Palindrome linked list
// Approach 1 using vector arr TC = O(n) SC = O(n)
bool checkpalindrome(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}


bool isPalindrome(Node* head){
    vector<int> arr;
    Node* temp = head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkpalindrome(arr);
}

// Approach 2 TC = O(n) SC = O(n);
int getlength(Node* head){
    Node* temp  = head;
    int cnt = 0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool palindrome(Node* head){
    // reverse the second list
    int len = getlength(head);
    int mid = len/2;
    int cnt = 1;
    Node* temp = head;
    while(cnt<mid){
        temp = temp->next;
        cnt++;
    }
    Node* curr = temp->next;
    Node* forward = NULL;
    Node* prev = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    temp->next = NULL;
    // Checking the data
    Node* temp1 = head;
    while(temp1 != NULL && prev !=NULL){
        if(temp1->data != prev->data){
            return false;
        }
        temp1 = temp1->next;
        prev = prev->next;
    }
    return true;
}



int main(){
    Node* head = NULL;
//
//    insert(head, 2);
//    insert(head,1);
//    insert(head,3);
//    insert(head,1);
//    insert(head, 2);
//    insert(head,1);
//    print(head);
//    removedupunsortmap(head);
//    print(head);
//    cout<<" Palindrome checking ...."<<"\n";
//    if(palindrome(head)==true){
//        cout<<" Yes it is palindrome \n";
//    }else{
//        cout<<" No it is not palindrome \n";
//    }
//    cout<<"\n";
//    cout<<"\n";
    Node* head1 = NULL;
    Node* head2 = NULL;
    insert(head1, 2);
    insert(head1,3);
    print(head1);
    insert(head2,2);
    print(head2);
    cout<<" Answer : \n";
    cout<<multiply(head1, head2);

//    cout<<" Sorting...... "<<"\n";
//    Node* head3 = mergesorted(head1, head2);
//    print(head3);
//    Node* ans = removedup(head);
//    print(head);
//    cout<<"Unsorted list ";
//    removedupunsortmap(head);
//    print(head);
//    cout<<" Sorted list using approach 1 \n";
//    sort012(head);
//    print(head);
//    cout<<" Sorted using approach 2\n";
//    sortlist(head);
//    print(head);

    return 0;
}