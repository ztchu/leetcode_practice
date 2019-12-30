
#include <iostream>
#include <string>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* p = nullptr;
        while (l1 || l2) {
            int first = 0;
            if (l1) {
                first = l1->val;
                l1 = l1->next;
            }
            int second = 0;
            if (l2) {
                second = l2->val;
                l2 = l2->next;
            }
            int ret = (first + second + carry) % 10;
            carry = (first + second + carry) / 10;
            if (!head) {
                head = new ListNode(ret);
                p = head;
            }
            else {
                p->next = new ListNode(ret);
                p = p->next;
            }
        }
        if (carry && p) {
            p->next = new ListNode(carry);
        }
        return head;
    }
};

void TestList() {
    Solution so;
    ListNode* first = new ListNode(2);
    first->next = new ListNode(4);
    first->next->next = new ListNode(3);
    ListNode* second = new ListNode(0);
    /*second->next = new ListNode(6);
    second->next->next = new ListNode(4);*/

    ListNode *head = so.addTwoNumbers(first, second);
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}