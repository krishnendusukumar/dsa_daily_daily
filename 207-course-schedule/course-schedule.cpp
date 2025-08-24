class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        queue<int> q;
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0 ; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};