class Solution {
public:

void findMinSteps(string start, string end, vector<string>& list, unordered_map<string, int>& memo){
        unordered_set<string> st(list.begin(), list.end());

        queue<string> q;
        q.push(start);
        memo[start] = 1;
        while(!q.empty()){
            auto node = q.front(); q.pop();

            if(node == end) return;

            for(int i = 0; i < node.size(); i++) {
            auto nextword = node;
                for(auto j = 'a'; j <= 'z'; j++) {
                    nextword[i] = j;
                    if(memo.count(nextword)) {
                        if(memo[nextword] > 1+memo[node]) {
                            memo[nextword] = 1+memo[node];
                            q.push(nextword);
                        }
                    }
                }
            }
        }
    return;
}

void recurse(vector<string>& ans, vector<string>& list, string start, string end, unordered_map<string, int>& memo, vector<vector<string>>& result){ 
    if(start == end) {
        auto it = ans;
        reverse(it.begin(), it.end());
        result.push_back(it);
        return;
    }
    
    
        string original = start;
    for(int i = 0; i < start.size(); i++) {
        string next = original;
        for(auto j = 'a'; j <= 'z'; j++) {
            next[i] = j;
            if(memo.count(next)) {
                if(memo[next] == memo[original] - 1) {
                    ans.push_back(next);
                    recurse(ans, list, next, end, memo, result);
                    ans.pop_back();
                }
            }
        }
    }
}

    vector<vector<string>> findLadders(string start, string end, vector<string>& list) {
        unordered_map<string, int> memo;
        for(auto it : list) memo[it]= INT_MAX;
        if(find(list.begin(), list.end(), start) == list.end()) list.push_back(start);
        if(find(list.begin(), list.end(), end) == list.end()) return {};

        findMinSteps(start, end, list, memo);
        if(memo[end] == INT_MAX) return {};
        vector<string> ans;
        ans.push_back(end);
        vector<vector<string>> result;
        recurse(ans, list, end, start, memo, result);
        return result;
    }
};