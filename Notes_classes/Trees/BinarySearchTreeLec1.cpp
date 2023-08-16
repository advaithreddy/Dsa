#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class treenode{
public:
    int data;
    treenode* left;
    treenode* right;


    treenode(int d){
        data = d;
        left = right = NULL;
    }
};
typedef treenode tn;

void inorder(treenode* root){
    if(root == nullptr)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Implementation of BST
treenode* insertintoBST(treenode* root, int d){
    if(root == nullptr){
        root = new treenode(d);
        return root;
    }

    if(d > root->data){
        root->right = insertintoBST(root->right, d);
    }else{
        root->left = insertintoBST(root->left , d);
    }
    return root;
}

void takeinput(treenode* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertintoBST(root, data);
        cin>>data;
    }
}

void levelOrder(treenode* root){
    queue<treenode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()){
        treenode* front = q.front();
        q.pop();

        if(front == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }
    }
}

// Search in BST Bool;
bool BSTsearch(treenode* root, int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k) {
        return true;
    }else if(root->data > k){
        return BSTsearch(root->left, k);
    }else{
        return BSTsearch(root->right, k);
    }
}

// Iterative way
//bool search(treenode* root, int k){
//    treenode* temp = root;
//    while(temp!=NULL){
//        if(temp->data == k)
//            return true;
//
//        if(temp->data > k){
//            temp = temp->left;
//        }else{
//            temp = temp->right;
//        }
//    }
//    return false;
//}

