#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";
    
    // Creating the circular linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            Node* temp = new Node(val);
            tail->next = temp;
            tail = temp;
        }
    }
    
  
    tail->next = head; 
  
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            cout << "Loop exists!" << endl;
            break;
        }
    }
    
    if (fast == NULL || fast->next == NULL) {
        cout << "No Loop" << endl;
    }
    
   
    cout << "Circular Linked List: ";
    Node* trav = head;
    do {
        cout << trav->data << " ";
        trav = trav->next;
    } while (trav != head);
    
    return 0;
}
