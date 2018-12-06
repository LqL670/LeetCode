/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.47%)
 * Total Accepted:    426.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>numSet(3);
        vector<vector<int> > res;

        if(nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i< nums.size() - 2; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int sum = 0 - nums[i];
            for(int j = i+1, k = nums.size()-1;j<k;){
                if(nums[j] + nums[k] == sum){
                    numSet[0] = nums[i];
                    numSet[1] = nums[j++];
                    numSet[2] = nums[k--];
                    res.push_back(numSet);
                    while(j<k && nums[j] == nums[j-1])
                        j++;
                    while(k>j && nums[k] == nums[k+1])
                        k--;
                }else if(nums[j] + nums[k] < sum)
                    j++;
                else
                    k--;
            }
        }
        return  res;
    }
};
