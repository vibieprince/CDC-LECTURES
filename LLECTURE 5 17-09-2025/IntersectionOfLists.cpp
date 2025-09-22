#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Helper to get length of a list
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Move longer list ahead
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        // Traverse together
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};

int main() {
    // Create two linked lists with intersection
    // List A: 1 -> 2 -> 3
    //                     \
    //                      6 -> 7
    //                     /
    // List B:     4 -> 5

    // Common part
    ListNode* common = new ListNode(6);
    common->next = new ListNode(7);

    // List A
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common; // connect to common part

    // List B
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common; // connect to common part

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
