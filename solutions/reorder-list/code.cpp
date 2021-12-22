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
    void reorderList(ListNode* head) {
        // [1,2,3,4,5,6] -> [1,2,3] [4,5,6]
        ListNode* mid = divide(head);
        // [4,5,6] -> [6,5,4]
        ListNode* rev = reverse(mid);
        // [1,2,3] , [4,5,6] -> [1,4,2,5,3,6]
        zipList(head, rev);
    }
    
    ListNode* divide(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head!=nullptr){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    void zipList(ListNode* l1, ListNode* l2){
        while(l1 != nullptr && l2 != nullptr){
            ListNode* l1next = l1->next;
            ListNode* l2Next = l2->next;
            l1->next = l2;
            l2->next = l1next;
            l1 = l1next;
            l2 = l2Next;
        }
    }
};