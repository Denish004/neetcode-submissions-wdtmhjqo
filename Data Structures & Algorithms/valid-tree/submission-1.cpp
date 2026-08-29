class Solution {
public:
    bool DFS(int node, int parent, vector<vector<int>>&adjList, unordered_set<int>& visit){

        visit.insert(node);
        for(auto adjNode : adjList[node]){
           if(adjNode == parent){
            continue;
           }

           if(visit.count(adjNode)){
            return false;
           }

           if(!DFS(adjNode, node, adjList, visit)){
            return false;
           }
           
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adjList(n);
        unordered_set<int> visit;

        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        

        if(!DFS(0, -1, adjList, visit)){
            return false;
        }

        return visit.size()==n;


    }
};
