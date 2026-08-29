class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<int> inDegree(numCourses);

      

        vector<vector<int>> adjList(numCourses);

        for(auto pr : prerequisites){
            inDegree[pr[0]]++;
            adjList[pr[1]].push_back(pr[0]);
        }

        queue<int> q;

        for(int i = 0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        int count = 0;
        vector<int> order;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);
            count++;

            for(auto adjCourse : adjList[course]){
                inDegree[adjCourse]--;
                if(inDegree[adjCourse]==0){
                    q.push(adjCourse);
                }
            }
        }

    
    if(count == numCourses){
        return order;
    }
    return {};
    }
};
