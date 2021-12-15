#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummyHead = new ListNode(INT_MIN, head);
        ListNode *lastValid = dummyHead;
        ListNode *nodeToInsert = head;
        while (nodeToInsert != nullptr) {
            ListNode *insertionSlot = dummyHead;
            while (insertionSlot->next->val < nodeToInsert->val) {
                insertionSlot = insertionSlot->next;
            }
            if (insertionSlot->next == nodeToInsert) {
                lastValid = nodeToInsert;
            } else {
                lastValid->next = nodeToInsert->next;
                nodeToInsert->next = insertionSlot->next;
                insertionSlot->next = nodeToInsert;
            }
            nodeToInsert = lastValid->next;
        }
        return dummyHead->next;
    }
};