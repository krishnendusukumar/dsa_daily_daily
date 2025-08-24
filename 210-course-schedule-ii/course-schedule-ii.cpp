class Solution {
public:


    bool dfs(int i, vector<int>& visited, vector<vector<int>>& adj, stack<int>& st) {
        if(visited[i] == 2) return false;
        if(visited[i] == 1) return true;
        
        visited[i] = 2;
        for(auto it : adj[i]) {
            if(!dfs(it, visited, adj, st)) return false;
        }
        visited[i] = 1;
        st.push(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        stack<int> st;
        
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) if(dfs(i, visited, adj, st) == false) return {};
        }

        vector<int> vec;
        while(st.size()) {
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};