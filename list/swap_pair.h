#pragma once

#include <iostream>

namespace swap_pair {

     struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(nullptr) {}
     };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = nullptr;
        ListNode* second = head;
        ListNode* third = head->next;
        ListNode* fourth = nullptr;
        head = nullptr;
        while (second && third) {
            ListNode* fourth = third->next;
            if (!first) {
                head = third;
                first = third;
            }
            else {
                first->next = third;
            }
            
            third->next = second;
            second->next = fourth;

            first = second;
            second = fourth;
            if (second && second->next) {
                third = second->next;
            }
            else {
                break;
            }
        }
        return head;
    }
};

void Test() {
    Solution so;
    ListNode a(1), b(2);// , c(3), d(4);
    ListNode* head = &a;
    a.next = &b;
    b.next = nullptr;
    /*b.next = &c;
    c.next = &d;*/
    //d.next = nullptr;
    auto ans = so.swapPairs(head);
    while (ans) {
        std::cout << ans->val << " ";
        ans = ans->next;
    }
    std::cout << std::endl;
}
}