/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (35.38%)
 * Total Accepted:    143.4K
 * Total Submissions: 405.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        ListNode lessHead(0);
        ListNode moreHead(0);
        ListNode* less = &lessHead;
        ListNode* more = &moreHead;
        ListNode* cur = head;

        while(cur!=NULL){
            if(cur->val < x){
                less->next = cur;
                less = less ->next;
            }
            else{
                more ->next = cur;
                more = more->next;
            }
            cur = cur->next;
        }
        less->next = moreHead.next;
        more->next = NULL;
        return lessHead.next;
    }
};
