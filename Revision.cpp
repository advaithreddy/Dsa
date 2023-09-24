#include<bits/stdc++.h>
using namespace std;

// Binary tree revision
// How to create a tree
class node{
public:
    int data;
    node* left;
    node* right;

    // and now a constructor
    node(int val){
        // we will get a val
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }        
};

// We have successfully created the block of a tree not the tree  [left | data | right]
// Now let us build the tree
node* buildtree(node* root){
    // we need the root node to build the tree
    cout<<"Enter the data: ";
    int data;
    cin>>data;  // now we got out root node and our data
    root = new node(data); // Horray We got out parent node 

    // Now by using recursion we need to build the left and right part of the tree
    // But before that we need to check a null case
    if(data == -1){
        return nullptr; // this is the breaking case
    }
    // that we need to stop from taking the data
    // left recusrion
    cout<<"Enter the data for the left of "<<data<<"\n";
    root->left = buildtree(root->left);
    
    // right recurson
    cout<<"Enter the data for the right of "<<data<<"\n";
    root->right = buildtree(root->right);

    return root;
}

// We have build the tree but to see it we need any traversal code
// Types of Traversals
// 1. Level Order traversal
// This is the leveling traversal tats it
void levelOrder(node* root){
    //Only for this we will use the help of another data structure
    queue<node*> q;
    // we built a queue which can hold the nodes
    // Simple always remember first push the root node
    q.push(root);
    // q.push(nullptr); // this is separator
    // now our queue holds the root node
    while(!q.empty()){
        node* temp = q.front(); // point the root node with a new pointer
        q.pop(); // and then pop it
        // if(temp == nullptr){
        //     cout<<"\n";
        //     if(!q.empty()){
        //         q.push(nullptr);
        //     }
        // }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        // }
    }
    // and if you really want the level order to be in level a extra bit of code is needed
    // I will add it above and comment later you can check it
}

// Now let us learn the reversal of it, same but here we will use a stack 
void reverseLevelOrder(node* root){
    if(root == nullptr) return;

    queue<node*> q;  // this is for normal order
    stack<node*> s; // this is to reverse it

    q.push(root);
    while(!q.empty()){
        // here insted of printing i will push them into the stack
        node* temp = q.front();
        q.pop();
        s.push(temp); // I guess you got it

        // Not printing
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    // Now we will print them
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
    }
}

// 2. Inorder Traversal
void inOrder(node* root){
    if(root == nullptr) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// 3. Pre order
void preOrder(node* root){
    if(root == nullptr) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// 4. Post order
void postOrder(node* root){
    if(root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// Building tree with level order traversal
void levelOrderBuild(node* &root){
    queue<node*> q; // cause we do this in level order traversal
    cout<<"Enter the root node data: ";
    int data;
    cin>>data;
    root = new node(data); // we formed the box
    q.push(root); // push it into the queue;
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// Height or maximum depth of the tree 
// This question implies the maximum depthe node a tree can have theta is the height of the tree
int heightOfTree(node* root){
    if(root == nullptr) return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    int ans = max(leftHeight,rightHeight) + 1;// This is for the parent node
    return ans;
}

// Count Leaf Node
void leafTraverse(node* root, int &c){
    if(root == nullptr) return;

    leafTraverse(root->left,c);
    leafTraverse(root->right,c);

    if(root->left == nullptr && root->right == nullptr) c++;
}

int leafNode(node* root){
    int count = 0;
    leafTraverse(root,count);
    return count;
}

// Diameter of the Tree 
// Approach 1 
// There will be 3 options op1 -> the answer is in the left subtree 
// op2 -> the answer is in the right subtree
// op3 -> the answer is heightleft + heightright 
int diameterAp1(node* root){
    // base case
    if(root == nullptr)return 0;

    int op1 = diameterAp1(root->left);
    int op2 = diameterAp1(root->right);
    int op3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(op1, max(op2,op3));
    return ans;
}
// Approach 2 
// Same but in the above approach we will three call for every node 
// So i want to skip it
pair<int,int> helper(node* root){
    // base case
    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    // pair<int,      int>
    //    diameter  height
    pair<int,int> left = helper(root->left);
    pair<int,int> right = helper(root->right);

    int op1 = left.first; // left diameter
    int op2 = right.first; // right diameter
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3)); // diameter
    ans.second = max(left.second , right.second) + 1; // height
    return ans;
}

int diameterAp2(node* root){
    return helper(root).first;
}

// Balanced Tree
/*The height of the left subtree and rightsubtree can be atmost one*/
// Approach 1
bool balancedAp1(node* root){
    if(root == nullptr) return 1;
    
    int leftDepth = heightOfTree(root->left);
    int rightDepth = heightOfTree(root->right);

    if(abs(leftDepth - rightDepth) <= 1){
        return 1;
    }else{
        return 0;
    }
}

// Approach 2  similar to the pair 
pair<bool,int> helper2(node* root){
    if(root == nullptr){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> leftSubtree = helper2(root->left);
    pair<bool,int> rightSubtree = helper2(root->right);

    // same as above we have 3 options
    // one is to be in left subtree
    bool op1 = leftSubtree.first;
    bool op2 = rightSubtree.first;
    bool diff = abs(leftSubtree.second - rightSubtree.second) <= 1;
    
    pair<bool,int> ans;
    ans.second = max(leftSubtree.second, rightSubtree.second) + 1;

    if(op1 && op2 && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

bool balancedAp2(node* root){
    return helper2(root).first;
}


signed main(){

    node* root = nullptr;

    root = buildtree(root);
    cout<<"\n";
    cout<<"The level order of the tree is: ";
    levelOrder(root);
    cout<<endl;
    cout<<"Reverse Level order traversal: ";
    reverseLevelOrder(root);
    cout<<endl;
    cout<<"In order traversal: ";
    inOrder(root);
    cout<<endl;
    cout<<"Pre order traversal: ";
    preOrder(root);
    cout<<endl;
    cout<<"Post order traversal: ";
    postOrder(root);
    cout<<endl;
    cout<<"The maximum depth or height of tree is: "<<heightOfTree(root);
    cout<<endl;
    cout<<"The number of leaf nodes are: "<<leafNode(root);
    cout<<endl;
    cout<<"The diameter of the tree is: "<<diameterAp2(root);
    cout<<endl;
    if(balancedAp2(root)){
        cout<<"The tree is balanced";
    }else{
        cout<<"The tree is not balanced";
    }
    cout<<endl;

    // Demo Tree
    // 4 2 1 -1 -1 3 -1 -1 6 -1 -1
    /*
    Height : 3         4       Level Order: 4 2 6 1 3
    Leaf Node: 3      / \      Reverse : 3 1 6 2 4
    Diameter: 4      2   6     In Order : 1 2 3 4 6
    Balanced        / \        Post Order : 1 3 2 6 4
                   1   3       Pre Order : 4 2 1 3 6
    */

    return 0;
}