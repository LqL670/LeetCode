/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (33.15%)
 * Total Accepted:    165.8K
 * Total Submissions: 500.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead ->next =head;

        ListNode* prev = dummyHead;
        int len = n-m+1;
        while(prev->next != NULL && m>1){
            prev = prev->next;
            m--;
        }
        ListNode* cur = prev->next;
        ListNode* post = cur->next;
        while(post != NULL && len >0){
            cur->next = post->next;
            post->next = prev->next;
            prev->next= post;
            post->next = cur->next;
            len --;
        }
        
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
