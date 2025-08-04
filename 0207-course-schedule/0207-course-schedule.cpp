class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector <int> in_degrees(n, 0);
        vector <vector<int>> adj_list(n);
        for(auto &p: prerequisites){
            int to = p[0], from = p[1]; 
            adj_list[from].push_back(to);
            in_degrees[to]++;
        }

        queue <int> q; // to keep track of the nodes with no in-degrees
        for(int i = 0; i < n; i++){
            if(in_degrees[i] == 0){
                q.push(i);
            }
        }
        vector <int> answer;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            answer.push_back(node);
            for(int neighbor: adj_list[node]){
                in_degrees[neighbor]--;
                if(in_degrees[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return answer.size() == n;
    }
};