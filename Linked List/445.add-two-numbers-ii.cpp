/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (48.10%)
 * Total Accepted:    70.6K
 * Total Submissions: 146.8K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> stack1;
       stack<int> stack2;
       while(l1){
           stack1.push(l1->val);
           l1 = l1->next;
       }
       while(l2){
           stack2.push(l2->val);
           l2 = l2->next;
       }
       ListNode* head = NULL;
       int sum = 0;
       while(!stack1.empty() || !stack2.empty()){
           sum/=10;

           if(!stack1.empty()){
               sum += stack1.top();
               stack1.pop();
           }
           if(!stack2.empty()){
               sum += stack2.top();
               stack2.pop();
           }
           ListNode* tmp = new ListNode(sum%10);
           tmp->next = head;
           head = tmp;
       }
       if(sum>=10){
           ListNode* tmp = new ListNode(1);
           tmp->next = head;
           head =tmp;
       }

       return head;
    }
};
