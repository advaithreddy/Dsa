#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;

    explicit Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};


Node* buildtree(Node* root){
    int d;
    cout<<"Enter the data: ";
    cin>>d;
    root = new Node(d);

    if(d == -1){
        return NULL;
    }
    cout<<"Enter the data to the left of "<<d<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter the data to the right of "<<d<<endl;
    root->right = buildtree(root->right);
    return root;
}

// levelOrder
void levelorder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}

// Maximum Bloodline sum (Max sum by nodes)
void solve(Node* root, int sum , int &maxSum, int len , int &maxLen){
    // base case
    if(root == NULL){
        // I need to check 2 cases
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len == maxLen){
            maxSum = max(sum , maxSum);
        }
        return;
    }

    sum = sum+ root->data;
    solve(root->left, sum , maxSum, len+1, maxLen);
    solve(root->right, sum , maxSum, len+1, maxLen);
}

int maxBloodline(Node* root){
    int sum = 0;
    int maxSum = INT_MIN;
    int l = 0, maxLen = 0;
    solve(root, sum , maxSum, l, maxLen);
    return maxSum;
}


// Lowest common ancestor
Node* lca(Node* root, int n1, int n2){
    // Base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    // Now traverse through left and right
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    // Now checking four Conditions
    if(left !=NULL && right !=NULL){
        return root;
    }else if(left!=NULL && right == NULL){
        return left;
    }else if(left == NULL && right !=NULL){
        return right;
    }else{
        return NULL;
    }
}


