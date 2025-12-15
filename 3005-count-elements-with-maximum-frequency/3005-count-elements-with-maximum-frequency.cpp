class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_frequency = 0;
        map <int, int> m;
        for(int c : nums){
            m[c]++;
            if(m[c] > max_frequency){
                max_frequency = m[c];
            }
        }
        int count = 0;
        for(auto x : m){
            // cout << x.first << " " << x.second << "\n";
            if(x.second == max_frequency){
                count += x.second;
            }
        }
        // cout << max_frequency << "\n";
        return count;
    }
};