// Min max Elemnent in a BST
pair<treenode*,treenode*> MinMax(treenode* root){
    if(root == NULL){
        pair<treenode*,treenode*> p = make_pair(nullptr, nullptr);
        return p;
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    treenode* lefttree = root;
    treenode* righttree = root;
    while(lefttree->left!= nullptr){
        lefttree = lefttree->left;
    }
    while(righttree->right!= nullptr){
        righttree = righttree->right;
    }
    return make_pair(lefttree, righttree);
}

// Deletion In BST
treenode* minVal(treenode* root){
    treenode* temp = root;
    while(temp->left!= nullptr){
        temp = temp->left;
    }
    return temp;
}
treenode* deletefromBST(treenode* root, int x){
    // base case
    if(root == nullptr){
        return nullptr;
    }

    // Main Method
    if(root->data == x){
        // Deletion Code
        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root->left != nullptr && root->right == nullptr){
            treenode* temp = root->left;
            delete root;
            return temp;
        }

        if(root->right != nullptr && root->left == nullptr){
            treenode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        // Min using PS: You can use any method
        if(root->left != nullptr && root->right != nullptr){
            int change = minVal(root->right) -> data;
            root->data = change;
            root->right = deletefromBST(root->right, change);
            return root;
        }

    }else if(root->data > x)
    {
        root->left = deletefromBST(root->left, x);
        return root;
    }else
    {
        root->right = deletefromBST(root->right, x);
        return root;
    }
}

// Valid BST
bool recisBST(treenode* &root, int min, int max){
    // base case
    if(root == nullptr){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = recisBST(root->left,min,root->data);
        bool right = recisBST(root->right,root->data, max);
        return left && right;
    }
    return false;
}

bool isBst(treenode* root){
    return recisBST(root, INT_MIN, INT_MAX);
}

// Kth Smallest
int solvekth(treenode* root, int &i, int k){
    // base case
    if(root == nullptr)
        return -1;

    // L
    int left = solvekth(root->left, i, k);
    if(left!=-1)
        return left;

    // N
    i++;
    if(i==k)
        return root->data;

    // R
    return solvekth(root->right, i, k);
}

int kthsmallest(treenode* root, int k){
    int i =0;
    return solvekth(root, i, k);
}

// kth largest
int sizeofBST(treenode* root){
    if(root == nullptr)
        return 0;

    int left = sizeofBST(root->left);
    int right = sizeofBST(root->right);
    return 1 + left + right;
}

int solvelarge(treenode* root, int &i, int k){
    // base case
    if(root == nullptr)
        return -1;

    // L
    int left = solvekth(root->left, i, k);
    if(left!=-1)
        return left;

    // N
    i++;
    if(i==k)
        return root->data;

    // R
    return solvekth(root->right, i, k);
}
int kthlargest(treenode* root, int k){
    int n = sizeofBST(root);
    int i = 0;
    int newk = n-k + 1;
    return solvelarge(root, i, newk);
}

// predecessor and Successor of an element By Inorder Traversal
pair<int,int> predSucc(treenode* root, int key){
    // First make a temp node
    treenode* temp = root;
    int pred = -1, succ = -1;
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;               // Cause this can be the succ of the key Just think advaith its easy
            temp = temp->left;
        }else{
            pred = temp->data;
            temp = temp->right;              // Same when you are moving to the right this can be the pred of the key
        }                                    // We dont know and we cant take the chance
    }

    // Now we found the key node so if it is a parent of two children then we need to find the max and min value from subtree
    treenode* leftTree = temp->left;
    // Imagine everything is imagination in trees same as linked lists
    while(leftTree != nullptr){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    treenode* rightTree = temp->right;

    while(rightTree != nullptr){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    return {pred, succ};
}

// LCA in a BST
treenode* LCAinBST(treenode* root, treenode* n1, treenode* n2){
    // base case
    if(root == nullptr)
        return nullptr;

    // 1st Condition
    if(root->data < n1->data && root->data < n2->data)
        return LCAinBST(root->left, n1, n2);

    if(root->data > n1->data && root->data > n2->data)
        return LCAinBST(root->right, n1, n2);

    return root;
}

// 2 Sum BST
void sum2(treenode* root, vector<int>& ans){
    if(root == nullptr){
        return;
    }

    sum2(root->left,ans);
    ans.push_back(root->data);
    sum2(root->right, ans);
}

bool twosumBST(vector<int>& ans, int k){
    int i = 0;
    int j = ans.size()-1;
    while(i<j){
        if(ans[i] + ans[j] == k){
            return true;
        }else if(ans[i] + ans[j] > k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

// Flatten a BST into a sorted list
treenode* FlattenBST(treenode* root){
    vector<int> ans;
    sum2(root, ans);
    int n = ans.size();
    treenode* head = new treenode(ans[0]);
    treenode* curr = head;
    for(int i=1;i<n;i++){
        treenode* temp = new treenode(ans[i]);
        curr->left = nullptr;
        curr->right = temp;
        curr = temp;
    }
    // Now we have reached the final node
    curr->left = nullptr;
    curr->right = nullptr;
    return head;
}

void printLL(treenode* head){
    while(head!= nullptr){
        cout<<head->data<<" -> ";
        head = head->right;
    }
    cout<<" NULL";
}

// BST to Balanced BST
/* Balanced Bst The height of left + height of right <= 1
 *                       1
 *                     /   \
 *                    2     3
 *                  /  \   /  \
 *                4     5 6    7
 */
treenode* balBST(int s, int e, vector<int> ans){
    if(s>e){
        return nullptr;
    }

    int mid = (s+e) >> 1;
    treenode* root = new treenode(ans[mid]);
    root->left = balBST(s,mid-1,ans);
    root->right = balBST(mid+1,e,ans);
    return root;
}
treenode* BalancedBST(treenode* root){
    vector<int> ans;
    sum2(root, ans);
    return balBST(0,ans.size()-1,ans);
}

// Preorder Traversal to BST
treenode* solvepreBST(vector<int>& arr, int mini, int maxi , int& i){
    if(i>=arr.size())
        return nullptr;

    if(arr[i] < mini || arr[i] > maxi)
        return nullptr;

    treenode* root = new treenode(arr[i++]);
    root->left = solvepreBST(arr, mini, root->data, i);
    root->right = solvepreBST(arr, root->data, maxi, i);
    return root;
}
treenode* pretoBST(vector<int> arr){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solvepreBST(arr, mini, maxi, i);
}

// Merge Two BST
void inordersolve(treenode* &root,vector<int> &ans){
    if(root== nullptr)
        return ;

    inordersolve(root->left, ans);
    ans.push_back(root->data);
    inordersolve(root->right, ans);
}

vi merge(vi& a, vi& b){
    vi res(a.size() + b.size());

    int i = 0, j =0, k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            res[k++] = a[i];
            i++;
        }else{
            res[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        res[k++] = a[i];
        i++;
    }

    while(j<b.size()){
        res[k++] = b[j];
        j++;
    }

    return res;
}

tn* buildMergeBST(int s, int e, vi& arr){
    if(s>e)
        return nullptr;

    int mid = (s+e) / 2;
    tn* root = new tn(arr[mid]);
    root->left = buildMergeBST(s,mid-1,arr);
    root->right = buildMergeBST(mid+1, e, arr);
    return root;
}

tn* mergeBST(tn* root1 , tn* root2){
    vi a;
    vi b;
    inordersolve(root1, a);
    inordersolve(root2, b);

    vi mergedarray = merge(a, b);
    return buildMergeBST(0, mergedarray.size()-1, mergedarray);
}

// Largest BST in a Binary Tree
class info{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solveBST(tn *root, int& ans){
    // base case
    if(root == nullptr)
        return {INT_MIN, INT_MAX, true, 0};

    // Now we have MIN, MAX, valid, size ,_ answer
    // Through left subtree
    info left = solveBST(root->left, ans);
    // Right Subtree
    info right = solveBST(root->right, ans);
    // Now we will do these operations in left and right subtree
    // Imagine we have gone to the last node in the left subtree
    // mark it as currnode
    info currnode;

    // Now calculate the Values
    currnode.size = left.size + right.size + 1;  // So we got 1 here {-, -, -, 1}
    currnode.maxi = max(root->data, right.maxi);  // {-, as rep, -, 1};
    currnode.mini = min(root->data, left.mini); // We are calculating mini from left cause

    // Next is validity check
    // 4 conditions
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        // If satisfy all these conditions then it is valid
        currnode.isBST = true;
    }else{
        currnode.isBST = false;
    }

    // Update the answer
    if(currnode.isBST){
        ans = max(ans, currnode.size);
    }

    return currnode;   // So by the end of the function we return {final mini, final maxi, final, bool , size}
    // we only need size in this
}

treenode* Buildtree(treenode* root){
    cout<<"Enter the data: \n";
    int data;
    cin>>data;
    root = new treenode(data);
    // Now we have created the root mode now ny using recursion we need to build the left and right child
    // Null Case
    if( data == -1){
        return NULL;
    }
    // Left
    cout<<"Enter the data for inserting in the left of "<< data << "\n";
    root->left = Buildtree(root->left);

    // Right
    cout<<"Enter the data for inserting in the right of "<< data << "\n";
    root->right = Buildtree(root->right);
    return root;
}

void lO(tn* root){
    queue<tn*> q;
    q.push(root);
//    q.push(NULL); // Separator

    while(!q.empty()){
        tn* temp = q.front();
        q.pop();
//        if(temp == NULL){
//            cout<<endl;
//            if(!q.empty()){
//                q.push(NULL);
//            }
//        }else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
//        }
    }
}


int main(){

    treenode* root = nullptr;
//    cout<<"--------- Binary Search Tree ---------\n";
//    cout<<"Enter data to create BST:\n";
//    takeinput(root);
//    cout<<"\nTraversal\n";
//    levelOrder(root);

//    int k;
//    cout<<"\nEnter the Key to be Searched in BST: "; cin>>k;
//    if(BSTsearch(root, k)){
//        cout<<"We found the Element Congo!!\n";
//    }else{
//        cout<<"Better luck next time we couldn't find\n";
//    }
//    pair<treenode*,treenode*> ans = MinMax(root);
//    cout<<"\nMax and Min element in the BST: "<<ans.second->data<< " and "<<ans.first->data<<"\n";
//    cout<<"\n";
//    cout<<"------------------- Deletion from a BST -------------------\n";
//    int x; cout<<"Enter the value you want to delete:\n"; cin>>x;
//    treenode* deletenode = deletefromBST(root, x); cout<<"\nTraversal after deletion\n";
//    levelOrder(deletenode);
//    cout<<"\n";
//    cout<<"Is the BST VALID??\n";
//    if(isBst(root)){
//        cout<<"\nAns: YES THE TREE IS VALID BST\n";
//    }else{
//        cout<<"\nAns: NO THE TREE IS NOT VALID BST\n";
//    }
//    int sk; cout<<"\n Kth smallest in BST Enter the k value\n"; cin>>sk;
//    cout<<"\nThe value is "<<kthsmallest(root, sk)<<"\n";
//    int lk; cout<<"\n Kth Largest in BST Enter the k value\n"; cin>>lk;
//    cout<<"\nThe value is "<<kthlargest(root, sk)<<"\n";
//    cout<<"Inorder traversal by the vector\n";
//    int c; cout<<"Enter the value for which you wanna find predecessor and successor:\n"; cin>>c;
//    pair<int,int> ans = predSucc(root, c);
//    cout<<"\nPredecessor of the value is "<< ans.first << " and successor is "<<ans.second<<"\n";
//    cout<<"\nCheck with Inorder Traversal if you have any doubt\n";
//    inorder(root);
//    treenode* n1 = root->left->right;
//    treenode* n2 = root->right->left;  // You can change them according to you test case
//    treenode* result = LCAinBST(root, n1, n2);
//    cout<<"\n\nLCA of the Given n1 "<<n1->data<<" and n2 " <<n2->data<<" is "<<result->data<<"\n";
//    int s2; cout<<"\nEnter the value to check 2 sum :\n"; cin>>s2;
//    vector<int> inorderArray;
//    sum2(root, inorderArray);
//    if(twosumBST(inorderArray, s2)){
//        cout<<"Yes We Got 2 sum for the given value.\n";
//    }else{
//        cout<<"Sorry no Two Sum for the given value.\n";
//    }
//    treenode* head = FlattenBST(root);
//    cout<<"\nFlattend BST into a Sorted linked list\n";
//    printLL(head);
//    cout<<"\n\nBST to BALANCED BST\n";
//    treenode* bBST = BalancedBST(root);
//    cout<<"\nTraversal of the Balanced BST\n";
//    levelOrder(bBST);
//    int sizen; cout<<"\n\nEnter the size of the preorder traversal(No need to enter -1): \n"; cin>>sizen;
//    vector<int> preorderarr;
//    cout<<"\n Pre order to BST, Enter the preorder traversal :\n";
//    for(int i=0;i<sizen;i++){
//        cin>>preorderarr[i];
//    }
//    treenode* preBSTnode = pretoBST(preorderarr);
//    cout<<"\nTraversal of the Tree\n";
//    levelOrder(preBSTnode);
//    tn* root2 = nullptr;
//    cout<<"Enter the data to build tree 2:\n";
//    takeinput(root2);
//    cout<<"Traversal\n";
//    levelOrder(root2);
//
//    tn* mBST = mergeBST(root, root2);
//    cout<<"\nLevel order traversal of the merged BST:\n";
//    levelOrder(mBST);
//    cout<<"You can check with Sorting Here it is for you:\n";
//    inorder(mBST);
    root = Buildtree(root);
    cout<<"\nLevel Order traversal\n";
    lO(root);
    int ans = 0;
    info temp = solveBST(root, ans);
    cout<<"\nThe maximum Sized BST in the given Binary tree is:\n "<<ans;

    cout<<"\n\n\n \t\t\tTHANK YOU!!!\t\t\t\n\n\n";
    // Input 10 8 21 7 27 5 4 3 -1
    // Input 100 50 28 70 60 110 120 115 -1
    // Input 50 45 40 49 55 53 60 -1
    return 0;
}