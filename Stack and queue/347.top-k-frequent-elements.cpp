/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (51.95%)
 * Total Accepted:    154.6K
 * Total Submissions: 297.2K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        assert(k > 0);
        unordered_map<int,int> freq;
        int nLen = nums.size();
        for(int i=0; i<nLen;i++)
            freq[nums[i]] ++;
        assert(k <= freq.size());
        // pair<频率，元素>
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
        //priority_queue<pair<int,int>> pq;
        for(unordered_map<int,int>::iterator iter=freq.begin();iter != freq.end();iter++){
            if(k==pq.size()){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
            }else
                pq.push(make_pair(iter->second,iter->first));
        }
        vector<int> res;
        while(! pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
