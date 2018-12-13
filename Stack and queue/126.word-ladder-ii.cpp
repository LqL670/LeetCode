/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (16.23%)
 * Total Accepted:    101.4K
 * Total Submissions: 624.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordDict = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordDict = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordDict, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
// class Solution {
// private:
    // void isConnect(vector<string>&connect,unordered_set<string>& wordDict,const string &current,const string& endWord,unordered_set<string>& visit){
        // connect.clear();
        // string cur = current;
        // int len = cur.size();
        // for(int i =0; i<len;i++){
            // char t = cur[i];
            // for(char c = 'a';c<='z';c++){
                // if(t==c) continue;
                // cur[i]=c;
                // if((cur==endWord || wordDict.find(cur)!=wordDict.end())&&(visit.find(cur)==visit.end())){
                    // connect.push_back(cur);
                // }
            // }
            // cur[i]=t;
        // }
    // }
    // void bfs(map<string,vector<string> > &preNode,unordered_set<string>&wordDict,const string &beginWord,const string &endWord){
        // queue<string> q;
        // unordered_set<string> visit;
        // vector<string> connect;
        // visit.insert(beginWord);
        // q.push(beginWord);
        // while(!q.empty()){
            // int len = q.size();
            // vector<string>tmpList;
            // while(len--){
                // string current = q.front();q.pop();
                // isConnect(connect,wordDict,current,endWord,visit);
                // for(int i = 0; i<connect.size();i++){
                    // if(visit.find(connect[i])==visit.end()){
                        // if(preNode[connect[i]].empty()){
                            // tmpList.push_back(connect[i]);
                            // q.push(connect[i]);
                        // }
                        // preNode[connect[i]].push_back(current);
                    // }
                // }
            // }
            // int tmpLen=tmpList.size();
            // for(int j=0;j<tmpLen;j++) visit.insert(tmpList[j]);
            // if(visit.find(endWord)!=visit.end())
                // return;
        // }
    // }

    // void dfs(const string& beginWord,const string& endWord,vector<string>& tmp,map<string,vector<string> >&preNode,vector<vector<string> >result){
        // if(endWord==beginWord){
            // tmp.push_back(beginWord);
            // vector<string> tmpres(tmp.rbegin(),tmp.rend());
            // result.push_back(tmpres);
            // return;
        // }
        // tmp.push_back(endWord);
        // for(int i=0;i<preNode[endWord].size();i++)
            // dfs(beginWord,preNode[endWord][i],tmp,preNode,result);
    // }
// public:
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordDict) {
        // unordered_set<string> wordDict(wordDict.begin(),wordDict.end());
        // wordDict.insert(endWord);
        // map<string,vector<string> >preNode;

        // bfs(preNode,wordDict,beginWord,endWord);
        // vector<vector<string>>result;
        // vector<string>tmp;
        // dfs(beginWord,endWord,tmp,preNode,result);
        // return result;
    // }
// };


class Solution {
private:
    void isConnected(vector<string>&connect, unordered_set<string>& wordDict, const string &current, const string & end, unordered_set<string>&visit)
    {
        connect.clear();
        string cur = current;
        for (int i = 0; i < cur.size(); i++){
            char t = cur[i];
            for (char c = 'a'; c < 'z'; c++){
                if (c == t) continue;
                cur[i] = c;
                if ((cur == end || wordDict.find(cur) != wordDict.end()) && (visit.find(cur) == visit.end())){
                    connect.push_back(cur);
                }

            }
            cur[i] = t;
        }
    }// isConnect求当前节点相连多所有节点

    //BFS
    void bfs(map<string,vector<string>>&preNode, unordered_set<string>&wordDict, const string &beginWord, const string& endWord){
        queue<string>q;
        unordered_set<string>visit;//是否访问
        visit.insert(beginWord);
        vector<string>connect;
        q.push(beginWord);
        while (!q.empty()){
            int len = q.size();
            vector<string> tmpVisit;
            while (len--){
                string current = q.front();
                q.pop();
                isConnected(connect, wordDict, current, endWord, visit);
                for (int i = 0; i < connect.size(); i++){
                    if (visit.find(connect[i]) == visit.end()){//未被访问
                        if (preNode[connect[i]].empty()){//这个判断语句为了防止图中所说情况
                            tmpVisit.push_back(connect[i]);
                            q.push(connect[i]);
                        }
                        preNode[connect[i]].push_back(current);
                    }
                }
            }//每一层
            for (int j = 0; j < tmpVisit.size(); j++)//每一层结束记录访问节点
                visit.insert(tmpVisit[j]);
            if (visit.find(endWord) != visit.end())
                return;
        }
    }

    //DFS
    void dfs(const string &beginWord, const string &t, vector<string>tmp, map<string,vector<string>>&preNode, vector<vector<string>>&result){
        if (t == beginWord){
            tmp.push_back(beginWord);
            vector<string>tmpres(tmp.rbegin(), tmp.rend());
            result.push_back(tmpres);
            return;
        }
        tmp.push_back(t);
        for (int i = 0; i < preNode[t].size(); i++)
            dfs(beginWord, preNode[t][i], tmp, preNode, result);
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>>result;
		unordered_set<string> wordDict(wordList.begin(),wordList.end());
        if(wordDict.count(endWord)==0) return result;
        map<string, vector<string>>preNode;//记录前驱节点



        bfs(preNode, wordDict, beginWord, endWord);
        //bfs -> 每个节点的前驱节点
        vector<string>tmp;
        dfs(beginWord, endWord, tmp, preNode, result);
        //dfs -> 从后往前搜索出路径
		sort(result.begin(),result.end(),less_f);
        return result;
    }
	
	static bool less_f(const vector<string>& a, const vector<string>& b){
		int len = a.size();
		for(int i =0; i<len;i++){
			if(a[i][0]<b[i][0]) return false;
			else if(a[i][0]>b[i][0]) return true;
			else continue;
		}
		return false;
	}
};
