class Solution {
public:
    vector<int> ans;
    bool dfs(vector<int> &inPath, vector<int> &visited, unordered_map<int, vector<int>> &adj, int node){
        inPath[node]=true;
        visited[node]=true;

        for(auto& neigh: adj[node]){
            if(inPath[neigh]){
                return false;
            }

            if(!visited[neigh]){
                if(!dfs(inPath, visited, adj, neigh)) return false;
            }
        }
        ans.push_back(node);
        inPath[node]=false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0]; 

            adj[u].push_back(v);
        }

        vector<int> visited(numCourses, false);
        vector<int> inPath(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(!dfs(inPath, visited, adj, i)){
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
