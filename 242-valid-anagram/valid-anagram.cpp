class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> m;
        for(auto it : s) m[it]++;
        for(auto it : t) {
            if(m[it] > 0) m[it]--;
            else return false;
        }
        return true;
    }
};