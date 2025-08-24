class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i) {
        if(visited[i] == 1) return true;
        if(visited[i] == -1 || visited[i] == 2) return false;

        visited[i] = 2;
        for(auto it : graph[i]) {
            if(!dfs(graph, visited, it)) {
                visited[i] = -1;
                return false;
            }
        }
        visited[i] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) dfs(graph, visited, i);
        }
        vector<int> safe_array;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 1) safe_array.push_back(i);
        }
        return safe_array;
    }
};