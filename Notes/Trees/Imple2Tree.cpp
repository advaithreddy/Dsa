// Implementation of Red Black Tree
#include <iostream>
using namespace std;

// Define colors for Red-Black Tree nodes
enum Color {
    RED,
    BLACK
};

// Define the structure for a Red-Black Tree node
template <typename T>
struct RBTreeNode {
    T key;
    Color color;
    RBTreeNode* parent;
    RBTreeNode* left;
    RBTreeNode* right;

    RBTreeNode(T k, Color c = RED, RBTreeNode* p = nullptr, RBTreeNode* l = nullptr, RBTreeNode* r = nullptr)
        : key(k), color(c), parent(p), left(l), right(r) {}
};

// Red-Black Tree class
template <typename T>
class RedBlackTree {
private:
    RBTreeNode<T>* root;
    RBTreeNode<T>* nil; // Sentinel node

public:
    RedBlackTree() {
        nil = new RBTreeNode<T>(T(), BLACK, nullptr, nullptr, nullptr);
        root = nil;
    }

    // Function to perform a left rotation
    void leftRotate(RBTreeNode<T>* x) {
        RBTreeNode<T>* y = x->right;
        x->right = y->left;

        if (y->left != nil) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    // Function to perform a right rotation
    void rightRotate(RBTreeNode<T>* y) {
        RBTreeNode<T>* x = y->left;
        y->left = x->right;

        if (x->right != nil) {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nil) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    // Function to insert a key into the Red-Black Tree
    void insert(T key) {
        RBTreeNode<T>* z = new RBTreeNode<T>(key);
        RBTreeNode<T>* y = nil;
        RBTreeNode<T>* x = root;

        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nil) {
            root = z; // Tree was empty
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        z->left = nil;
        z->right = nil;
        z->color = RED;

        insertFixup(z);
    }

    // Function to fix the Red-Black Tree properties after an insertion
    void insertFixup(RBTreeNode<T>* z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                RBTreeNode<T>* y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;          // Case 1
                    y->color = BLACK;                  // Case 1
                    z->parent->parent->color = RED;    // Case 1
                    z = z->parent->parent;             // Case 1
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;                  // Case 2
                        leftRotate(z);                  // Case 2
                    }
                    z->parent->color = BLACK;          // Case 3
                    z->parent->parent->color = RED;    // Case 3
                    rightRotate(z->parent->parent);    // Case 3
                }
            } else {
                RBTreeNode<T>* y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;          // Case 1
                    y->color = BLACK;                  // Case 1
                    z->parent->parent->color = RED;    // Case 1
                    z = z->parent->parent;             // Case 1
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;                  // Case 2
                        rightRotate(z);                 // Case 2
                    }
                    z->parent->color = BLACK;          // Case 3
                    z->parent->parent->color = RED;    // Case 3
                    leftRotate(z->parent->parent);     // Case 3
                }
            }
        }

        root->color = BLACK;
    }

    // Function to perform an in-order traversal of the Red-Black Tree
    void inOrderTraversal(RBTreeNode<T>* x) {
        if (x != nil) {
            inOrderTraversal(x->left);
            cout << x->key << " ";
            inOrderTraversal(x->right);
        }
    }

    // Function to print the Red-Black Tree in-order
    void printInOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree<int> rbTree;

    // Insert keys into the Red-Black Tree
    rbTree.insert(41);
    rbTree.insert(38);
    rbTree.insert(31);
    rbTree.insert(12);
    rbTree.insert(19);
    rbTree.insert(8);

    // Print the Red-Black Tree in-order
    rbTree.printInOrder();

    return 0;
}


// Implementation of Interval Tree
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int low;
    int high;

    Interval(int l, int h) : low(l), high(h) {}
};

// Structure to represent a node in the Interval Tree
struct IntervalTreeNode {
    Interval* interval;
    int maxHigh; // Maximum high value in the subtree rooted at this node
    IntervalTreeNode* left;
    IntervalTreeNode* right;

    IntervalTreeNode(Interval* i)
        : interval(i), maxHigh(i->high), left(nullptr), right(nullptr) {}
};

// Interval Tree class
class IntervalTree {
private:
    IntervalTreeNode* root;

