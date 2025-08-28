class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({passingFees[0], 0, 0});
        unordered_map<int,int> memo;
        for(int i = 0; i < n; i++) memo[i] = INT_MAX;

        while(!pq.empty()) {
            auto [cost, time, node] = pq.top(); pq.pop();

            if(node == n-1) {
                return cost;
            }
            for(auto [u, w] : adj[node]) {
                int newTime = time + w;

                if(maxTime >= newTime && memo[u] > newTime) {
                    memo[u] = newTime;
                    pq.push({cost+passingFees[u], newTime, u});
                }
            }
        }
        return -1;
    }
};