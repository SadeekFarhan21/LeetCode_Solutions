#include <math.h>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        double log = log10(n) / log10(2);
        return (int) log == log;
    }
};