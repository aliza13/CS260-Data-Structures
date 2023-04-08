#include <iostream>
#include <list>

using std::cout;

int main() {
    int a;
    a = 55; // initialize vars with type, var name, value
    int b = 25;
    cout << b;
    float c = 2.0;

    cout << "Hello?";
    return 0; // why return 0? 

    std::list<int> bagOfMarbles = {1,2,3,4,5};
    // methods
    bagOfMarbles.push_back(6); // add marble to back
    cout << bagOfMarbles.front(); // first marble outputted
    return 0;
    // did not print front item...
    bagOfMarbles.pop_front(); // first element is removed
    



}

// this is a comment
/* This is a multi
line comment */