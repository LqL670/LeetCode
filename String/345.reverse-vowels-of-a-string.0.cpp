/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.24%)
 * Total Accepted:    132K
 * Total Submissions: 328K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            while(!checkVowels(s[left]) && left < right)
                left++;
            while(!checkVowels(s[right]) && left < right)
                right--;
            swap(s[left++],s[right--]);
        }
        return s;
    }

    bool checkVowels(const char c){
        bool isVowel = false;
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                isVowel = true;
                break;
            default:
                break;
        }
        return isVowel;
    }
};
