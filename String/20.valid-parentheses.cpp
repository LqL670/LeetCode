/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.08%)
 * Total Accepted:    452K
 * Total Submissions: 1.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;

        for(int i = 0; i< s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stack.push(s[i]);
            else{
                if(stack.size()==0)
                    return false;

                char c = stack.top();
                stack.pop();

                char match ;
                if(s[i]==')')
                    match = '(';
                else if(s[i]=']')
                    match='[';
                else
                    match='{';

                if(c != match)
                    return false;


            }
        }

        if(stack.size() != 0)
            return false;

        return true;
    }
};
