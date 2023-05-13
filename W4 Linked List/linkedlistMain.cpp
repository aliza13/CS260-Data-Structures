#include <iostream>
#include <new>
#include <cstdlib>

using std::cout;
using std::endl;


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
        head = NULL;
    }

    void insert (int data, int n) {
        Node* temp = new Node(); 
        temp -> data = data; // temp pts to data
        temp -> next = nullptr; // next is empty

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



// remove function that takes a position and removes the value stored at that position of the list and returns it
// myList.remove(somePosition)


// test that the position isn't null 

// a get function that takes a position and returns that value without removing it
// myList.get(somePosition)



// test that that position exists

int main(){
    LinkedList ll;

    ll.insert(1,1);
    ll.insert(4,2);
    ll.insert(7,3);

}