/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (31.50%)
 * Total Accepted:    304.8K
 * Total Submissions: 965.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,deque<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> min_heap;
        for(ListNode* l:lists)
            if(l)
                min_heap.push(make_pair(l->val,l));
        ListNode* head =new ListNode(0);
        ListNode* cur = head;
        while(!min_heap.empty()){
            cur->next = min_heap.top().second;
            cur=cur->next;
            min_heap.pop();
            if(cur->next) 
                min_heap.push(make_pair(cur->next->val,cur->next));
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};
