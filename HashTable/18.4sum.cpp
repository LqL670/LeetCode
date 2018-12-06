/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.81%)
 * Total Accepted:    193K
 * Total Submissions: 669.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len<4)
            return res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i< len -3; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;

            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if(nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target)
                continue;
            for(int j = i+1; j < len -2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;
                if(nums[i] + nums[j] + nums[len -2] + nums[len-1] < target)
                    continue;
                int begin = j+1,end = len -1;
                while(begin < end){
                    int sum = nums[i] + nums[j] + nums[begin] + nums[end];
                    if(sum == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[begin++]);
                        tmp.push_back(nums[end--]);
                        res.push_back(tmp);
                        while(begin < end && nums[begin] == nums[begin-1])
                            ++begin;
                        while(end > begin && nums[end] == nums[end+1])
                            --end;
                    }
                    else if(sum < target)
                        ++begin;
                    else
                        --end;
                }
            }
        }

        return res;
    }
};
