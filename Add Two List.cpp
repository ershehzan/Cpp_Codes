#include <iostream>
using namespace std;

// Node definition
class Node {
  public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};

// Solution class as provided above
class Solution {
  public:
    Node* reverse(Node* curr, Node* prev) {
        if (curr == NULL) return prev;
        Node* front = curr->next;
        curr->next = prev;
        return reverse(front, curr);
    }

    Node* addTwoLists(Node* first, Node* sec) {
        first = reverse(first, NULL);
        sec = reverse(sec, NULL);

        Node* curr1 = first;
        Node* curr2 = sec;
        Node* head = NULL;
        Node* tail = NULL;

        int carry = 0;

        while (curr1 && curr2) {
            int sum = curr1->data + curr2->data + carry;
            carry = sum / 10;

            Node* newNode = new Node(sum % 10);

            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            int sum = curr1->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
        }

        while (curr2) {
            int sum = curr2->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
        }

        while (carry) {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

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

int main() {
    // Example: 1st list: 2 -> 4 -> 3 (represents 243)
    //          2nd list: 5 -> 6 -> 4 (represents 564)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node* first = createList(arr1, n1);
    Node* second = createList(arr2, n2);

    Solution sol;
    Node* result = sol.addTwoLists(first, second);

    cout << "Resultant List: ";
    printList(result);

    // Free memory (not strictly necessary for small test, but good practice)
    while (result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
