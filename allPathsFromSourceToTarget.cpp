class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> initialNodesToVisit, nextNodesToVisit, proposedPath;
        int j = 0, lastNode = graph.size() - 1;
        initialNodesToVisit = graph[0];
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
                nextNodesToVisit = graph[initialNodesToVisit[i]];
                proposedPath.emplace_back(initialNodesToVisit[i]);
                while(!nextNodesToVisit.empty())
                {
                    if (nextNodesToVisit[j] == lastNode)
                    {
                        proposedPath.emplace_back(nextNodesToVisit[j]);
                        paths.emplace_back(proposedPath);
                        proposedPath.pop_back();
                        nextNodesToVisit.erase(nextNodesToVisit.begin()+j);
                    }
                    else
                    {
                        proposedPath.emplace_back(nextNodesToVisit[j]);
                        nextNodesToVisit = graph[nextNodesToVisit[j]];
                    }
                }
                proposedPath.clear();
                // missing case where the same initial node must be revisited (add visited vector?)
            }
        }
        return paths;
    }
};