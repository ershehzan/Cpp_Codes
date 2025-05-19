#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Solution {
public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (!head) return head;
        Node* prev = head, *curr = head->next;
        while (curr) {
            if (curr->data == prev->data) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* createList(int n) {
    Node* head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Solution solution;
    int n;
    cout << "Enter number of nodes in sorted linked list: ";
    cin >> n;
    cout << "Enter elements of sorted linked list: ";
    Node* head = createList(n);

    head = solution.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}