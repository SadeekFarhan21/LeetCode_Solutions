
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        priority_queue<long long> max_heap;
        long long n = happiness.size();
        for(long long i = 0; i < n; i++){
            min_heap.push(happiness[i]); // O (nlogn)
        }

        for(long long i = 1; i <= n - k; i++){
            min_heap.pop();
        }
        while(!min_heap.empty()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        long long total = 0;
        for(long long i = 0; i < k; i++){
            long long element = max_heap.top();
            element -= i;
            max_heap.pop();
            if(element > 0){
                total += element;
            } 
        }
        return total;
    }
};