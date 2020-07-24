// Time complexity :- O(n + e)
// Space complexity :- O(n)
class Solution {
public:
    void dfs(vector<vector<int>>& graph, int u, vector<int>curr, vector<vector<int> >&ans)
    {
        curr.push_back(u);
        
        if(u == graph.size()-1)
        {
            ans.push_back(vector<int>(curr.begin(), curr.end()));
            return;
        }
        for(auto child: graph[u])
        {
            dfs(graph, child, curr, ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int> >ans;
        int n = graph.size()-1;
        vector<int>curr;
        dfs(graph,0,curr,ans);
        
        return ans;
    }
};