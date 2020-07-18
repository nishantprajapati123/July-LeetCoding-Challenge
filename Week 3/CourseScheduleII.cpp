// Time complexity :- O(N+E)
// Space complexity :- O(N)
class Solution {
public:
    bool dfs(int u, vector<int>graph[], vector<bool>&vis, vector<bool>&inProcess, vector<int>&order)
    {
        vis[u] = true;
        inProcess[u] = true;
        
        for(auto child: graph[u])
        {
            if(!vis[child] && !dfs(child, graph, vis, inProcess, order))
                return false;
            if(inProcess[child])
                return false;
        }
        
        inProcess[u] = false;
        order.push_back(u);
        return true;
    }
    bool findOrderHelper(vector<int>graph[], vector<bool>&vis, vector<bool>&inProcess, vector<int>&order)
    {
        int n = vis.size();
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && !dfs(i, graph, vis, inProcess, order))
                return false;
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>graph[numCourses];
        
        for(auto course: prerequisites)
            graph[course[1]].push_back(course[0]);
        
        vector<bool>vis(numCourses, false);
        vector<bool>inProcess(numCourses, false);
        vector<int>order;
        
        if(findOrderHelper(graph, vis, inProcess, order))
        {
            reverse(order.begin(), order.end());
            return order;
        }
        return {};
    }
};