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


void inserttail(Node* &head, int val)
{
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
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


void insertposition(Node* &head,int position, int data){
    if(position == 1){
        insert(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt<position -1){
        temp = temp->next;
        cnt++;
    }

    Node* nodeinsert = new Node(data);
    nodeinsert-> next = temp->next;
    temp->next = nodeinsert;
}

void deleteNode(Node* &head, int position){
    if(position==1){
        Node* temp = head;
        head  = head -> next;
        temp-> next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr-> next;
            cnt++;
        }

        // we got the position
        prev->next = curr-> next;
        curr-> next = NULL;
        delete curr;
    }
}

void deletnthnodefromback(Node* &head, int n){
    // Basic Approach
    // Take a dummy node and calculate the whole size of the list
    Node* dummy1 = head;
    int cnt = 1;
    while(dummy1!=NULL){
        dummy1 = dummy1->next;
        cnt++;
    }
    // Now cnt = 5 , so do cnt - n ==>   5 - 2 = 3;
    int cnt1 = 1;
    Node* dummy2 = head;
    while(cnt1<(cnt-n)){
        dummy2 = dummy2->next;
        cnt1++;
    }
    // Now cnt1 is pointing 1->2->3->4->5
    //                            t                <- now it is pointing the required node
    Node* temp = dummy2->next;
    dummy2 ->next = dummy2->next->next;
    temp ->next = NULL;
    delete temp;
}

    Node* addTwoNumbers(Node* l1, Node* l2) {
        // Base case
        // if(l1== NULL || l2 == NULL){
        //     return l1;
        // }

        // Take 1st number
        int num1 =0;
        while(l1!=nullptr){
            num1 = num1 * 10 + l1->data;
            l1 = l1->next;
        }
        // Take 2nd Number
        int num2=0;
        while(l2!=nullptr){
            num2 = num2 * 10 + l2->data;
            l2 = l2->next;
        }
        // Reverse the num
        int revnum1 = 0;
        while(num1!=0){
            int d1 = num1%10;
            revnum1 = revnum1 * 10 + d1;
            num1 /= 10;
        }
        int revnum2 = 0;
        while(num2!=0){
            int d2 = num1%10;
            revnum2 = revnum2 * 10 + d2;
            num2 /= 10;
        }
        // We made the sum
        int sum = revnum1 + revnum2;

        // Converting the num into a linked list
        Node* head = nullptr;
        Node* curr = NULL;

        while(sum!=0){
            int digit = sum%10;
            if(head == NULL){
                head = new Node(digit);
                curr = head;
            }else{
                curr ->next = new Node(digit);
                curr = curr->next;
            }
            sum /= 10;
        }
        Node* dummyans = new Node(0);
        return (head == NULL)? dummyans : head;
    }

int sizeofll(Node* head){
    int size = 0;
    while(head!=NULL){
        head = head->next;
        size++;
    }
    return size;
}

int main(){
    fast_io;
//    Node *head = NULL;
//    Node *head1 = NULL;
//
//    insert(head, 3);
//    insert(head, 4);
//    insert(head, 2);
//    cout<<" Your l1 List: \n";
//    print(head);
//    insert(head1, 4);
//    insert(head1, 6);
//    insert(head1, 5);
//    cout<<" Your l2 List: \n";
//    print(head1);
//    cout<<"Addition of the lists: \n";
//    Node* ans = addTwoNumbers(head,head1);
//    print(ans);
//    int num1 = 243;
//    int num2 = 564;
//    int revnum1 = 0;
//    while(num1!=0){
//        int d1 = num1%10;
//        revnum1 = revnum1 * 10 + d1;
//        num1 /= 10;
//    }
//    int revnum2 = 0;
//    while(num2!=0){
//        int d2 = num2%10;
//        revnum2 = revnum2 * 10 + d2;
//        num2 /= 10;
//    }
//    cout<<revnum2;
//    // We made the sum
//    int sum = revnum1 + revnum2;
//    cout<<sum<<endl;
    Node* head = NULL;
    insert(head,1);
    insert(head,3);
    insert(head,2);
    insert(head,4);
    insert(head,5);
    cout<<sizeofll(head)<<endl;


//    cout<<"Insertion at head: ";
//    print(head);
//    inserttail(head, 6);
//    inserttail(head, 8);
//    cout<<"Insertion at tail: ";
//    print(head);
//    int posi;
//    cout<<"Enter the position : ";
//    cin>>posi;
//    insertposition(head, posi,14);
//    cout<<"Insert at position "<<posi<<" is : ";
//    print(head);
//    deleteNode(head,1);
//    print(head);
//    deleteNode(head, 4);
//    print(head);


//    int cnt,val,pos;
//    int exp;
//    cout<<"Enter 1 to insert at head, 2 to insert at tail, 3 to insert in middle"<<endl;
//    cin>>exp;
//    switch(exp){
//        case 1:
//            cout<<"Enter how many values you want to insert : ";
//            cin>>cnt;
//            for(int i=1;i<=cnt;++i){
//                cout<<"Enter the value you want to insert: ";
//                cin>>val;
//                insert(head,val);
//            }
//            cout<<"After you insertion: ";
//            print(head);
//            break;
//        case 2:
//            cout<<"Enter how many values you want to insert : ";
//            cin>>cnt;
//            for(int i=1;i<=cnt;++i){
//                cout<<"Enter the value you want to insert: ";
//                cin>>val;
//                inserttail(head,val);
//            }
//            cout<<"After you insertion: ";
//            print(head);
//            break;
//        case 3:
//            cout<<"Enter how many values you want to insert : ";
//            cin>>cnt;
//            for(int i=1;i<=cnt;++i){
//                cout<<"Enter the value you want to insert: ";
//                cin>>val;
//                cout<<"Enter where you want to insert : ";
//                cin>>pos;
//                insertposition(head,pos,val);
//            }
//            cout<<"After you insertion: ";
//            print(head);
//            break;
//        default:
//            cout<<"Invalid choice "<<endl;
//            break;
//    }

    return 0;
}