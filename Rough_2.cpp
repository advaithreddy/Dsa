#include<bits/stdc++.h>
#define ll long long
#define f0(a,b) for(i=a;i<b;i++)
#define f1(i,a,b) for(i=a;i<b;++i)
#define tst int t; cin>>t
#define ps push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;



/* Author
		Advaith
*/

bool isPermutation(char input1[], char input2[]) {
    // Write your code here

    // Frequency array approach

    /*
    1. Create an array arr[256] -> ASCII values size;
    2. For input1 increase arr[input[i]]++;
    3. For input2 decrease the frequency;
    4. check if its 0 and print accordingly
    */


    int arr[256]; // ASCII values size
    for(int i=0;i<256;i++){
        arr[i] = 0;
    }


    // For str 1
    for(int i=0;input1[i]!='\0';++i){
        arr[input1[i]]++;
    }

    //str 2
    for(int i=0;input2[i]!='\0';++i){
        arr[input2[i]]++;
    }

    for(int i=0;i<256;i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
}

void swap(int *a1, int *a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}


void selectionsort(int *a , int n){
    int i;
    for(i=0;i<n-1;i++){
        int mini =i;
        for(int j=i+1;j<n;++j){
            if(a[mini]>a[j]){
                mini = j;
            }
        }


        if(mini != i){
            swap(&a[i], &a[mini]);
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long maxSubarraySum(int arr[], int n)
{
    int sum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxsum = max(sum, maxsum);
        if(sum < 0){
            sum = 0;
        }
    }
    if(maxsum>0){
        return maxsum;
    }else{
        return 0;
    }
}

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


int main(){
    fast_io;
    tst;
    while(t--){
         int l;
         string str;
         cout<<"Enter the value :"<<endl;
         cin>>l;
         cout<<"Enter the path : "<<endl;
         cin>>str;
         int up = 0;
         int cnt = 0;
         for(int i=0;i<l;i++){
             if (str[i]=='U') {
                 up++;
             }
             else {
                 if (up==0){
                     cnt++;
                 }
                 up--;
             }
         }
         if (up<0) {
             cnt--;
         }
         cout<<cnt<<endl;
    }


//    Node *head = NULL;
//
//
//    insert(head, 1);
//    insert(head, 2);
//    insert(head, 4);
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

    return 0;
}