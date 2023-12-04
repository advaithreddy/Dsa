// Implementation of Binary Tree
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int main() {
    // Creating nodes for the tree
    BinaryTreeNode* root = new BinaryTreeNode(1);
    BinaryTreeNode* leftChild = new BinaryTreeNode(2);
    BinaryTreeNode* rightChild = new BinaryTreeNode(3);

    // Connecting nodes to form the tree
    root->left = leftChild;
    root->right = rightChild;

    // Accessing and printing the data
    cout << "Root Data: " << root->data << endl;
    cout << "Left Child Data: " << root->left->data << endl;
    cout << "Right Child Data: " << root->right->data << endl;

    // Remember to free memory to avoid memory leaks
    delete root;
    delete leftChild;
    delete rightChild;

    return 0;
}


// Implementation of Ternary Tree
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TernaryTreeNode {
    int data;
    TernaryTreeNode* left;
    TernaryTreeNode* middle;
    TernaryTreeNode* right;

    TernaryTreeNode(int value) : data(value), left(nullptr), middle(nullptr), right(nullptr) {}
};

int main() {
    // Creating nodes for the tree
    TernaryTreeNode* root = new TernaryTreeNode(1);
    TernaryTreeNode* leftChild = new TernaryTreeNode(2);
    TernaryTreeNode* middleChild = new TernaryTreeNode(3);
    TernaryTreeNode* rightChild = new TernaryTreeNode(4);

    // Connecting nodes to form the tree
    root->left = leftChild;
    root->middle = middleChild;
    root->right = rightChild;

    // Accessing and printing the data
    cout << "Root Data: " << root->data << endl;
    cout << "Left Child Data: " << root->left->data << endl;
    cout << "Middle Child Data: " << root->middle->data << endl;
    cout << "Right Child Data: " << root->right->data << endl;

    // Remember to free memory to avoid memory leaks
    delete root;
    delete leftChild;
    delete middleChild;
    delete rightChild;

    return 0;
}


// Implementation of N-ary Tree
#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct NaryTreeNode {
    int data;
    vector<NaryTreeNode*> children;

    NaryTreeNode(int value) : data(value) {}
};

// Function to print the N-ary tree using a depth-first traversal
void printNaryTree(NaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    for (NaryTreeNode* child : root->children) {
        printNaryTree(child);
    }
}

int main() {
    // Creating nodes for the N-ary tree
    NaryTreeNode* root = new NaryTreeNode(1);
    
    NaryTreeNode* child1 = new NaryTreeNode(2);
    NaryTreeNode* child2 = new NaryTreeNode(3);
    NaryTreeNode* child3 = new NaryTreeNode(4);

    // Connecting nodes to form the tree
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    // Adding more children for demonstration
    NaryTreeNode* grandchild1 = new NaryTreeNode(5);
    NaryTreeNode* grandchild2 = new NaryTreeNode(6);
    
    child1->children.push_back(grandchild1);
    child1->children.push_back(grandchild2);

    // Accessing and printing the data
    cout << "N-ary Tree: ";
    printNaryTree(root);
    cout << endl;

    // Remember to free memory to avoid memory leaks
    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete grandchild1;
    delete grandchild2;

    return 0;
}


// Implementation of Binary Search Tree
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function for an in-order traversal of the BST (prints the keys in ascending order)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Creating a BST
    TreeNode* root = nullptr;

    // Insert keys into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal to print the keys in ascending order
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Remember to free memory to avoid memory leaks
    // In a real-world scenario, you would need to implement a proper destructor to free the entire tree.
    delete root;

    return 0;
}



// Implementation of Ternary Search Tree
#include <iostream>
#include <string>
using namespace std;

// Define the structure for a tree node
struct TSTNode {
    char data;
    bool isEndOfWord;
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;

    TSTNode(char value) : data(value), isEndOfWord(false), left(nullptr), middle(nullptr), right(nullptr) {}
};

// Function to insert a key into the TST
TSTNode* insert(TSTNode* root, const string& key, size_t depth) {
    if (root == nullptr) {
        root = new TSTNode(key[depth]);
    }

    if (key[depth] < root->data) {
        root->left = insert(root->left, key, depth);
    } else if (key[depth] == root->data) {
        if (depth < key.length() - 1) {
            root->middle = insert(root->middle, key, depth + 1);
        } else {
            root->isEndOfWord = true; // Mark the end of the word
        }
    } else {
        root->right = insert(root->right, key, depth);
    }

    return root;
}

