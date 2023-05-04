Assignment 3 (Linked Queue):
Based on what we know about linked lists, stacks, and queues, design a linked queue (a queue using a linked-list to store the data in the structure)
Design, implement, and test a Queue data structure that:
uses a linked-list to store values in the queue
has an enqueue method that will appropriately add a value to the back of the queue as an appropriate element
has a dequeue method that will appropriately remove an element from the front of the queue and return its value

Analyze the complexity of your implementations (at least the run-time of the add, remove, and peek methods).
A: I believe it is O(1) because it is constant time for the methods.

Tests: Be sure to include at least one test for each piece of functionality that should verify that your code is working!
A: A good test would be to test what the dequeue method does when the queue is empty. I made sure to handle this case.

What line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).
A: lines 78-86

Note: This assignment is partly to get you some practice with basic pointers if you have not used them much, to get you thinking about dynamically sizing containers, and to think about what might be efficient and what might be able to be improved.