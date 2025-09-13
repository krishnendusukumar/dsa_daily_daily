class Solution {
public:
    int maxFreqSum(string s) {
        map<int,int>m;
        int ans = 0, count = 0;
        for(int i = 0; i < s.size(); i++) {
            auto first = s[i];
            auto second = ++m[s[i] - 'a'];
            if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') ans = max(ans, second);
            else count = max(count, second);
        }
        return ans + count;
    }
};