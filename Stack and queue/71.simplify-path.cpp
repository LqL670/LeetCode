/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (27.51%)
 * Total Accepted:    132.8K
 * Total Submissions: 482.7K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. 
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * path = "/a/../../b/../c//.//", => "/c"
 * path = "/a//b////c/d//././/..", => "/a/b/c"
 * 
 * In a UNIX-style file system, a period ('.') refers to the current directory,
 * so it can be ignored in a simplified path. Additionally, a double period
 * ("..") moves up a directory, so it cancels out whatever the last directory
 * was. For more information, look here:
 * https://en.wikipedia.org/wiki/Path_(computing)#Unix_style
 * 
 * Corner Cases:
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    string simplifyPath(string path) {
        string res,tmp;
        vector<string>st;
        stringstream s(path);
        while(getline(s,tmp,'/')){
            if(tmp=="." || tmp=="") continue;
            else if(tmp==".."){
                if(!st.empty()) st.pop_back();
            }else{
                st.push_back(tmp);
            }
        }
        for(auto& i:st){
            res +="/"+i;
        }
        return res.empty()?"/":res;
    }
};
