class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        vector<vector<int>> store(51);
        for (auto &it : points) {
            int x = it[0];
            int y = it[1];
            store[x].push_back(y);
        }
        
        int count = 0;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                auto p1 = points[i];
                auto p2 = points[j];
                int r1 = p1[0], c1 = p1[1], r2 = p2[0], c2 = p2[1];
                
                if (i == j) continue;
                
                if (r1 <= r2 && c1 >= c2) {
                    bool flag = true;
                    for (int k = r1; k <= r2 && flag; k++) {
                        for (int val : store[k]) {
                                if((k == r1 && val == c1) || (k == r2 && val == c2)) continue;
                            if ((val >= c2 && val <= c1)) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
