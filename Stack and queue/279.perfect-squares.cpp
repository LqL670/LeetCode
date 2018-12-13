/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (39.40%)
 * Total Accepted:    145.4K
 * Total Submissions: 368.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
        assert(n>0);

        queue<pair<int,int> > q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1,false);
        visited[n]=true;
        while(!q.empty()){
            int num=q.front().first;
            int distance = q.front().second;q.pop();

            //if(num==0) return distance;

            for(int i = 1;;i++){
                int a = num-i*i;
                if(a<0) break;
                if(a==0) return distance+1;
                if(!visited[a]){
                    q.push(make_pair(a,distance+1));
                    visited[a] = true;
                }
            }
        }
    }
};
