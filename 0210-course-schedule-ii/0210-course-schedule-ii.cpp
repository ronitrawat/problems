class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            for(int &x: adj[i]){
                indegree[x]+=1;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;

        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int x: adj[f]){
                indegree[x]-=1;
                if(indegree[x]==0){
                    q.push(x);
                }
            }

        }
       if(ans.size()==numCourses){
        return ans;
       }
       return {};


    }
};