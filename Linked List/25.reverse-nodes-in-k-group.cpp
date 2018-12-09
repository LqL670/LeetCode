/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (34.25%)
 * Total Accepted:    155.2K
 * Total Submissions: 452.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next= head;
        ListNode* tmp = head;
        ListNode* res = dummyHead;
        int len = 0;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        if(len<k || k==1)
            return head;

        while(len>=k){
            for(int i = 0; i<k-1;i++){
                ListNode* node = dummyHead->next;
                dummyHead->next = head->next;
                head->next =  dummyHead->next->next;
                dummyHead->next->next = node;
            }
            dummyHead = head;
            head = head->next;
            len -=k;
        }
        ListNode* res1 = res->next;
        delete res;
        return res1;
    }
};
