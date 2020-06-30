#pragma once

#include "list/add_two_number.h"
#include "list/swap_pair.h"

namespace test_list {
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr) {
                return l2;
            }
            if (l2 == nullptr) {
                return l1;
            }

            ListNode* head = nullptr;
            ListNode* p_current = nullptr;
            while (l1 && l2) {
                ListNode* temp = nullptr;
                if (l1->val <= l2->val) {
                    temp = l1;
                    l1 = l1->next;
                }
                else {
                    temp = l2;
                    l2 = l2->next;
                }
                if (!head) {
                    head = temp;
                    p_current = temp;
                }
                else {
                    p_current->next = temp;
                    p_current = temp;
                }
            }

            p_current->next = nullptr;
            if (l1) {
                p_current->next = l1;
            }
            if (l2) {
                p_current->next = l2;
            }
            return head;
        }

        ListNode* RemoveOddNode(ListNode* head) {
            if (!head) {
                return nullptr;
            }

            head = head->next;
            ListNode* p = head;
            while (p) {
                if (p->next) {
                    p->next = p->next->next;
                    p = p->next;
                }
                else {
                    break;
                }
            }
            return head;
        }
    };

    void TestList() {
        ListNode* head = new ListNode(3, nullptr);
        //ListNode* a = new ListNode(4, nullptr);
        /*ListNode* b = new ListNode(5, nullptr);
        ListNode* c = new ListNode(6, nullptr);*/

        //head->next = a;
        /*a->next = b;
        b->next = c;*/

        Solution so;
        auto ans = so.RemoveOddNode(head);
        while (ans) {
            std::cout << ans->val << std::endl;
            ans = ans->next;
        }
        system("pause");
    }
}