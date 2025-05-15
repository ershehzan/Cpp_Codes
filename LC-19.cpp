#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        // Count the total number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Calculate the position from the start
        count -= n;

        // If the node to be removed is the head
        if (count == 0) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Traverse to the node before the one to be removed
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Remove the nth node from the end
        prev->next = curr->next;
        delete curr;

        return head;
    }
};

int main() {
    Solution solution;

    // Create a linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    // Input the position of the node to be removed from the end
    int pos;
    cout << "Enter the position of the node to be removed from the end: ";
    cin >> pos;

    // Remove the nth node from the end
    head = solution.removeNthFromEnd(head, pos);

    // Print the updated linked list
    cout << "Updated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}