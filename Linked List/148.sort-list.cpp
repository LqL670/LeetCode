/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (32.69%)
 * Total Accepted:    158.5K
 * Total Submissions: 485K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
 
//单链表递归实现 自顶向下
// class Solution {
// public:
    // ListNode* sortList(ListNode* head) {
        // if(head==NULL || head->next==NULL) return head;

        // ListNode *pFast,*pSlow;
        // pFast=head;
        // pSlow=head;
        // while(pFast->next!=NULL && pFast->next->next!=NULL){
            // pFast = pFast->next->next;
            // pSlow = pSlow->next;
        // }
        // pFast=pSlow;
        // pSlow=pSlow->next;
        // pFast->next=NULL;

        // ListNode* pFront = sortList(head);
        // ListNode* pBack = sortList(pSlow);
        // return merge(pFront, pBack);
    // }

    // ListNode* merge(ListNode* head1, ListNode* head2){
        // if(head1==NULL) return head2;
        // if(head2==NULL) return head1;

        // ListNode* res=NULL;
        // if(head1->val < head2->val){
            // res = head1;
            // head1 =head1->next;
        // }else{
            // res = head2;
            // head2=head2->next;
        // }
        // ListNode* p = res;
        // while(head1!=NULL && head2!=NULL){
            // if(head1->val > head2->val){
                // res->next = head2;
                // head2 = head2->next;
            // }else{
                // res->next = head1;
                // head1=head1->next;
            // }
            // res=res->next;
        // }
        // if(head1) res->next = head1;
        // else if(head2) res->next = head2;

        // return p;
    // }
// };


// class Solution {
// public:
    // ListNode* sortList(ListNode* head) {
		
	// }
// };

class Solution {
public:
	ListNode* split(ListNode* head,int size){
		for(int i =1; i<size;i++){
			if(head!=NULL) head = head->next;
		}
		if(head==NULL) return NULL;
		ListNode* p = head->next;
		head->next = NULL;
		return p;
	}
	ListNode* merge(ListNode* head1,ListNode* head2,ListNode* tail){
		while(head1 && head2){
			if(head1->val < head2->val){
				tail->next =head1;
				head1 = head1->next;
			}else{
				tail->next=head2;
				head2 = head2->next;
			}
			tail=tail->next;
		}
		tail->next = head1==NULL ? head2:head1;
		while(tail->next)
			tail=tail->next;

		return tail;
	}

    ListNode* sortList(ListNode* head) {
		if(head==NULL || head->next ==NULL) return head;

		int len =0;
		ListNode* cur = head;
		while(cur){
			cur=cur->next;
			len++;
		}
		ListNode* pTemp = new ListNode(0);
		ListNode* tail = pTemp;
		ListNode *front,*back;
		pTemp ->next=head;
		for(int size=1; size<len;size<<=1){
			cur = pTemp->next;
			tail = pTemp;
			while(cur){
				front = cur;
				back = split(cur,size);
				cur = split(back,size);
				tail=merge(front,back,tail);
			}
		}

		ListNode* res = pTemp->next;
		delete pTemp;
		return res;
	}
};



