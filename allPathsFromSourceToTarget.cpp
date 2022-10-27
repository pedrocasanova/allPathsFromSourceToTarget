class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> connected;
        int i = 0;
        connected = graph[0];
        while(!connected.empty())
        {
            for(int j = 0; j < graph[connected[i]].size(); j++)
            {
                connected.emplace_back(graph[connected[i]][j]);
            }
            connected.erase(connected.begin());
            i++;
        }
        return paths;
    }
};