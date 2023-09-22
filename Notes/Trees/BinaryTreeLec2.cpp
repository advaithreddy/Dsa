#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

// Zig Zag Traversal
vector<int> Zigzagtraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    vector<int> result;
    bool flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            int index = flag ? i : size - i- 1;
            ans[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        flag = !flag;
        for(auto i: ans) {
            result.push_back(i);
        }
    }
    return result;
}

// Boundary Traversal of a Trees
// Can be break down to three parts
// Part 1 left traverse
void traverseLeft(Node* root, vector<int> &ans){
    if((root==NULL) || (root->left==NULL && root->right ==NULL)){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left,ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

// Part 2 Leaf Node traverse
void traverseLeaf(Node* root, vector<int>& ans){
    if(root==NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

// Part 3 right traverse
void traverseRight(Node* root, vector<int> & ans){
    if((root==NULL) || (root->left==NULL && root->right ==NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}
vector<int> boundarytraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    ans.push_back(root->data);

    // traverse Left
    traverseLeft(root->left,ans);
    // traverse leaf
    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right
    traverseRight(root->right, ans);
    return ans;
}

// Vertical Traversal Of a Tree
vector<int> traverseVertical(Node* root){
    // Vertical traversal is complicated amongst others
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node*, pair<int, int> > > q;

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<Node*,pair<int,int> > temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl +1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// Top view of the binary Tree
vector<int> topView(Node* root){
    map<int,int> mp;
    queue<pair<Node*,int> > q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* top = temp.first;
        int hd = temp.second;

        // Push for the first time
        if(mp.find(hd) == mp.end()){
            mp[hd] = top->data;
        }

        if(top->left){
            q.push(make_pair(top->left,hd-1));
        }

        if(top->right){
            q.push(make_pair(top->right,hd+1));
        }
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

// Bottom and Top are not so different
/* // Push for the first time
        if(mp.find(hd) == mp.end()){
            mp[hd] = top->data;
        }

        Instead of this checking we can simply insert
*/
vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,int> mp;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        Node* top = q.front().first;
        int hd = q.front().second;
        q.pop();

        mp[hd] = top->data;

        if(top->left){
            q.push(make_pair(top->left,hd-1));
        }

        if(top->right){
            q.push(make_pair(top->right,hd+1));
        }
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

// Left View of the Tree
void lefttra(Node* root, vector<int>& ans, int level){
    if(root==NULL){
        return;
    }

    if(level>=ans.size()){
        ans.push_back(root->data);
    }
    lefttra(root->left, ans, level+1);
    lefttra(root->right, ans, level+1);
}
vector<int> leftView(Node* root){
    vector<int> ans;
    lefttra(root, ans, 0);
    return ans;
}

// Right View
void righttra(Node* root, vector<int>& ans, int level){
    if(root==NULL){
        return;
    }

    if(level>=ans.size()){
        ans.push_back(root->data);
    }
    righttra(root->right, ans, level+1);
    righttra(root->left, ans, level+1);
}
vector<int> RightView(Node* root){
    vector<int> ans;
    righttra(root, ans, 0);
    return ans;
}

// Diagonal Traversal
vector<int> traverseDiagonal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<Node*> q;
    Node* temp = root;
    while(temp){
        ans.push_back(temp->data);

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            temp = temp->right;
        }else{
            if(!q.empty()){
                temp = q.front();
                q.pop();
            }else{
                temp = NULL;
            }
        }
    }
    return ans;
}


int main(){

    Node* root = NULL;
    root = buildtree(root);
    cout<<"\n";
    cout<<"Level Order Traversal \n";
    levelorder(root);
    cout<<"\n";
    cout<<"Zig Zag Traversal\n";
    vector<int> output = Zigzagtraversal(root);
    for(auto i : output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Boundary Traversal\n";
    output = boundarytraversal(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Vertical Traversal\n";
    output = traverseVertical(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Top View of the Tree\n";
    output = topView(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Bottom View of the Tree\n";
    output = bottomView(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Left View of the Tree\n";
    output = leftView(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Right View of the Tree\n";
    output = RightView(root);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Diagonal traversal of the Tree\n";
    output = traverseDiagonal(root);
    for(auto i:output){
        cout<<i<<" ";
    }



    // Input ->   1 7 5 2 -1 -1 -1 2 -1 -1 0 0 -1 -1 0 -1 -1
    return 0;
}