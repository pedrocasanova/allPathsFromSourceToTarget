class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> initialNodesToVisit, nextNodesToVisit, proposedPath;
        int j = 0, lastNode = graph.size() - 1;
        initialNodesToVisit = graph[0];
        // visit each node connected to 0
        for (int i = 0; i < initialNodesToVisit.size(); i++)
        {
            proposedPath.emplace(proposedPath.begin(), 0);
            if(initialNodesToVisit[i] == lastNode)
            {
                proposedPath.emplace_back(initialNodesToVisit[i]);
                paths.emplace_back(proposedPath);
                proposedPath.clear();
            }
            else
            {
                nextNodesToVisit = graph[i];
                for(int k = 0; k < nextNodesToVisit.size(); k++) 
                {
                        cout << "next nodes to visit:  " << nextNodesToVisit[k] << endl;
                }
                for (int j = 0; j < nextNodesToVisit.size(); j++)
                {
                    if (nextNodesToVisit[j] == lastNode)
                    {
                        proposedPath.emplace_back(nextNodesToVisit[j]);
                        paths.emplace_back(proposedPath);
                        proposedPath.pop_back();
                    }
                    else if(nextNodesToVisit.empty())
                    {
                        proposedPath.clear();
                        break;
                    }
                    else
                    {
                        proposedPath.emplace_back(nextNodesToVisit[j]);
                        nextNodesToVisit = graph[j];
                    }
                }
            }
        }
        return paths;
    }
};