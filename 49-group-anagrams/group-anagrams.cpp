class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> v;
        for(auto it : strs) {
            string s = it;
            sort(it.begin(), it.end());
            v[it].push_back(s);
        }
        vector<vector<string>>ans;
        for (auto it : v) {
            ans.push_back(it.second);
        }
        return ans;
    }
};