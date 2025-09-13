class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int>m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i] - 'a']++;
        }
        int ans = 0, count = 0;
        for(auto it : m) {
            auto first = it.first + 'a';
            if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') ans = max(ans, it.second);
            else count = max(count, it.second);
        }
        return ans + count;
    }
};