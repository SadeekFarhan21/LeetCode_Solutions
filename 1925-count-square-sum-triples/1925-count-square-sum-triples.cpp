class Solution {
public:
    bool isSquare(int n){
        return (int) sqrt(n) * (int) sqrt(n) == n;
    }
    int countTriples(int n) {
        int count = 0;
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                int sum = a * a + b * b;
                if(isSquare(sum) && (int) sqrt(sum) <= n){
                    cout << a << " " << b << " " << (int) sqrt(sum) << "\n";
                    count += 1;
                }
            }
        } 
        return count;
    }
};