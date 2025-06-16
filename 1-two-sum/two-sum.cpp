class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        map<int, int>n;
        for(int i = 0; i < nums.size() ; i++) {
            m[nums[i]] = i;
            n[nums[i]]++;
        }
        for(auto i = 0 ; i < nums.size(); i++) {
            int element = nums[i];
            int new_target = target - element;
            n[nums[i]]--;
            if(n[new_target] && m[new_target]) {
                return {i, m[new_target]};
            }
        }
        return {1,2};
    }
};