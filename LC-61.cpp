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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Count the length of the list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Modulo operation to avoid unnecessary rotations
        k = k % count;
        if (k == 0) return head;

        count -= k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Rotate
        prev->next = NULL;
        ListNode* tail = curr;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        head = curr;

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

    // Input the number of rotations
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Rotate the linked list
    head = solution.rotateRight(head, k);

    // Print the updated linked list
    cout << "Rotated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}