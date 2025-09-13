class Solution {
public:
    int maxFreqSum(string s) {
        map<int,int>m;
        int ans = 0, count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ans = max(ans, ++m[s[i] - 'a']);
            else count = max(count, ++m[s[i] - 'a']);
        }
        return ans + count;
    }
};