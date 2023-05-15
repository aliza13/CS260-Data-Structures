#include <iostream>
#include <new>
#include <cstdlib> 

using std::cout;
using std::endl;
using std::cin;

// linked list
struct Node { 
    int data;
    Node* next; // node ptr will point to the next node in linked list
};

class LinkedList {
private:
    Node* head; // Node* is a pointer type

public:
// insert function that takes a value and inserts it into a given position into the list
    LinkedList(){
        head = NULL; // list is empty
    }

    void insert (int data, int n) {
        Node* temp = new Node(); 
        temp -> data = data; // temp pts to data
        temp -> next = NULL; // next is empty

        if (n == 1) {
            temp -> next = head; 
            head = temp;
            return;
        }

        Node* temp2 = head; // another ptr to Node, starts at head
        for (int i = 0; i < n-2; i++) { 
            temp2 = temp2 -> next;

        }
            temp -> next = temp2 -> next; // building links
            temp2 -> next = temp; 
    }

    void deleteNode(){
// remove function that takes a position and removes the value stored at that position of the list and returns it
        int n;
        cout << "Enter the position of the node you want to be deleted: ";
        cin >> n;

        Node* temp = head; // temp var pointing at head
        // test should be if head is the wanted deletion
        if (n == 1) { // special case: deleting the head node
            head = head->next;
            delete temp;
            return;
        }

        for(int i = 0; i < n-2; i++){

            temp = temp -> next;
            if (temp == NULL || temp->next == NULL) { // position is out of bounds
                cout << "Error: Position out of bounds :( " << endl;
                return;
            }
        }

        Node* temp2 = temp -> next; // what n is
        temp -> next = temp2 -> next; // + 1
        delete(temp2); 
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





// a get function that takes a position and returns that value without removing it
// myList.get(somePosition)



// test that that position exists

int main(){
    LinkedList ll;

    ll.insert(1,1);
    ll.insert(4,2);
    ll.insert(5,3);

    ll.printList(); // first test worked!
    ll.deleteNode();
    ll.printList(); 

    ll.deleteNode();
    ll.printList(); 

    ll.deleteNode();
    ll.printList();

    return 0;
}