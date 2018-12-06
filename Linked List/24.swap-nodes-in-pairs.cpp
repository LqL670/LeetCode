/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (41.76%)
 * Total Accepted:    257K
 * Total Submissions: 615.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Note:
 * 
 * 
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;

        ListNode* p = dummyNode;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 =  node1->next;
            ListNode* next = node2->next;

            node2->next =  node1;
            node1->next =next;
            p->next = node2;

            p = node1;
        }

        ListNode* res = dummyNode->next;
        delete dummyNode;
        return res;

    }
};