// Function to search for a key in the TST
bool search(TSTNode* root, const string& key, size_t depth) {
    if (root == nullptr) {
        return false;
    }

    if (key[depth] < root->data) {
        return search(root->left, key, depth);
    } else if (key[depth] == root->data) {
        if (depth == key.length() - 1) {
            return root->isEndOfWord; // Check if it's the end of the word
        } else {
            return search(root->middle, key, depth + 1);
        }
    } else {
        return search(root->right, key, depth);
    }
}

int main() {
    // Creating a TST
    TSTNode* root = nullptr;

    // Insert keys into the TST
    root = insert(root, "apple", 0);
    insert(root, "banana", 0);
    insert(root, "orange", 0);

    // Search for keys in the TST
    cout << "Search 'apple': " << (search(root, "apple", 0) ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (search(root, "banana", 0) ? "Found" : "Not Found") << endl;
    cout << "Search 'grape': " << (search(root, "grape", 0) ? "Found" : "Not Found") << endl;

    // Remember to free memory to avoid memory leaks
    // In a real-world scenario, you would need to implement a proper destructor to free the entire tree.
    delete root;

    return 0;
}


// Implementation of AVL Tree
#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure for a tree node
struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

// Function to get the height of a node
int getHeight(AVLNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to update the height of a node
void updateHeight(AVLNode* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Function to perform a right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to get the balance factor of a node
int getBalanceFactor(AVLNode* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function to insert a key into the AVL Tree
AVLNode* insert(AVLNode* root, int key) {
    if (root == nullptr) {
        return new AVLNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed in this example
        return root;
    }

    // Update height of current node
    updateHeight(root);

    // Get the balance factor to check if this node became unbalanced
    int balance = getBalanceFactor(root);

    // Perform rotations if needed to rebalance the tree
    // Left Left Case
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }
    // Right Right Case
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }
    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function for an in-order traversal of the AVL Tree (prints the keys in ascending order)
void inorderTraversal(AVLNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    AVLNode* root = nullptr;

    // Insert keys into the AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Perform in-order traversal to print the keys in ascending order
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Remember to free memory to avoid memory leaks
    // In a real-world scenario, you would need to implement a proper destructor to free the entire tree.
    delete root;

    return 0;
}


// Implementation of B Tree
#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a B-tree node
template <typename T>
struct BTreeNode {
    bool isLeaf;
    vector<T> keys;
    vector<BTreeNode*> children;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
};

// B-tree class
template <typename T>
class BTree {
private:
    int degree;  // Minimum degree of the B-tree
    BTreeNode<T>* root;

public:
    BTree(int t) : degree(t), root(nullptr) {}

    // Function to search for a key in the B-tree
    BTreeNode<T>* search(BTreeNode<T>* x, T key) {
        int i = 0;
        while (i < x->keys.size() && key > x->keys[i]) {
            i++;
        }

        if (i < x->keys.size() && key == x->keys[i]) {
            return x;  // Key found in this node
        } else if (x->isLeaf) {
            return nullptr;  // Key not found, and this node is a leaf
        } else {
            return search(x->children[i], key);  // Recur to the appropriate child
        }
    }

    // Function to split a child of the B-tree
    void splitChild(BTreeNode<T>* x, int i) {
        BTreeNode<T>* y = x->children[i];
        BTreeNode<T>* z = new BTreeNode<T>(y->isLeaf);
        int t = degree - 1;

        // Move the (t-1) largest keys of y to z
        z->keys = vector<T>(y->keys.begin() + t, y->keys.end());
        y->keys.resize(t);

        // Move the (t) children of y to z if y is not a leaf
        if (!y->isLeaf) {
            z->children = vector<BTreeNode<T>*>(y->children.begin() + t, y->children.end());
            y->children.resize(t);
        }

        // Insert the middle key of y to x
        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);

        // Insert z as a child of x
        x->children.insert(x->children.begin() + i + 1, z);
    }

    // Function to insert a key into the B-tree
    void insert(T key) {
        if (root == nullptr) {
            root = new BTreeNode<T>(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == (2 * degree) - 1) {
                BTreeNode<T>* newRoot = new BTreeNode<T>(false);
                newRoot->children.push_back(root);
                root = newRoot;
                splitChild(newRoot, 0);
            }
            insertNonFull(root, key);
        }
    }

    // Function to insert a key into a non-full B-tree node
    void insertNonFull(BTreeNode<T>* x, T key) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            // Insert the key into the node
            x->keys.push_back(T());  // Create space for the new key
            while (i >= 0 && key < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = key;
        } else {
            // Find the child to insert into
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            i++;

            // Check if the child is full
            if (x->children[i]->keys.size() == (2 * degree) - 1) {
                splitChild(x, i);
                if (key > x->keys[i]) {
                    i++;
                }
            }

            // Recur to the appropriate child
            insertNonFull(x->children[i], key);
        }
    }

    // Function to print the B-tree in-order
    void inOrderTraversal(BTreeNode<T>* x) {
        if (x != nullptr) {
            int i;
            for (i = 0; i < x->keys.size(); i++) {
                if (!x->isLeaf) {
                    inOrderTraversal(x->children[i]);
                }
                cout << x->keys[i] << " ";
            }

            if (!x->isLeaf) {
                inOrderTraversal(x->children[i]);
            }
        }
    }

    // Function to search for a key in the B-tree
    bool search(T key) {
        return (search(root, key) != nullptr);
    }
};

int main() {
    BTree<int> btree(3);  // Creating a B-tree with a minimum degree of 3

    // Insert keys into the B-tree
    btree.insert(1);
    btree.insert(3);
    btree.insert(7);
    btree.insert(10);
    btree.insert(11);
    btree.insert(13);
    btree.insert(14);
    btree.insert(15);
    btree.insert(18);
    btree.insert(16);
    btree.insert(19);
    btree.insert(24);
    btree.insert(25);
    btree.insert(26);
    btree.insert(21);
    btree.insert(4);
    btree.insert(5);
    btree.insert(20);
    btree.insert(22);
    btree.insert(2);
    btree.insert(17);
    btree.insert(12);
    btree.insert(6);

    // Perform in-order traversal to print the keys in ascending order
    cout << "In-order Traversal: ";
    btree.inOrderTraversal(btree.root);
    cout << endl;

    // Search for keys in the B-tree
    cout << "Search for key 6: " << (btree.search(6) ? "Found" : "Not Found") << endl;
    cout << "Search for key 8: " << (btree.search(8) ? "Found" : "Not Found") << endl;

    return 0;
}



// Implementation of B+ Tree
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define the structure for a B+ tree node
template <typename K, typename V>
struct BPlusTreeNode {
    bool isLeaf;
    vector<K> keys;
    BPlusTreeNode* parent;
    vector<BPlusTreeNode*> children;
    vector<V> values;

    BPlusTreeNode(bool leaf, BPlusTreeNode* parent = nullptr)
        : isLeaf(leaf), parent(parent) {}
};

// B+ tree class
template <typename K, typename V>
class BPlusTree {
private:
    int order;  // Order of the B+ tree
    BPlusTreeNode<K, V>* root;

public:
    BPlusTree(int t) : order(t), root(nullptr) {}

    // Function to search for a key in the B+ tree
    V search(BPlusTreeNode<K, V>* x, K key) {
        if (x == nullptr) {
            return V();  // Key not found
        }

        int i = 0;
        while (i < x->keys.size() && key > x->keys[i]) {
            i++;
        }

        if (x->isLeaf) {
            // Check if the key is present in the leaf node
            if (i < x->keys.size() && key == x->keys[i]) {
                return x->values[i];
            } else {
                return V();  // Key not found
            }
        } else {
            return search(x->children[i], key);  // Recur to the appropriate child
        }
    }

    // Function to insert a key-value pair into the B+ tree
    void insert(K key, V value) {
        if (root == nullptr) {
            root = new BPlusTreeNode<K, V>(true);
            root->keys.push_back(key);
            root->values.push_back(value);
        } else {
            BPlusTreeNode<K, V>* r = root;
            if (r->keys.size() == order - 1) {
                // Create a new root if the root is full
                BPlusTreeNode<K, V>* newRoot = new BPlusTreeNode<K, V>(false);
                newRoot->children.push_back(root);
                root->parent = newRoot;
                root = newRoot;
                splitChild(newRoot, 0);
            }
            insertNonFull(r, key, value);
        }
    }

    // Function to insert a key-value pair into a non-full B+ tree node
    void insertNonFull(BPlusTreeNode<K, V>* x, K key, V value) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            // Insert the key-value pair into the leaf node
            x->keys.push_back(K());  // Create space for the new key
            x->values.push_back(V()); // Create space for the new value
            while (i >= 0 && key < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                x->values[i + 1] = x->values[i];
                i--;
            }
            x->keys[i + 1] = key;
            x->values[i + 1] = value;
        } else {
            // Find the child to insert into
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            i++;

            // Check if the child is full
            if (x->children[i]->keys.size() == order - 1) {
                splitChild(x, i);
                if (key > x->keys[i]) {
                    i++;
                }
            }

            // Recur to the appropriate child
            insertNonFull(x->children[i], key, value);
        }
    }

    // Function to split a child of the B+ tree
    void splitChild(BPlusTreeNode<K, V>* x, int i) {
        BPlusTreeNode<K, V>* y = x->children[i];
        BPlusTreeNode<K, V>* z = new BPlusTreeNode<K, V>(y->isLeaf, x);

        int t = (order - 1) / 2;

        // Move the (t) largest keys of y to z
        z->keys = vector<K>(y->keys.begin() + t, y->keys.end());
        y->keys.resize(t);

        // Move the (t) largest values of y to z if y is a leaf
        if (y->isLeaf) {
            z->values = vector<V>(y->values.begin() + t, y->values.end());   
            y->values.resize(t);
        }

        // Move the middle key of y to x
        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);

        // Insert z as a child of x
        x->children.insert(x->children.begin() + i + 1, z);

        // Update parent pointers
        if (y->isLeaf) {
            z->parent = y->parent;
            if (y->parent) {
                int index = getChildIndex(y);
                y->parent->children.insert(y->parent->children.begin() + index + 1, z);
            }
        }

        // Update keys and values of y
        y->keys.resize(t - 1);
        y->values.resize(t - 1);
    }

    // Function to get the child index in the parent
    int getChildIndex(BPlusTreeNode<K, V>* child) {
        BPlusTreeNode<K, V>* parent = child->parent;
        for (int i = 0; i < parent->children.size(); ++i) {
            if (parent->children[i] == child) {
                return i;
            }
        }
        return -1; // Should not reach here
    }

    // Function to print the B+ tree level by level
    void levelOrderTraversal() {
        if (root == nullptr) {
            cout << "B+ tree is empty." << endl;
            return;
        }

        queue<BPlusTreeNode<K, V>*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                BPlusTreeNode<K, V>* current = q.front();
                q.pop();

                cout << "[ ";
                for (int j = 0; j < current->keys.size(); ++j) {
                    cout << current->keys[j] << " ";
                }
                cout << "] ";

                if (!current->isLeaf) {
                    for (BPlusTreeNode<K, V>* child : current->children) {
                        q.push(child);
                    }
                }
            }
            cout << endl;
        }
    }
};

