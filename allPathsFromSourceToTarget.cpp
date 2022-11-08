class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> curPath = {0};
        dfs(graph, 0, curPath, res);
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int cur, vector<int>& curPath, vector<vector<int>>& res) {
        if(cur == graph.size() - 1) {
            res.push_back(curPath);
        }
        
        for(auto next : graph[cur]) {
            curPath.push_back(next);
            dfs(graph, next, curPath, res);
            curPath.pop_back();
        }
    }
};