// #include <iostream>
// using namespace std;


// // Deque using Array
// class Deque {
// private:
//     int* arr;
//     int front;
//     int rear;
//     int capacity;

// public:
//     // Constructor
//     Deque(int size) : arr(new int[size]), front(-1), rear(-1), capacity(size) {}

//     // Destructor
//     ~Deque() {
//         delete[] arr;
//     }

//     // Function to check if the deque is empty
//     bool isEmpty() {
//         return front == -1;
//     }

//     // Function to check if the deque is full
//     bool isFull() {
//         return (front == 0 && rear == capacity - 1) || (front == rear + 1);
//     }

//     // Function to insert an element at the front of the deque
//     void insertFront(int value) {
//         if (isFull()) {
//             std::cout << "Deque overflow\n";
//             return;
//         }

//         if (isEmpty()) {
//             front = rear = 0;
//         } else if (front == 0) {
//             front = capacity - 1;
//         } else {
//             front--;
//         }

//         arr[front] = value;
//     }

//     // Function to insert an element at the rear of the deque
//     void insertRear(int value) {
//         if (isFull()) {
//             std::cout << "Deque overflow\n";
//             return;
//         }

//         if (isEmpty()) {
//             front = rear = 0;
//         } else if (rear == capacity - 1) {
//             rear = 0;
//         } else {
//             rear++;
//         }

//         arr[rear] = value;
//     }

//     // Function to delete an element from the front of the deque
//     void deleteFront() {
//         if (isEmpty()) {
//             std::cout << "Deque underflow\n";
//             return;
//         }

//         if (front == rear) {
//             front = rear = -1;
//         } else if (front == capacity - 1) {
//             front = 0;
//         } else {
//             front++;
//         }
//     }

//     // Function to delete an element from the rear of the deque
//     void deleteRear() {
//         if (isEmpty()) {
//             std::cout << "Deque underflow\n";
//             return;
//         }

//         if (front == rear) {
//             front = rear = -1;
//         } else if (rear == 0) {
//             rear = capacity - 1;
//         } else {
//             rear--;
//         }
//     }

//     // Function to get the front element of the deque
//     int getFront() {
//         if (isEmpty()) {
//             std::cout << "Deque is empty\n";
//             return -1; // Assuming -1 as an indicator of an empty deque
//         }
//         return arr[front];
//     }

//     // Function to get the rear element of the deque
//     int getRear() {
//         if (isEmpty()) {
//             std::cout << "Deque is empty\n";
//             return -1; // Assuming -1 as an indicator of an empty deque
//         }
//         return arr[rear];
//     }

//     void printDeque() {
//         if (isEmpty()) {
//             std::cout << "Deque is empty\n";
//             return;
//         }

//         if (front <= rear) {
//             for (int i = front; i <= rear; i++) {
//                 std::cout << arr[i] << " ";
//             }
//         } else {
//             for (int i = front; i < capacity; i++) {
//                 std::cout << arr[i] << " ";
//             }
//             for (int i = 0; i <= rear; i++) {
//                 std::cout << arr[i] << " ";
//             }
//         }

//         std::cout << std::endl;
//     }
// };

// // Example usage
// int main() {
//     Deque myDeque(5);

//     myDeque.insertFront(10);
//     myDeque.insertRear(20);
//     myDeque.insertRear(30);
//     myDeque.insertFront(90);
//     myDeque.insertFront(80);
//     myDeque.printDeque();
//     // std::cout << "Front element: " << myDeque.getFront() << std::endl;
//     // std::cout << "Rear element: " << myDeque.getRear() << std::endl;

//     // myDeque.deleteFront();
//     // myDeque.deleteRear();

//     // std::cout << "Updated front element: " << myDeque.getFront() << std::endl;
//     // std::cout << "Updated rear element: " << myDeque.getRear() << std::endl;

//     return 0;
// }


// // Deque using linked list
// #include <iostream>

// // Node structure for the doubly linked list
// struct Node {
//     int data;
//     Node* next;
//     Node* prev;

//     // Constructor
//     Node(int value) : data(value), next(nullptr), prev(nullptr) {}
// };

// class Deque {
// private:
//     Node* front;
//     Node* rear;

// public:
//     // Constructor
//     Deque() : front(nullptr), rear(nullptr) {}

//     // Function to check if the deque is empty
//     bool isEmpty() {
//         return front == nullptr;
//     }

//     // Function to insert an element at the front of the deque
//     void insertFront(int value) {
//         Node* newNode = new Node(value);
//         if (isEmpty()) {
//             front = rear = newNode;
//         } else {
//             newNode->next = front;
//             front->prev = newNode;
//             front = newNode;
//         }
//     }

