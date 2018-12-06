/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (43.37%)
 * Total Accepted:    196.2K
 * Total Submissions: 452.4K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */
class Solution {
public:
    bool isHappy(int n) {
       unordered_set<int> visit;
       while(n != 1){
           if(visit.find(n) != visit.end())
               return false;
           visit.insert(n);

           int sum = 0;
           while(n){
               sum += (n%10) * (n%10);
               n/=10;
           }
           n = sum;
       }
       return true;
    }
};
