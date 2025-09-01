class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        using T = tuple<double,int, int>;
        priority_queue<T> pq;
        for(auto it : classes) {
            int p = it[0];
            int t = it[1];
            double passpercent = (double)((double)(p+1)/(t+1) - (double)p/t);
            pq.push({passpercent, p, t});
        }
        while(extra--) {
            auto [ a, p, t] = pq.top(); pq.pop();
            int new_t = t + 1;
            int new_p = p + 1;
            double percent = (double)((double)(new_p + 1 )/(new_t+1) - (double)new_p/new_t);
            pq.push({percent,  new_p, new_t});
        }
        double total_percent = 0.0;
        while(pq.size() > 0) {
            auto [per, p, t] = pq.top(); pq.pop();
            total_percent += (double)p/t;
        }
        double ans = (double)total_percent/classes.size();
        return ans;
    }
};