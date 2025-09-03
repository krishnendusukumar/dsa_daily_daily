class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [] (auto& a, auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> vis(1001, -1);
        int count = 0;
        int n = points.size();
        for(int i = 0; i < n-1; i++) {
            int prev = INT_MAX;
            for(int j = i+1; j < n; j++) {
               bool flag = true;
               int c1 = points[i][1];
               int c2 = points[j][1];
               if(c2 > c1) continue;
               else {
                if(prev == INT_MAX || prev < c2) {
                    // cout<<c1<<" "<<c2<<" "<<prev<<endl;
                    count++;
                    prev = c2;
                }
               }
            }
        }
        return count;
    }
};


// 2 6
// 4 4
// 6 2