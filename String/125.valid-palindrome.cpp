/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (29.22%)
 * Total Accepted:    290.3K
 * Total Submissions: 993.3K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            if(!isalnum(s[left]))
                ++left;
            else if(!isalnum(s[right]))
                --right;
            else if((s[left] - 'a' + 32)%32 != (s[right] - 'a' + 32)%32)
                return false;
            else{
                ++ left;
                -- right;
            }

        }
        return  true;
    }
};
