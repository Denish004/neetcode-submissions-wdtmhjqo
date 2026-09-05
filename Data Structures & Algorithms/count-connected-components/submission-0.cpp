class Solution {
public:
    void DFS(int node , vector<vector<int>>&adjList, vector<int>& visited){

        visited[node]=1;

        for(auto adjNode: adjList[node]){
            if(visited[adjNode]==0){
                DFS(adjNode, adjList, visited);
            }
          
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>>adjList(n);

        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        int count = 0;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                  DFS(i, adjList, visited);
                  count++;
            }
          
        }
        return count;
    }
};
