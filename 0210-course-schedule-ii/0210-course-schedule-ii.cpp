class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector <int> in_degrees(n, 0);
        vector<vector<int>> adj_list(n);
        vector <int> answer;
        queue <int> q;
        
        // Process the prerequisite into an adjacency list
        // Create the in_degree list
        for(auto &p: prerequisites){
            int from = p[1], to = p[0];
            adj_list[from].push_back(to);
            in_degrees[to]++;
        }

        // Find the nodes to put in the queue to get staretd with
        for(int i = 0; i < n; i++){
            if(in_degrees[i] == 0){
                q.push(i);
            }
        }

        // Main topological sorting
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
        if(answer.size() == n){
            return answer;
        }
        return {};
    }
};