class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, -1);
        vector<int> R(n, n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(s.size() && nums[s.top()] < nums[i]) s.pop();
            if(!s.empty()) L[i] = s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1; i>= 0; i--) {
            while(s.size() && nums[s.top()] < nums[i]) s.pop();
            if(!s.empty()) R[i] = s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i = 0 ; i < n; i++) {
            if(R[i] != n && (R[i] - i) >= 2) ans++;
            if(L[i] != -1 && (i - L[i]) >= 2) ans++;
        }
        return ans;
    }
};