    // Function to build an Interval Tree from a vector of intervals
    IntervalTreeNode* buildTree(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return nullptr;
        }

        vector<IntervalTreeNode*> nodes;
        for (const Interval& interval : intervals) {
            nodes.push_back(new IntervalTreeNode(new Interval(interval.low, interval.high)));
        }

        while (nodes.size() > 1) {
            vector<IntervalTreeNode*> newNodes;
            for (size_t i = 0; i < nodes.size(); i += 2) {
                IntervalTreeNode* left = nodes[i];
                IntervalTreeNode* right = (i + 1 < nodes.size()) ? nodes[i + 1] : nullptr;
                IntervalTreeNode* parent = mergeNodes(left, right);
                newNodes.push_back(parent);
            }
            nodes = newNodes;
        }

        return nodes[0];
    }

    // Function to merge two nodes and create a parent node
    IntervalTreeNode* mergeNodes(IntervalTreeNode* left, IntervalTreeNode* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        IntervalTreeNode* parent = new IntervalTreeNode(new Interval(0, 0));
        parent->interval->low = min(left->interval->low, right->interval->low);
        parent->interval->high = max(left->interval->high, right->interval->high);
        parent->maxHigh = max(left->maxHigh, right->maxHigh);
        parent->left = left;
        parent->right = right;

        return parent;
    }

    // Function to perform a recursive search in the Interval Tree
    vector<Interval> search(IntervalTreeNode* node, Interval& query) {
        vector<Interval> result;

        if (node == nullptr) {
            return result;
        }

        if (doOverlap(*(node->interval), query)) {
            result.push_back(*(node->interval));
        }

        if (node->left != nullptr && query.low <= node->left->maxHigh) {
            vector<Interval> leftResult = search(node->left, query);
            result.insert(result.end(), leftResult.begin(), leftResult.end());
        }

        if (node->right != nullptr && query.low <= node->right->maxHigh) {
            vector<Interval> rightResult = search(node->right, query);
            result.insert(result.end(), rightResult.begin(), rightResult.end());
        }

        return result;
    }

public:
    // Constructor to build the Interval Tree from a vector of intervals
    IntervalTree(vector<Interval>& intervals) : root(nullptr) {
        root = buildTree(intervals);
    }

    // Function to check if two intervals overlap
    bool doOverlap(const Interval& a, const Interval& b) const {
        return (a.low <= b.high && b.low <= a.high);
    }

    // Function to perform a search for intervals overlapping with the query interval
    vector<Interval> intervalSearch(Interval& query) {
        return search(root, query);
    }
};

