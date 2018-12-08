/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (44.28%)
 * Total Accepted:    452.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        // ListNode* head = NULL;
        // if(l1->val > l2->val){
            // head = l2;
            // head->next = mergeTwoLists(l1,l2->next);
        // }else{
            // head = l1;
            // head->next =mergeTwoLists(l1->next, l2);
        // }
		ListNode* dummyHead = new ListNode(0);
		ListNode* head=dummyHead;
		while(l1 && l2){
			if(l1->val > l2->val){
				head->next = l2;
				head = head->next;
				l2= l2->next;
			}
			else if(l1->val < l2->val){
				head->next = l1;
				head = head->next;
				l1= l1->next;
			}
		}
		while(l1){
			head->next = l1;
			head = head->next;
			l1= l1->next;
		}
		while(l2){
			head->next = l2;
			head = head->next;
			l2= l2->next;
		}
		
		ListNode* res =dummyHead->next;
		delete dummyHead;
        return res;
    }
};
