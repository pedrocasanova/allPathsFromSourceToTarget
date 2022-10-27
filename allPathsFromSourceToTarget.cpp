class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> connected;
        int i = 0, lastNode = 3;
        connected = graph[0];
        // visit each node connected to 0
        for (int i = 0; i < connected.size(); i++)
        {
            paths.push_back({0});
            for(int j = 0; j < graph[i].size(); j++)
            {
                // paths[i].push_back(graph[j][i]);
                cout << graph[i][j] << " , ";
                
            } 
            cout << endl;
        }
        return paths;
    }
};