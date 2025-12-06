class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long long num = n;
        string s = to_string(n);
        string string_num = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0'){
                string_num.push_back(s[i]);
            }
        }
        n = stoi(string_num);
        long long sum = 0;
        while(num != 0){
            sum += num % 10;
            num /= 10;
        }
        return n * sum;
    }
};