//     // Function to insert an element at the rear of the deque
//     void insertRear(int value) {
//         Node* newNode = new Node(value);
//         if (isEmpty()) {
//             front = rear = newNode;
//         } else {
//             newNode->prev = rear;
//             rear->next = newNode;
//             rear = newNode;
//         }
//     }

//     // Function to delete an element from the front of the deque
//     void deleteFront() {
//         if (isEmpty()) {
//             std::cout << "Deque underflow\n";
//             return;
//         }

//         Node* temp = front;
//         if (front == rear) {
//             front = rear = nullptr;
//         } else {
//             front = front->next;
//             front->prev = nullptr;
//         }
//         delete temp;
//     }

//     // Function to delete an element from the rear of the deque
//     void deleteRear() {
//         if (isEmpty()) {
//             std::cout << "Deque underflow\n";
//             return;
//         }

//         Node* temp = rear;
//         if (front == rear) {
//             front = rear = nullptr;
//         } else {
//             rear = rear->prev;
//             rear->next = nullptr;
//         }
//         delete temp;
//     }

//     // Function to get the front element of the deque
//     int getFront() {
//         if (isEmpty()) {
//             std::cout << "Deque is empty\n";
//             return -1; // Assuming -1 as an indicator of an empty deque
//         }
//         return front->data;
//     }

//     // Function to get the rear element of the deque
//     int getRear() {
//         if (isEmpty()) {
//             std::cout << "Deque is empty\n";
//             return -1; // Assuming -1 as an indicator of an empty deque
//         }
//         return rear->data;
//     }
// };

// // Example usage
// int main() {
//     Deque myDeque;

//     myDeque.insertFront(10);
//     myDeque.insertRear(20);
//     myDeque.insertRear(30);

//     std::cout << "Front element: " << myDeque.getFront() << std::endl;
//     std::cout << "Rear element: " << myDeque.getRear() << std::endl;

//     myDeque.deleteFront();
//     myDeque.deleteRear();

//     std::cout << "Updated front element: " << myDeque.getFront() << std::endl;
//     std::cout << "Updated rear element: " << myDeque.getRear() << std::endl;

//     return 0;
// }

// // Circular queue using array
// #include <iostream>

// class CircularQueue {
// private:
//     int* arr;
//     int front;
//     int rear;
//     int capacity;

// public:
//     // Constructor
//     CircularQueue(int size) : arr(new int[size]), front(-1), rear(-1), capacity(size) {}

//     // Destructor
//     ~CircularQueue() {
//         delete[] arr;
//     }

//     // Function to check if the circular queue is empty
//     bool isEmpty() {
//         return front == -1;
//     }

//     // Function to check if the circular queue is full
//     bool isFull() {
//         return (rear + 1) % capacity == front;
//     }

//     // Function to enqueue (add) an element to the circular queue
//     void enqueue(int value) {
//         if (isFull()) {
//             std::cout << "Queue overflow\n";
//             return;
//         }

//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % capacity;
//         }

//         arr[rear] = value;
//     }

//     // Function to dequeue (remove) an element from the circular queue
//     int dequeue() {
//         if (isEmpty()) {
//             std::cout << "Queue underflow\n";
//             return -1; // Assuming -1 as an indicator of an empty queue
//         }

//         int value = arr[front];

//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front = (front + 1) % capacity;
//         }

//         return value;
//     }

//     // Function to get the front element of the circular queue without removing it
//     int peek() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty\n";
//             return -1; // Assuming -1 as an indicator of an empty queue
//         }
//         return arr[front];
//     }
// };

// // Example usage
// int main() {
//     CircularQueue myQueue(5);

//     myQueue.enqueue(10);
//     myQueue.enqueue(20);
//     myQueue.enqueue(30);

//     std::cout << "Front element: " << myQueue.peek() << std::endl;

//     std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
//     std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

//     std::cout << "Front element: " << myQueue.peek() << std::endl;

//     return 0;
// }


// Circular queue using circular linked list
#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    CircularQueue() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~CircularQueue() {
        // Release memory when the queue is destroyed
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (add) an element to the circular queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        // Make the circular connection
        rear->next = front;
    }

    // Function to dequeue (remove) an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow\n";
            return -1; // Assuming -1 as an indicator of an empty queue
        }

        int value = front->data;
        Node* temp = front;

        if (front == rear) {
            // Last element in the queue
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front; // Maintain the circular connection
        }

        delete temp;
        return value;
    }

    // Function to get the front element of the circular queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1; // Assuming -1 as an indicator of an empty queue
        }
        return front->data;
    }
};

// Example usage
int main() {
    CircularQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    return 0;
}