int main() {
    // Example usage of Interval Tree
    vector<Interval> intervals = { {15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40} };
    IntervalTree intervalTree(intervals);

    // Query interval
    Interval queryInterval(14, 16);

    // Perform interval search
    vector<Interval> result = intervalTree.intervalSearch(queryInterval);

    // Print the intervals that overlap with the query interval
    cout << "Intervals overlapping with query interval (" << queryInterval.low << ", " << queryInterval.high << "):" << endl;
    for (const Interval& interval : result) {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    return 0;
}


// Implementation of 2-3-4 Tree
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node types in a 2-3-4 Tree
enum NodeType {
    TWO_NODE,
    THREE_NODE,
    FOUR_NODE
};

// Structure to represent a node in a 2-3-4 Tree
template <typename KeyType, typename ValueType>
struct TreeNode {
    vector<KeyType> keys;
    vector<ValueType> values;
    vector<TreeNode*> children;
    NodeType nodeType;

    TreeNode(NodeType type) : nodeType(type) {}

    bool isLeaf() const {
        return children.empty();
    }
};

// 2-3-4 Tree class
template <typename KeyType, typename ValueType>
class TwoThreeFourTree {
private:
    TreeNode<KeyType, ValueType>* root;

    // Function to insert a key-value pair into a 2-3-4 Tree
    void insert(TreeNode<KeyType, ValueType>*& node, KeyType key, ValueType value) {
        if (node == nullptr) {
            node = new TreeNode<KeyType, ValueType>(TWO_NODE);
            node->keys.push_back(key);
            node->values.push_back(value);
            return;
        }

        if (node->isLeaf()) {
            insertIntoNode(node, key, value);
        } else {
            int childIndex = getChildIndex(node, key);
            insert(node->children[childIndex], key, value);
        }

        splitNode(node);
    }

    // Function to insert a key-value pair into a node
    void insertIntoNode(TreeNode<KeyType, ValueType>*& node, KeyType key, ValueType value) {
        auto it = lower_bound(node->keys.begin(), node->keys.end(), key);
        int index = it - node->keys.begin();

        // Insert key and value into the appropriate position
        node->keys.insert(it, key);
        node->values.insert(node->values.begin() + index, value);
    }

    // Function to split a node if needed
    void splitNode(TreeNode<KeyType, ValueType>*& node) {
        if (node->keys.size() <= 3) {
            return; // Node is within limits
        }

        TreeNode<KeyType, ValueType>* parent = node->isLeaf() ? nullptr : node;

        TreeNode<KeyType, ValueType>* newLeft = new TreeNode<KeyType, ValueType>(TWO_NODE);
        TreeNode<KeyType, ValueType>* newRight = new TreeNode<KeyType, ValueType>(TWO_NODE);

        newLeft->keys.push_back(node->keys[0]);
        newRight->keys.push_back(node->keys[2]);

        if (!node->isLeaf()) {
            newLeft->children.push_back(node->children[0]);
            newLeft->children.push_back(node->children[1]);
            newRight->children.push_back(node->children[2]);
            newRight->children.push_back(node->children[3]);
        } else {
            newLeft->values.push_back(node->values[0]);
            newRight->values.push_back(node->values[2]);
        }

        if (parent == nullptr) {
            // Creating a new root
            parent = new TreeNode<KeyType, ValueType>(THREE_NODE);
            root = parent;
        }

        int parentIndex = getChildIndex(parent, node->keys[1]);
        parent->keys.insert(parent->keys.begin() + parentIndex, node->keys[1]);
        parent->children.insert(parent->children.begin() + parentIndex, newLeft);
        parent->children.insert(parent->children.begin() + parentIndex + 1, newRight);

        if (parent->keys.size() > 3) {
            // If the parent is a 4-node, split it as well
            splitNode(parent);
        }
    }

    // Function to find the index of the child to traverse based on the key
    int getChildIndex(TreeNode<KeyType, ValueType>* node, KeyType key) {
        auto it = lower_bound(node->keys.begin(), node->keys.end(), key);
        return it - node->keys.begin();
    }

public:
    TwoThreeFourTree() : root(nullptr) {}

    // Function to insert a key-value pair into the tree
    void insert(KeyType key, ValueType value) {
        insert(root, key, value);
    }

    // Function to perform an in-order traversal of the tree
    void inOrderTraversal(TreeNode<KeyType, ValueType>* node) const {
        if (node != nullptr) {
            if (node->isLeaf()) {
                for (size_t i = 0; i < node->keys.size(); ++i) {
                    cout << "(" << node->keys[i] << ", " << node->values[i] << ") ";
                }
            } else {
                for (size_t i = 0; i < node->children.size(); ++i) {
                    inOrderTraversal(node->children[i]);
                    if (i < node->keys.size()) {
                        cout << "(" << node->keys[i] << ") ";
                    }
                }
            }
        }
    }

    // Function to print the tree in in-order traversal
    void printInOrder() const {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    TwoThreeFourTree<int, string> tree;

    // Insert key-value pairs into the 2-3-4 Tree
    tree.insert(1, "One");
    tree.insert(2, "Two");
    tree.insert(3, "Three");
    tree.insert(4, "Four");
    tree.insert(5, "Five");
    tree.insert(6, "Six");
    tree.insert(7, "Seven");
    tree.insert(8, "Eight");
    tree.insert(9, "Nine");
    tree.insert(10, "Ten");
    tree.insert(11, "Eleven");
    tree.insert(12, "Twelve");
    tree.insert(13, "Thirteen");
    tree.insert(14, "Fourteen");

    // Print the 2-3-4 Tree in in-order traversal
    tree.printInOrder();

    return 0;
}


// Implementation of Balanced Tree
#include <iostream>
#include <algorithm>

template <typename KeyType, typename ValueType>
struct AVLNode {
    KeyType key;
    ValueType value;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(KeyType k, ValueType v)
        : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

template <typename KeyType, typename ValueType>
class AVLTree {
private:
    AVLNode<KeyType, ValueType>* root;

    int height(AVLNode<KeyType, ValueType>* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(AVLNode<KeyType, ValueType>* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode<KeyType, ValueType>* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    AVLNode<KeyType, ValueType>* rotateRight(AVLNode<KeyType, ValueType>* y) {
        AVLNode<KeyType, ValueType>* x = y->left;
        AVLNode<KeyType, ValueType>* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode<KeyType, ValueType>* rotateLeft(AVLNode<KeyType, ValueType>* x) {
        AVLNode<KeyType, ValueType>* y = x->right;
        AVLNode<KeyType, ValueType>* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode<KeyType, ValueType>* insert(AVLNode<KeyType, ValueType>* node, KeyType key, ValueType value) {
        if (!node) {
            return new AVLNode<KeyType, ValueType>(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            // Duplicate keys not allowed in this example
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->key) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (key > node->right->key) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void inOrderTraversal(AVLNode<KeyType, ValueType>* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << "(" << node->key << ", " << node->value << ") ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(KeyType key, ValueType value) {
        root = insert(root, key, value);
    }

    void printInOrder() {
        std::cout << "In-order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree<int, std::string> avlTree;

    avlTree.insert(10, "Ten");
    avlTree.insert(20, "Twenty");
    avlTree.insert(30, "Thirty");
    avlTree.insert(15, "Fifteen");
    avlTree.insert(5, "Five");

    avlTree.printInOrder();

    return 0;
}


// Implementation of Splay Tree
#include <iostream>

template <typename KeyType, typename ValueType>
struct SplayNode {
    KeyType key;
    ValueType value;
    SplayNode* left;
    SplayNode* right;

    SplayNode(KeyType k, ValueType v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
};

template <typename KeyType, typename ValueType>
class SplayTree {
private:
    SplayNode<KeyType, ValueType>* root;

    // Zig step in the splaying process
    SplayNode<KeyType, ValueType>* zig(SplayNode<KeyType, ValueType>* x) {
        SplayNode<KeyType, ValueType>* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    // Zag step in the splaying process
    SplayNode<KeyType, ValueType>* zag(SplayNode<KeyType, ValueType>* x) {
        SplayNode<KeyType, ValueType>* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Splay the node with the given key to the root
    SplayNode<KeyType, ValueType>* splay(SplayNode<KeyType, ValueType>* root, KeyType key) {
        if (!root || root->key == key) {
            return root;
        }

        if (key < root->key) {
            if (!root->left) {
                return root;
            }

            // Zig-Zig
            if (key < root->left->key) {
                root->left->left = splay(root->left->left, key);
                root = zig(root);
            }
            // Zig-Zag
            else if (key > root->left->key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right) {
                    root->left = zag(root->left);
                }
            }

            return (root->left) ? zig(root) : root;
        } else {
            if (!root->right) {
                return root;
            }

            // Zag-Zig
            if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left) {
                    root->right = zig(root->right);
                }
            }
            // Zag-Zag
            else if (key > root->right->key) {
                root->right->right = splay(root->right->right, key);
                root = zag(root);
            }

            return (root->right) ? zag(root) : root;
        }
    }

    // Helper function to insert a key-value pair into the tree
    SplayNode<KeyType, ValueType>* insert(SplayNode<KeyType, ValueType>* root, KeyType key, ValueType value) {
        if (!root) {
            return new SplayNode<KeyType, ValueType>(key, value);
        }

        root = splay(root, key);

        if (key < root->key) {
            SplayNode<KeyType, ValueType>* newNode = new SplayNode<KeyType, ValueType>(key, value);
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
            return newNode;
        } else if (key > root->key) {
            SplayNode<KeyType, ValueType>* newNode = new SplayNode<KeyType, ValueType>(key, value);
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
            return newNode;
        } else {
            // Duplicate keys not allowed in this example
            return root;
        }
    }

    // Helper function to perform an in-order traversal of the tree
    void inOrderTraversal(SplayNode<KeyType, ValueType>* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << "(" << node->key << ", " << node->value << ") ";
            inOrderTraversal(node->right);
        }
    }

public:
    SplayTree() : root(nullptr) {}

    // Function to insert a key-value pair into the tree
    void insert(KeyType key, ValueType value) {
        root = insert(root, key, value);
    }

    // Function to perform an in-order traversal of the tree
    void printInOrder() {
        std::cout << "In-order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    SplayTree<int, std::string> splayTree;

    splayTree.insert(10, "Ten");
    splayTree.insert(20, "Twenty");
    splayTree.insert(30, "Thirty");
    splayTree.insert(15, "Fifteen");
    splayTree.insert(5, "Five");

    splayTree.printInOrder();

    return 0;
}


// Implementation of QuadTree
#include <iostream>
#include <vector>

template <typename T>
struct Point {
    T x, y;

    Point(T x, T y) : x(x), y(y) {}
};

template <typename T>
struct Rectangle {
    T x, y, width, height;

    Rectangle(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {}

    bool contains(const Point<T>& point) const {
        return (point.x >= x && point.x < x + width && point.y >= y && point.y < y + height);
    }

    bool intersects(const Rectangle<T>& other) const {
        return (x < other.x + other.width && x + width > other.x &&
                y < other.y + other.height && y + height > other.y);
    }
};

template <typename T>
class Quadtree {
private:
    static const size_t MAX_CAPACITY = 4;

    struct QuadNode {
        Rectangle<T> boundary;
        std::vector<Point<T>> points;
        QuadNode* northwest;
        QuadNode* northeast;
        QuadNode* southwest;
        QuadNode* southeast;

        QuadNode(T x, T y, T width, T height)
            : boundary(x, y, width, height), northwest(nullptr), northeast(nullptr),
              southwest(nullptr), southeast(nullptr) {}

        ~QuadNode() {
            delete northwest;
            delete northeast;
            delete southwest;
            delete southeast;
        }
    };

    QuadNode* root;

    // Helper function to insert a point into the quadtree
    QuadNode* insert(QuadNode* node, const Point<T>& point) {
        if (!node) {
            return new QuadNode(point.x, point.y, 1, 1);
        }

        if (node->points.size() < MAX_CAPACITY && !node->northwest) {
            // If the node has space for more points, add the point
            node->points.push_back(point);
        } else {
            // If the node is at capacity or is an internal node, subdivide and insert
            T halfWidth = node->boundary.width / 2;
            T halfHeight = node->boundary.height / 2;

            if (!node->northwest) {
                node->northwest = new QuadNode(node->boundary.x, node->boundary.y, halfWidth, halfHeight);
                node->northeast = new QuadNode(node->boundary.x + halfWidth, node->boundary.y, halfWidth, halfHeight);
                node->southwest = new QuadNode(node->boundary.x, node->boundary.y + halfHeight, halfWidth, halfHeight);
                node->southeast = new QuadNode(node->boundary.x + halfWidth, node->boundary.y + halfHeight, halfWidth, halfHeight);

                // Move existing points to appropriate sub-quads
                for (const auto& existingPoint : node->points) {
                    insert(node, existingPoint);
                }

                node->points.clear();
            }

            // Insert the new point into the appropriate sub-quad
            if (node->northwest->boundary.contains(point)) {
                node->northwest = insert(node->northwest, point);
            } else if (node->northeast->boundary.contains(point)) {
                node->northeast = insert(node->northeast, point);
            } else if (node->southwest->boundary.contains(point)) {
                node->southwest = insert(node->southwest, point);
            } else {
                node->southeast = insert(node->southeast, point);
            }
        }

        return node;
    }

    // Helper function to query points in a given range
    void queryRange(const QuadNode* node, const Rectangle<T>& range, std::vector<Point<T>>& result) const {
        if (!node) {
            return;
        }

        if (!node->northwest && range.intersects(node->boundary)) {
            for (const auto& point : node->points) {
                if (range.contains(point)) {
                    result.push_back(point);
                }
            }
        } else {
            queryRange(node->northwest, range, result);
            queryRange(node->northeast, range, result);
            queryRange(node->southwest, range, result);
            queryRange(node->southeast, range, result);
        }
    }

public:
    Quadtree(T width, T height) : root(new QuadNode(0, 0, width, height)) {}

    ~Quadtree() {
        delete root;
    }

    // Function to insert a point into the quadtree
    void insert(const Point<T>& point) {
        root = insert(root, point);
    }

    // Function to query points within a given range
    std::vector<Point<T>> queryRange(const Rectangle<T>& range) const {
        std::vector<Point<T>> result;
        queryRange(root, range, result);
        return result;
    }
};

int main() {
    Quadtree<int> quadtree(100, 100);

    quadtree.insert(Point<int>(10, 20));
    quadtree.insert(Point<int>(30, 40));
    quadtree.insert(Point<int>(50, 60));
    quadtree.insert(Point<int>(70, 80));

    Rectangle<int> queryRange(0, 0, 60, 60);
    std::vector<Point<int>> pointsInRange = quadtree.queryRange(queryRange);

    std::cout << "Points in range: ";
    for (const auto& point : pointsInRange) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}


// Implementation of Octree
#include <iostream>
#include <vector>

template <typename T>
struct Point3D {
    T x, y, z;

    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
};

template <typename T>
struct BoundingBox {
    T minX, minY, minZ, maxX, maxY, maxZ;

    BoundingBox(T minX, T minY, T minZ, T maxX, T maxY, T maxZ)
        : minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {}

    bool contains(const Point3D<T>& point) const {
        return (point.x >= minX && point.x <= maxX &&
                point.y >= minY && point.y <= maxY &&
                point.z >= minZ && point.z <= maxZ);
    }

    bool intersects(const BoundingBox<T>& other) const {
        return (minX <= other.maxX && maxX >= other.minX &&
                minY <= other.maxY && maxY >= other.minY &&
                minZ <= other.maxZ && maxZ >= other.minZ);
    }
};

template <typename T>
class Octree {
private:
    static const size_t MAX_CAPACITY = 8;

    struct OctreeNode {
        BoundingBox<T> boundingBox;
        std::vector<Point3D<T>> points;
        OctreeNode* children[8];

        OctreeNode(const BoundingBox<T>& box)
            : boundingBox(box) {
            for (size_t i = 0; i < 8; ++i) {
                children[i] = nullptr;
            }
        }

        ~OctreeNode() {
            for (size_t i = 0; i < 8; ++i) {
                delete children[i];
            }
        }
    };

    OctreeNode* root;

    // Helper function to insert a point into the octree
    OctreeNode* insert(OctreeNode* node, const Point3D<T>& point) {
        if (!node) {
            return new OctreeNode(BoundingBox<T>(point.x, point.y, point.z, point.x, point.y, point.z));
        }

        if (node->points.size() < MAX_CAPACITY && !node->children[0]) {
            // If the node has space for more points, add the point
            node->points.push_back(point);
        } else {
            // If the node is at capacity or is an internal node, subdivide and insert
            T midX = (node->boundingBox.minX + node->boundingBox.maxX) / 2;
            T midY = (node->boundingBox.minY + node->boundingBox.maxY) / 2;
            T midZ = (node->boundingBox.minZ + node->boundingBox.maxZ) / 2;

            if (!node->children[0]) {
                node->children[0] = new OctreeNode(BoundingBox<T>(node->boundingBox.minX, node->boundingBox.minY, node->boundingBox.minZ, midX, midY, midZ));
                node->children[1] = new OctreeNode(BoundingBox<T>(midX, node->boundingBox.minY, node->boundingBox.minZ, node->boundingBox.maxX, midY, midZ));
                node->children[2] = new OctreeNode(BoundingBox<T>(node->boundingBox.minX, midY, node->boundingBox.minZ, midX, node->boundingBox.maxY, midZ));
                node->children[3] = new OctreeNode(BoundingBox<T>(midX, midY, node->boundingBox.minZ, node->boundingBox.maxX, node->boundingBox.maxY, midZ));
                node->children[4] = new OctreeNode(BoundingBox<T>(node->boundingBox.minX, node->boundingBox.minY, midZ, midX, midY, node->boundingBox.maxZ));
                node->children[5] = new OctreeNode(BoundingBox<T>(midX, node->boundingBox.minY, midZ, node->boundingBox.maxX, midY, node->boundingBox.maxZ));
                node->children[6] = new OctreeNode(BoundingBox<T>(node->boundingBox.minX, midY, midZ, midX, node->boundingBox.maxY, node->boundingBox.maxZ));
                node->children[7] = new OctreeNode(BoundingBox<T>(midX, midY, midZ, node->boundingBox.maxX, node->boundingBox.maxY, node->boundingBox.maxZ));

                // Move existing points to appropriate sub-octants
                for (const auto& existingPoint : node->points) {
                    insert(node, existingPoint);
                }

                node->points.clear();
            }

            // Insert the new point into the appropriate sub-octant
            for (size_t i = 0; i < 8; ++i) {
                if (node->children[i]->boundingBox.contains(point)) {
                    node->children[i] = insert(node->children[i], point);
                    break;
                }
            }
        }

        return node;
    }

    // Helper function to query points in a given range
    void queryRange(const OctreeNode* node, const BoundingBox<T>& range, std::vector<Point3D<T>>& result) const {
        if (!node) {
            return;
        }

        if (!node->children[0] && range.intersects(node->boundingBox)) {
            for (const auto& point : node->points) {
                if (range.contains(point)) {
                    result.push_back(point);
                }
            }
        } else {
            for (size_t i = 0; i < 8; ++i) {
                queryRange(node->children[i], range, result);
            }
        }
    }

public:
    Octree(T width, T height, T depth) : root(new OctreeNode(BoundingBox<T>(0, 0, 0, width, height, depth))) {}

    ~Octree() {
        delete root;
    }

    // Function to insert a point into the octree
    void insert(const Point3D<T>& point) {
        root = insert(root, point);
    }

    // Function to query points within a given range
    std::vector<Point3D<T>> queryRange(const BoundingBox<T>& range) const {
        std::vector<Point3D<T>> result;
        queryRange(root, range, result);
        return result;
    }
};

int main() {
    Octree<int> octree(100, 100, 100);

    octree.insert(Point3D<int>(10, 20, 30));
    octree.insert(Point3D<int>(30, 40, 50));
    octree.insert(Point3D<int>(50, 60, 70));
    octree.insert(Point3D<int>(70, 80, 90));

    BoundingBox<int> queryRange(0, 0, 0, 60, 60, 60);
    std::vector<Point3D<int>> pointsInRange = octree.queryRange(queryRange);

    std::cout << "Points in range: ";
    for (const auto& point : pointsInRange) {
        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ") ";
    }
    std::cout << std::endl;

    return 0;
}


// Implementation of Trie(Prefix Tree)
#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    // Function to insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }

        current->isEndOfWord = true;
    }

    // Function to search for a word in the Trie
    bool search(const std::string& word) const {
        TrieNode* current = root;

        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }

        return current->isEndOfWord;
    }

    // Function to check if a word has a prefix in the Trie
    bool startsWith(const std::string& prefix) const {
        TrieNode* current = root;

        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }

        return true;
    }

    // Destructor to free Trie nodes
    ~Trie() {
        deleteTrie(root);
    }

private:
    // Helper function to recursively delete Trie nodes
    void deleteTrie(TrieNode* node) {
        if (!node) {
            return;
        }

        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }

        delete node;
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");

    // Search for words in the Trie
    std::cout << "Search results:\n";
    std::cout << "apple: " << (trie.search("apple") ? "Found" : "Not found") << "\n";
    std::cout << "app: " << (trie.search("app") ? "Found" : "Not found") << "\n";
    std::cout << "apricot: " << (trie.search("apricot") ? "Found" : "Not found") << "\n";
    std::cout << "orange: " << (trie.search("orange") ? "Found" : "Not found") << "\n";

    // Check for word prefixes in the Trie
    std::cout << "\nPrefix checks:\n";
    std::cout << "app: " << (trie.startsWith("app") ? "Has prefix" : "Doesn't have prefix") << "\n";
    std::cout << "ban: " << (trie.startsWith("ban") ? "Has prefix" : "Doesn't have prefix") << "\n";
    std::cout << "ora: " << (trie.startsWith("ora") ? "Has prefix" : "Doesn't have prefix") << "\n";

    return 0;
}
