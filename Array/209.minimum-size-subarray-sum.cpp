/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (33.61%)
 * Total Accepted:    149.5K
 * Total Submissions: 444.9K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = -1;
        int res = nums.size() + 1;

        int sum = 0;
        while(left < nums.size()){
            if(sum < s && right +1 < nums.size()){
                sum += nums[++right];
            }
            else{
                sum -= nums[left++];
            }

            if(sum >= s)
                res = res < right - left + 1 ? res : right-left + 1;
        }

        if(res == nums.size()+1)
            return 0;

        return res;
    }
};
