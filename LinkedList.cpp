#include <iostream>
using namespace std;

// Structure for Doubly Linked list
struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string value) {
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublLL {
private:
    Node* head;
    Node* tail;

public:
    DoublLL(string data) {
        Node* new_node = new Node(data);
        head = new_node;
        tail = new_node;
    }

    void append(string data) {
        Node* new_node = new Node(data);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void display() {
        Node* temp = head;
        cout << "null ";
        while (temp != nullptr) {
            cout << "<- prev | ";
            cout << " data : ";
            cout << temp->data;
            cout << " | next -> ";
            temp = temp->next;
        }
        cout << " null";
        cout << endl;
    }
};

int main() {
    cout << "_____________________ DOUBLE LINKED LIST _____________________\n";
    // Double Linked List
    DoublLL dll("Modi");
    // head -> nullptr

    dll.append("Emmanuel");
    dll.append("Advaith");
    cout << "From forward\n";
    dll.display();

    return 0;
}
