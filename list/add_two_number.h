
#include <iostream>
#include <string>
#include <vector>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace leetcode_list {

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

        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == nullptr) {
                return head;
            }

            std::vector<ListNode*> address;
            ListNode* ptr = head;
            while (ptr) {
                address.push_back(ptr);
                ptr = ptr->next;
            }
            int len = address.size();
            if (n > len) {
                return head;
            }
            if (n == len) {
                return head->next;
            }
            ListNode* prev = address[len - 1 - n];
            ListNode* cur = address[len - n];
            prev->next = cur->next;
            return head;
        }
    };

    void Test() {
        Solution so;
        ListNode* first = new ListNode(2);
        /*first->next = new ListNode(4);
        first->next->next = new ListNode(3);
        first->next->next->next = new ListNode(5);*/
        /*ListNode* second = new ListNode(0);*/
        /*second->next = new ListNode(6);
        second->next->next = new ListNode(4);*/

        ListNode* head = so.removeNthFromEnd(first, 1);
        while (head) {
            std::cout << head->val << std::endl;
            head = head->next;
        }
    }
}