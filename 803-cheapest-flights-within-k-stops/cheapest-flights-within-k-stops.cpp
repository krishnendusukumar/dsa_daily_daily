class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        if(src == dst) return 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>>pq;
        pq.push({0, src, 0});
        vector<int> memo(n, INT_MAX);
        memo[src] = 0;

        while(!pq.empty()) {
            auto [stops, node, price] = pq.top(); pq.pop();
            if(node == dst) memo[dst] = min(memo[dst], price);
            if(stops > k) continue;
            for(auto [u,w] : adj[node]) {
                if(stops <= k){
                    if(memo[u] > w + price) {
                        memo[u] = w + price;
                        pq.push({stops + 1, u, memo[u]});

                    }
                }
            }
        }
        if(memo[dst] == INT_MAX) return -1;
        return memo[dst];

    }
};