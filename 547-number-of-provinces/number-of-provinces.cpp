class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, int node, vector<int>& vis) {
        vis[node] = 1;
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] && !vis[i]) dfs(isConnected, i, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        int count = 0;
        for(int i = 0; i < vis.size(); i++) {
            if(!vis[i]) {
                count++;
                dfs(isConnected, i, vis);
            }
        }
        return count;
    }
};