// Kth Sum
void solvesum(Node* root, int k, int &count, vector<int>& path){
    if(root==NULL){
        return;
    }

    path.push_back(root->data);

    solvesum(root->left, k, count, path);
    solvesum(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for(int i=size-1;i>=0;i--){
        sum += path[i];

        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}

int kthsum(Node* root,int k){
    vector<int> path;
    int count =0;
    solvesum(root, k,count, path);
    return count;
}

// Kth Sum in a binary Tree
Node* solvekth(Node* root, int &k , int node){
    if(root == NULL) return NULL;
    if(root->data == node) return root;

    Node* left = solvekth(root->left,k,node);
    Node* right = solvekth(root->right,k,node);

    if(left!=NULL && right == NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return left;
    }

    if(right !=NULL && left == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthancestor(Node* root, int k, int node){
    Node* ans = solvekth(root, k, node);
    if(ans == NULL || ans->data == node){
        return -1;
    }else{}
    return ans->data;
}

// Maximum sum of Adjacent Nodes
// Search if you don't know the problem
pair<int,int> solvemaxsum(Node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solvemaxsum(root->left);
    pair<int,int> right = solvemaxsum(root->right);

    // now our calculation
    pair<int,int> res;
    res.first = root->data + left.second + right.second;        // It looks like this  <x,y>   left <2,4> right <3,11>
                                                                                     // f s          f   s       f  s
    res.second = max(left.first,left.second) + max(right.first, right.second);
    return res;
}

int maxsumnodes(Node* root){
    pair<int,int> ans = solvemaxsum(root);
    return max(ans.first, ans.second);
}

// Construct Tree from inorder and preorder
void createmapping(int *in, map<int,int>& nodetoindex, int n){
    for(int i= 0;i<n;i++){
        nodetoindex[in[i]] = i;
    }
}

Node* solvebuild(int in[], int pre[], int& Index, int inorderStart, int inorderEnd, int n, map<int,int>& nodetoindex){
    // base case
    if(Index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[Index++];
    Node* root = new Node(element);
    int pos = nodetoindex[element];

    root->left = solvebuild(in, pre, Index, inorderStart, pos-1, n,nodetoindex);
    root->right = solvebuild(in, pre, Index, pos+1, inorderEnd, n,nodetoindex);

    return root;
}

Node* treefrom(int in[], int pre[], int n){
    int preorderIndex = 0;
    map<int,int> nodetoindex;
    createmapping(in, nodetoindex, n);
    Node* ans = solvebuild(in, pre, preorderIndex, 0, n-1, n,nodetoindex);
    return ans;
}

// Construct Tree from inorder and postorder
// Similar to pre order
// Changes to be made are
// come from back
// and when traverse go to right first that's it everything same

// Burn Tree (hard)
Node* mappingparent(Node* root, int target, map<Node*,Node*>& nodeparent){
    Node* res = NULL;

    queue<Node*> q;
    q.push(root);
    nodeparent[root] = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left){
            q.push(front->left);
            nodeparent[front->left] = front;
        }

        if(front->right){
            q.push(front->right);
            nodeparent[front->right] = front;
        }
    }
    return res;
}

int burn(Node* root, map<Node*,Node*> &nodeparent){
    int time = 0;
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = 1;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if(nodeparent[front] && !visited[nodeparent[front]]){
                flag = 1;
                q.push(nodeparent[front]);
                visited[nodeparent[front]] = 1;
            }
        }
        if(flag == 1){
            time++;
        }
    }
    return time;
}

int burnthetree(Node* root, int target){
    map<Node*,Node*> mapping;
    Node* targetNode = mappingparent(root, target, mapping);
    int ans = burn(targetNode, mapping);
    return ans;
}

// Using Morris Traversal Flatten a binary Tree into a linked List
Node* flatten(Node* root){
    if(root == NULL)
    {
        return NULL;
    }

    Node* curr, *pre;
    curr = root;
    while(curr!=NULL){
        // By morris Traversal
        if(curr->left!=NULL){
            pre = curr->left;
            while(pre->right)
                pre = pre->right;
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    // Simple code but the logic is Astonishing
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root = NULL;
    root = buildtree(root);
    cout<<"\n";
    cout<<"Level Order Traversal \n";
    levelorder(root);
    cout<<"\n";
//    cout<<"Maximum BloodLine Sum of the tree is "<<maxBloodline(root)<<"\n";
//    cout<<"\n";
//    int n1, n2;
//    cout<<"Enter n1: "; cin>>n1;
//    cout<<"now n2: "; cin>>n2;
//    cout<<"LCA of Given n1 and n2 "<<lca(root, n1,n2)->data<<"\n";
//    cout<<"Kth Anscestor";
//    int k,n;
//    cout<<"Enter k and node value: "; cin>>k>>n; cout<<"\n";
//    cout<<"The solution is "<<kthancestor(root,k,n)<<"\n";
//    cout<<"Kth Sum\n";
//    int k2;
//    cout<<"Enter the value of k "; cin>>k2; cout<<"\n";
//    cout<<"The paths are "<<kthsum(root,k2)<<"\n";
//    cout<<"\n";
//    cout<<"Maximum sum of the adjacent nodes of Trees \n";
//    cout<<"The max sum is "<<maxsumnodes(root)<<"\n";
//    cout<<"\nConstruct Tree from inorder and preorder\n";
//    int in[10000], pre[100000],size;
//    cout<<"Enter the size of the inorder and preorder traversal: "; cin>>size;
//    cout<<"Enter the Inorder Traversal: ";
//    for(int i=0;i<size;i++){
//        cin>>in[i];
//    }
//    cout<<"Enter the Preorder Travesal: ";
//    for(int i=0;i<size;i++){
//        cin>>pre[i];
//    }
//    cout<<"\n";
//    Node* res = treefrom(in, pre, size);
//    int target;
//    cout<<"Enter the target: "; cin>>target;
//    cout<<"Min time taken to Burn the Tree is "<<burnthetree(root, target)<<"\n";
    cout<<"\n Flatten Into Linked list: ";
    Node* flattenll = flatten(root);
    inorder(flattenll);
    cout<<"\n";



    // Input ->   1 7 5 2 -1 -1 -1 2 -1 -1 0 0 -1 -1 0 -1 -1
    return 0;
}