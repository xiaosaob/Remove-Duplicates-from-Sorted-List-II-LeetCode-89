// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *prev = helper, *cur = head;
        while(cur) {
            int curVal = cur->val;
            if(cur->next && cur->next->val == curVal) {
                while(cur && cur->val == curVal) {
                    ListNode *next = cur->next;
                    free(cur);
                    cur = next;
                }
            } else {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
        }
        prev->next = NULL;
        return helper->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *newHead = NULL, *prev = NULL;
        ListNode *cur = head;
        while(cur) {
            if(!cur->next || cur->next->val != cur->val) {
                if(!newHead) newHead = cur;
                if(prev) prev->next = cur;
                prev = cur;
            } else {
                while(cur->next && cur->next->val == cur->val)
                    cur = cur->next;
            }
            cur = cur->next;
        }
        if(prev) prev->next = NULL;
        return newHead;
    }
};
