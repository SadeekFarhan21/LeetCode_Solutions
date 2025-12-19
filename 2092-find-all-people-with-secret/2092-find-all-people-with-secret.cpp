class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first_person) {
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[first_person] = true;

        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        int i = 0;
        while (i < meetings.size()) {
            int current_time = meetings[i][2];
            unordered_set<int> people_at_this_time;
            unordered_map<int, vector<int>> adj;
            
            while (i < meetings.size() && meetings[i][2] == current_time) {
                int u = meetings[i][0], v = meetings[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                people_at_this_time.insert(u);
                people_at_this_time.insert(v);
                i++;
            }

            queue<int> q;
            for (int p : people_at_this_time) {
                if (knows[p]) {
                    q.push(p);
                }
            }

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (!knows[neighbor]) {
                        knows[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knows[i]){
                result.push_back(i);
            }
        }
        return result;

    }
};