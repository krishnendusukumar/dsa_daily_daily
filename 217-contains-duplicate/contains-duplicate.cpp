class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (auto it : nums) {
            if(m[it] > 0) return true;
            m[it]++;
        }
        return false;
    }
};