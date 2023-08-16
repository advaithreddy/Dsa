#include<bits/stdc++.h>
using namespace std;

// BAsic Structure of Trees we can even use struct But i like to use class
class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this-> left = NULL;
        this->right = NULL;
    }
};

node* Buildtree(node* root){
    cout<<"Enter the data: \n";
    int data;
    cin>>data;
    root = new node(data);
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

//Types of Traversals
// 1. LevelOrder Traversal
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
//    q.push(NULL); // Separator

    while(!q.empty()){
        node* temp = q.front();
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

// Reverse Level Order
void reverselevelOrder(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    while(!s.empty()){
        node* dummy = s.top();
        s.pop();
        cout<<dummy->data<<" ";
    }
}

// Inorder Traversal
void InOrder(node* root){
    if(root == NULL){
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

// Pre Order
void PreOrder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// Post Order
void PostOrder(node* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

//Build tree with level order traversal
void BuildTreeLevel(node* &root){
    queue<node*> q;
    cout<<"Enter the root data: \n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp  = q.front();
        q.pop();

        cout<<"Enter the data for left of "<< temp->data <<"\n";
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data for right of "<< temp->data <<"\n";
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// Height or maximum depth of a binary tree
int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right)+1;

    return ans;
}

// Count leaf Node
void porder(node* root, int &c){
    if(root== NULL){
        return;
    }

    porder(root->left, c);
    if(root->left == NULL && root->right == NULL){
        c++;
    }
    porder(root->right, c);
}

int leaf(node* root){
    int count = 0;
    porder(root, count);
    return count;
}

// Diameter of the Tree optimized approach
pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second , right.second) + 1;
    return ans;
}
int diameter(node* root){
    return diameterFast(root).first;
}

// Balanced Tree
bool balanced(node* root){
    int left = height(root->left);
    int right = height(root->right);

    if(abs(left - right) <=1){
        return true;
    }else{
        return false;
    }
}

// Balanced
pair<bool,int> balancedfast(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balancedfast(root->left);
    pair<bool, int> right = balancedfast(root->right);

    bool op1 = left.first;
    bool op2 = right.first;
    bool diff = abs(left.second - right.second) <=1;
    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(op1 && op2 && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isbalanced(node* root){
    return balancedfast(root).first;
}

// is Sum Tree
pair<bool, int> Balancedfast(node* root){
    // Base case
    if(root== NULL){
        pair<bool, int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool, int> left = Balancedfast(root->left);
    pair<bool, int> right = Balancedfast(root->right);

    bool op1 = left.first;
    bool op2 = right.first;

    bool sum = root->data == left.second + right.second;

    pair<bool, int> ans;
    if(op1 && op2 && sum){
        ans.first = true;
        ans.second = 2*root->data;
    }else{
        ans.first = false;
    }
    return ans;
}
bool isSum(node* root){
    return Balancedfast(root).first;
}

// Morris Traversal (Efficient Inorder Traversal)
void traverseMorris(node* root){
    if(root == NULL){
        return;
    }

    node* curr, *pre;
    curr = root;
    while(curr!=NULL){
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }else
        {
            pre = curr->left;
            while(pre->right !=NULL && pre->right!=curr)
            {
                pre = pre->right;
            }

            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }else
            {
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
int main(){

    // Same like LL we need a root like head
    node* root = NULL;

    root = Buildtree(root);
//    BuildTreeLevel(root);
    cout<<"\n";
    cout<<"Printing the level Order Traversal \n";
    levelOrder(root);
    cout<<endl;
    cout<<"Reverse of it\n";
    reverselevelOrder(root);

    cout<<"\n";
    cout<<"Inorder Traversal"<<"\n";
    InOrder(root);
    cout<<"\n";
    cout<<"Pre Order Traversal\n";
    PreOrder(root);
    cout<<"\n";
    cout<<"Post Order Traversal\n";
    PostOrder(root);
    cout<<"\n";
    cout<<"Height of the binary Tree\n"<<height(root);
    cout<<"\n";
    cout<<"Number of leaf nodes of the Tree\n"<<leaf(root);
    cout<<"\n";
    cout<<"Diameter of the Tree:\n"<<diameter(root);
    cout<<"\n";
    if(balanced(root)){
        cout<<"Yes Tree is Balanced\n";
    }else{
        cout<<"No Tree is not Balanced\n";
    }
    cout<<"\n";
    if(isSum(root)){
        cout<<"Yes it is Sum Tree\n";
    }else{
        cout<<"No not a Sum Tree\n";
    }
    cout<<"\n";
    cout<<"Morris Traversal == Inorder Traversal \n";
    traverseMorris(root);
    cout<<"\n";
    // 1 7 5 2 -1 -1 -1 2 -1 -1 0 0 -1 -1 0 -1 -1

    return 0;
}