int main() {
    BPlusTree<int, string> bplusTree(3);  // Creating a B+ tree with a minimum degree of 3

    // Insert key-value pairs into the B+ tree
    bplusTree.insert(1, "One");
    bplusTree.insert(3, "Three");
    bplusTree.insert(7, "Seven");
    bplusTree.insert(10, "Ten");
    bplusTree.insert(11, "Eleven");
    bplusTree.insert(13, "Thirteen");
    bplusTree.insert(14, "Fourteen");
    bplusTree.insert(15, "Fifteen");
    bplusTree.insert(18, "Eighteen");
    bplusTree.insert(16, "Sixteen");
    bplusTree.insert(19, "Nineteen");
    bplusTree.insert(24, "Twenty-four");
    bplusTree.insert(25, "Twenty-five");
    bplusTree.insert(26, "Twenty-six");
    bplusTree.insert(21, "Twenty-one");
    bplusTree.insert(4, "Four");
    bplusTree.insert(5, "Five");
    bplusTree.insert(20, "Twenty");
    bplusTree.insert(22, "Twenty-two");
    bplusTree.insert(2, "Two");
    bplusTree.insert(17, "Seventeen");
    bplusTree.insert(12, "Twelve");
    bplusTree.insert(6, "Six");

    // Print the B+ tree level by level
    cout << "B+ Tree Level by Level:" << endl;
    bplusTree.levelOrderTraversal();

    // Search for values in the B+ tree
    cout << "\nSearch for key 6: " << bplusTree.search(6) << endl;
    cout << "Search for key 8: " << bplusTree.search(8) << endl;

    return 0;
}
