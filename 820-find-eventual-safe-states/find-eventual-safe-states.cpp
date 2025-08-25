class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> outdegree(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < outdegree.size(); i++) {
            if(outdegree[i] == 0) q.push(i);
        }
        vector<int> safe_node;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe_node.push_back(node);

            for(int i = 0; i < adj[node].size(); i++) {
                int u = adj[node][i];
                --outdegree[u];
                 if(outdegree[u] == 0) q.push(u);
            }
        }
        sort(safe_node.begin(), safe_node.end());
        return safe_node;
        

    }
};