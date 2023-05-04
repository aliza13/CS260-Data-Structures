#include <iostream>
#include <string>

using std::cout; // better practice than using namespace
using std::endl; // global
using std::string;

// template<class T>
//     public:
//         Stack(){
//             top = nullptr;
//         }
//     void push(int = newData) {
        
//         top = newNode
//     }
// }

// node structure that has two things: an int (data) and a pointer (next)
struct Node { // capitialize name 
    int data;
    Node* next; // node ptr will point to the next node in linked list
}; // Node and next are ptrs

class LinkedQueue {
private: // only accessible w in the class 
    // can only be accessed within LQ class
    Node* head; // Node* is a pointer type
    Node* tail;

public: // funcs in here can be called anywhere in code
    LinkedQueue() { // constructor, special member func called automatically when obj of class is created
    // LQ is empty rn, then when ptrs are updated, the NULL value can change
        head = NULL; // ptrs to node structs first
        tail = NULL; // points to last node in queue
    }
    
    // add element to tail Q
    void enqueue(int newData) {
        Node* newNode = new Node; // makes new node struct, assigns newData arg to data field (see struct)
        (*newNode).data = newData;
        (*newNode).next = NULL;
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // remove 1st element in queue
    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = head; // temp ptr as first node
            head = head->next; // then updates... also -> is said to be common syntax 
            if (head == NULL) {
                tail = NULL;
            }
            delete temp; // don't need temp anymore
        }
    }
    
    void printQueue() {
    Node* current = head;
    while (current != NULL) {
        cout << (*current).data << " ";
        current = (*current).next;
    }
    cout << endl;
}
};


// has to have a main func no matter what
int main(){
    LinkedQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(0);
    q.dequeue();
    q.enqueue(10000);
    q.dequeue();

    q.printQueue();

    return 0;

}