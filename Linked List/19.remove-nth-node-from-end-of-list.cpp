/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.63%)
 * Total Accepted:    318.6K
 * Total Submissions: 947K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead -> next = head;

        ListNode* p =dummyHead;
        ListNode* q = dummyHead;

        for(int i = 0; i< n+1;i++)
            q = q->next;

        while(q != NULL){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode =  p->next;
        p->next = delNode->next;
        delete delNode;
        
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
