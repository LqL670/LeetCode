/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (28.88%)
 * Total Accepted:    133.7K
 * Total Submissions: 462.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
 
 //my solution
// class Solution {
// public:
    // void reorderList(ListNode* head) {
        // if(head==NULL || head->next==NULL|| head->next->next==NULL) return ;

        // ListNode* cur=head;
        // int len=1;
        // while(cur->next!=NULL){
            // cur=cur->next;
            // len++;
        // }
        // if(len==3){
            // head->next->next=NULL;
            // cur->next=head->next;
            // head->next=cur;
            // return;
        // }
        // int mid=0;
        // if(len%2){
            // mid = (len+1)/2;
        // }else{
            // mid = len/2;
        // }
        // ListNode* midNode=head;
        // for(int i=0; i<mid-1;i++)
            // midNode=midNode->next;


        // ListNode* back = midNode->next;
        // midNode->next=NULL;
        // ListNode* node1=back;
        // ListNode* node2=back->next;
       // printLinkedList(head);
       // printLinkedList(back);
        // for(int i =0; i<len-mid-1;i++){
            // node1->next=node2->next;
            // node2->next=back;
            // back=node2;
            // node2=node1->next;
        // }
       // printLinkedList(head);
       // printLinkedList(cur);
        // ListNode* h=head;
        // for(int i=0;i<len-mid;i++){
            // ListNode* h2=h->next;
            // ListNode* c2=cur->next;
            // h->next=cur;
            // cur->next=h2;
            // h=h2;
            // cur=c2;
        // }
        // return ;
    // }
// };


class Solution {
public:
    void reorderList(ListNode* head) {
		if(head==NULL || head->next==NULL || head->next->next==NULL) return;
		
		ListNode* slow=head;
		ListNode* fast=head;
		while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
		
		stack<ListNode*> stack1;
		ListNode* half = slow->next;
		while(half!=NULL){
			stack1.push(half);
			half=half->next;
		}
		slow->next=NULL;
		ListNode* cur =head;
		while(cur!=NULL && !stack1.empty()){
			ListNode* next = cur->next;
			cur->next = stack1.top();
            stack1.pop();
			cur->next->next=next;
			cur=next;
		}
	}
};
