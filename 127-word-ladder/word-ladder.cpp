class Solution {
public:
bool helper(string a, string b) {
    int itr = 0;
    int diff = 0;
    while(itr < a.size()) {
        if(a[itr] == b[itr]) itr++;
        else {
            diff++;
            itr++;
        }
    }
    return diff == 1;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count = 0;
        int diff = 0;
        string src;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_map<string, int> memo;
        src = beginWord;
        unordered_map<string, vector<string>> adj;
        for(int i = 0 ; i < wordList.size(); i++) {
            memo[wordList[i]] = INT_MAX;
            for(int j = i+1; j < wordList.size(); j++) {
                string a = wordList[i];
                string b = wordList[j];

                if(helper(a, b)) {
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        queue<string> q;
        q.push(src);
        memo[src] = 0;

        while(!q.empty()) {
            string node = q.front();
            q.pop();
            if(endWord == node) return (memo[node] + 1);
            for(auto it : adj[node]) {
                if(memo[it] > memo[node] + 1) {
                memo[it] = min(memo[it], 1+memo[node]);
                q.push(it);
                }
            }
        }
        return 0;
    }
};