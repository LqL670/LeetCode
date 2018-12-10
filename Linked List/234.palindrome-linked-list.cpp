/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.62%)
 * Total Accepted:    209.9K
 * Total Submissions: 606K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* fast=head->next;
        ListNode* low =head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            low=low->next;
        }
        ListNode* cur=low->next;
        low->next=NULL;
        ListNode* node1=NULL;
        while(cur!=NULL){
            ListNode* node2=cur->next;
            cur->next=node1;
            node1=cur;
            cur=node2;
        }
        while(node1!=NULL && head!=NULL){
            if(node1->val!=head->val)
                return false;
            else{
                node1=node1->next;
                head=head->next;
            }
        }
        return true;
    }
};
