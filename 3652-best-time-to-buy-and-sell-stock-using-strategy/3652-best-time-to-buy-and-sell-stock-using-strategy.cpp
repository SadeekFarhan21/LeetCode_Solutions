class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int m = k / 2;

        // base profit (without any modification)
        long long base = 0;
        for (int i = 0; i < n; i++) {
            base += 1LL * strategy[i] * prices[i];
        }

        // helper arrays
        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = -1LL * strategy[i] * prices[i];
            B[i] = (1LL - strategy[i]) * prices[i];
        }

        // initial sums for the first window [0, k-1]
        long long sumA = 0, sumB = 0;
        for (int i = 0; i < m; i++) sumA += A[i];
        for (int i = m; i < k; i++) sumB += B[i];
        long long bestDelta = sumA + sumB;

        // slide the window
        for (int i = 0; i + k < n; i++) {
            sumA -= A[i];           // remove leftmost from A
            sumA += A[i + m];       // add new entry to A
            sumB -= B[i + m];       // remove first element of B segment
            sumB += B[i + k];       // add new element to B segment
            bestDelta = max(bestDelta, sumA + sumB);
        }

        return base + max(0LL, bestDelta);
    }
};
