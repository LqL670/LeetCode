/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (35.16%)
 * Total Accepted:    92.6K
 * Total Submissions: 263.2K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = 0, r = -1; 
        vector<int>res;

        int freq[256] = {0};
        for(int i = 0; i< p.size(); i++)
            freq[p[i]] ++;

        int one[256] = {0};
        while(l < s.size()){
            if(r+1 < s.size() && freq[s[r+1]] != 0 && one[s[r+1]] <= freq[s[r+1]] -1){
                one[s[++r]] ++;
            }
            else{
                one[s[l++]] --;
            }
            if(r < l)
                r = l -1;

            if(r-l+1 == p.size())
                res.push_back(l);
        }
        return res;
    }
};
