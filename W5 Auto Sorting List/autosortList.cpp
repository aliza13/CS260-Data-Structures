#include <iostream>
#include <new>

using std::cout;
using std::endl;
using std::cin;


struct Node { 
    int data;
    Node* next; 
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList(){
        head = NULL; 
    }

// ascending order list
    void insert (int data) {
        Node* temp = new Node(); 
        temp -> data = data; // temp pts to data
        temp -> next = NULL; // next is empty

        if (data < head ->data) { // if data is < head, insert at beginning 
            temp -> next = head; 
            head = temp;
            return;
        }

        if (head == NULL) {
            head = temp; 
        } else {
        Node* temp2 = head; 

        for (int i = 0; data < temp2 -> next -> data; i++) { // where temp2 is larger than data
            temp2 = temp2 -> next;

            }
            temp -> next = temp2 -> next; // building links
            temp2 -> next = temp; 
        }
    }

// a get function that takes a position and returns that value without removing it
    int getNode(int n) {
        Node* temp = head; // start at head node
        for (int i = 1; i < n; i++) { // traverse the list to the desired node
            if (temp == NULL) { // out of bounds
                cout << "Error: Position out of bounds :( " << endl;
                return -1; 
            }
            temp = temp->next;
        }
        return temp->data; 
    }


    /* inspiration https://www.includehelp.com/stl/print-all-elements-of-a-queue.aspx */
    void printList() {
    Node* current = head; // current ptr
    while (current != NULL) {
        cout << (*current).data << " ";
        current = (*current).next;
    }
    cout << endl;
    }
};





int main(){
    LinkedList ll;

    ll.insert(1);
    ll.insert(4);
    ll.insert(5);

    ll.printList(); 

    int positionIndex;
    cout << "Enter the index of the node you want to get: ";
    cin >> positionIndex;
    int value = ll.getNode(positionIndex);
    if (value != -1) { // test for error
        cout << "Value at position " << positionIndex << " is " << value << endl;
    }

    return 0;
}