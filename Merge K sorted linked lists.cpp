#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Linked list Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Comparator for the min heap (priority_queue)
class compare {
public:
    // Return true if a > b to make a min heap
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    // Function to merge K sorted linked lists
    Node* mergeKLists(vector<Node*>& arr) {
        // Min heap to keep track of the smallest head node from each list
        priority_queue<Node*, vector<Node*>, compare> p;

        // Push the head node of each linked list into the heap
        for (Node* node : arr) {
            if (node) {
                p.push(node);
            }
        }

        // Dummy node to start building the merged list
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Extract the smallest node from the heap and add to result list
        while (!p.empty()) {
            Node* temp = p.top();
            p.pop();

            // Append this node to the result
            tail->next = temp;
            tail = tail->next;

            // If there is another node in the same list, push it to heap
            if (temp->next) {
                p.push(temp->next);
            }
        }

        return dummy->next; // Return the merged list starting from real head
    }
};

// Utility function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test mergeKLists
int main() {
    // Creating 3 sorted linked lists manually
    Node* a = new Node(1);
    a->next = new Node(4);
    a->next->next = new Node(5);

    Node* b = new Node(1);
    b->next = new Node(3);
    b->next->next = new Node(4);

    Node* c = new Node(2);
    c->next = new Node(6);

    // Vector to store heads of all K lists
    vector<Node*> lists = {a, b, c};

    // Merge lists
    Solution sol;
    Node* result = sol.mergeKLists(lists);

    // Print result
    cout << "Merged Linked List: ";
    printList(result);

    return 0;
}
