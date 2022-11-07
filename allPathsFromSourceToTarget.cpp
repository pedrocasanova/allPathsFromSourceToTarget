class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> visited, stack;
        int lastNode = graph.size()-1;
        bool visitedFlag = false, inStackFlag = false;
        visited.emplace_back(0);
        stack = graph[0];
        while(!stack.empty())
        {
            // loop for connected nodes of this node
            for(int i = 0; i < graph[stack[0]].size(); i++)
            {
                for(int j = 0; j < visited.size();j++)
                {
                    if (graph[stack[0]][i] == visited[j]) visitedFlag = true;
                }
                for(int k = 0; k < stack.size();k++)
                {
                    if (graph[stack[0]][i] == stack[k]) inStackFlag = false;
                }
                // if not visited and not in the stack already, add
                if(!visitedFlag && !inStackFlag)
                {
                    stack.emplace(stack.begin(), graph[stack[0]][i]);
                }
                // else if the node is lastNode emplace into paths
                else if(graph[stack[0]][i] == lastNode) 
                {
                    paths.emplace_back(visited);    
                }   
                visitedFlag = false;
                inStackFlag = false;
            }
            visited.emplace_back(stack[0]);
            stack.erase(stack.begin());
            cout << " visited ";
            for (int l = 0; l < visited.size(); l++) cout << visited[l] << " ";
            cout << endl;
            cout << " stack ";
            for (int l = 0; l < stack.size(); l++) cout << stack[l] << " ";
            cout << endl;
        }
        return paths;
    }
};