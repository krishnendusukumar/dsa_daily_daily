class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> ans;
        if(n %2 == 1) ans.push_back(0);
        int iter = n/2;
        for(int i = iter; i > 0; i--) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};