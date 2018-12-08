/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (31.47%)
 * Total Accepted:    158.2K
 * Total Submissions: 502.7K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
		if(!head || !head->next) return head;
		
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
		ListNode* pre = dummyHead;
		while(pre->next){
			ListNode* cur = pre->next;
			while(cur->next &&cur->next->val == cur->val) 
				cur = cur->next;
			if(cur != pre->next) pre->next = cur->next;
			else pre = pre->next;
		}
        

       ListNode* res = dummyHead->next;
	   delete dummyHead;
	   return res;
    }
};
