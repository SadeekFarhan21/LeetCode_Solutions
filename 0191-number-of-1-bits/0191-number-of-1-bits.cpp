class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b(n);
        string s = b.to_string();
        int count = 0;
        for(auto c : s){
            if(c == '1') count += 1;
        }
        return count;
    }
};