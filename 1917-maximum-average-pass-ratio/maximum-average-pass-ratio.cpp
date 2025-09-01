class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        using T = tuple<double,int,int>; // (gain, p, t)
        priority_queue<T> pq;

        for (auto &c : classes) {
            int p = c[0], t = c[1];
            double gain = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            pq.push({gain, p, t});
        }

        while (extra--) {
            auto [gain, p, t] = pq.top(); pq.pop();
            p++, t++;
            double new_gain = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            pq.push({new_gain, p, t});
        }

        double total = 0.0;
        while (!pq.empty()) {
            auto [gain, p, t] = pq.top(); pq.pop();
            total += (double)p / t;
        }
        return total / classes.size();
    }
};
