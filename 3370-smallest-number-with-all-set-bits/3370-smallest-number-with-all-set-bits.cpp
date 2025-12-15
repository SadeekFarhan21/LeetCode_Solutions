class Solution {
public:
    int smallestNumber(int n) {

        double log = log2(n); // which power of 2 is the closest
        int answer = 0;
        if(log == (int) log){
            answer = n + (n * 2 - 1) / 2;
            
        }
        else {
            // find the next power
            log = (int) log + 1;
            answer = pow(2, log) - 1;
            cout << log << "\n";
            cout << "alternate\n";
        }
        return answer;
    }
};