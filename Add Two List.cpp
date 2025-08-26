#include <iostream>
using namespace std;

// Node definition for singly linked list
class Node {
  public:
    int data;       // Stores the value of the node
    Node* next;     // Pointer to the next node in the list
    Node(int val){
        data = val;
        next = NULL;
    }
};

// Solution class encapsulates methods to add two numbers represented by linked lists
class Solution {
  public:
    // Recursive function to reverse a linked list
    // curr: current node being processed
    // prev: previous node in the reversed list
    Node* reverse(Node* curr, Node* prev) {
        if (curr == NULL) return prev;      // Base case: end of list reached
        Node* front = curr->next;           // Store next node
        curr->next = prev;                  // Reverse the link
        return reverse(front, curr);        // Recursive call for next node
    }

    // Adds two numbers represented by linked lists and returns the sum as a linked list
    Node* addTwoLists(Node* first, Node* sec) {
        // Reverse both lists to start addition from the least significant digit
        first = reverse(first, NULL);
        sec = reverse(sec, NULL);

        Node* curr1 = first;    // Pointer to traverse first list
        Node* curr2 = sec;      // Pointer to traverse second list
        Node* head = NULL;      // Head of the result list
        Node* tail = NULL;      // Tail of the result list

        int carry = 0;          // Stores carry value during addition

        // Add nodes from both lists while both are non-empty
        while (curr1 && curr2) {
            int sum = curr1->data + curr2->data + carry;    // Sum of digits and carry
            carry = sum / 10;                               // Update carry

            Node* newNode = new Node(sum % 10);             // Create new node for the digit

            if (head == NULL) {
                head = tail = newNode;                      // Initialize result list
            } 
            else {
                tail->next = newNode;                       // Append to result list
                tail = tail->next;
            }

            curr1 = curr1->next;    // Move to next node in first list
            curr2 = curr2->next;    // Move to next node in second list
        }

        // Process remaining nodes in first list (if any)
        while (curr1) {
            int sum = curr1->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
        }

        // Process remaining nodes in second list (if any)
        while (curr2) {
            int sum = curr2->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
        }

        // If there is still a carry, add a new node
        while (carry) {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // Reverse the result to restore the proper order and return
        return reverse(head, NULL);
    }
};

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    // Example input: 1st list: 2 -> 4 -> 3 (represents 243)
    //               2nd list: 5 -> 6 -> 4 (represents 564)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create linked lists from arrays
    Node* first = createList(arr1, n1);
    Node* second = createList(arr2, n2);

    Solution sol;
    Node* result = sol.addTwoLists(first, second);   // Add the two numbers

    cout << "Resultant List: ";
    printList(result);                               // Output the result

    // Free memory used by result list (good practice)
    while (result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}






