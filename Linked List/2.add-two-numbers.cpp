/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.70%)
 * Total Accepted:    669.3K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
        if(l1 == NULL || l2 == NULL)
            return NULL;

        ListNode sumHead(0);
        ListNode* sum = &sumHead;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        int jinwei = 0;
        while(node1 != NULL && node2 !=NULL){
            ListNode* tmp = new ListNode(0);
            tmp->val = node1->val + node2->val + jinwei;
            if(tmp->val>9){
                jinwei = 1;
                tmp->val -= 10;
            }
            else
                jinwei = 0;
            sum->next = tmp;
            sum = sum->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        if(node1 == NULL && node2==NULL && jinwei){
            ListNode* tmp = new ListNode(1);
            sum->next = tmp;
            sum = sum ->next;
            jinwei = 0;
        }
        while(node1 != NULL){
            ListNode* tmp = new ListNode(0);
            tmp->val = node1->val + jinwei;
            if(tmp->val >9){
                tmp->val -= 10;
                jinwei = 1;
            }
            else
                jinwei = 0;
            sum->next=tmp;
            sum = sum->next;
            node1 = node1->next;
        }
        while(node2!=NULL){
            ListNode* tmp = new ListNode(0);
            tmp->val = node2->val + jinwei;
            if(tmp->val > 9){
                tmp-> val -= 10;
                jinwei = 1;
            }
            else
                jinwei = 0;
            sum->next=tmp;
            sum = sum->next;
            node2 = node2->next;
        }
        if(node1 == NULL && node2==NULL && jinwei){
            ListNode* tmp = new ListNode(1);
            sum->next = tmp;
            sum = sum->next;
        }
        return sumHead.next;
    }
};
