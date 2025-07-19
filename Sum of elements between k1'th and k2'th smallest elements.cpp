#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<long long> p1;
        priority_queue<long long> p2;

        for (long long i = 0; i < K1; i++)
            p1.push(A[i]);

        for (long long i = 0; i < K2 - 1; i++)
            p2.push(A[i]);

        for (long long i = K1; i < N; i++) {
            if (A[i] < p1.top()) {
                p1.pop();
                p1.push(A[i]);
            }
        }

        for (long long i = K2 - 1; i < N; i++) {
            if (A[i] < p2.top()) {
                p2.pop();
                p2.push(A[i]);
            }
        }

        long long sum1 = 0, sum2 = 0;

        while (!p1.empty()) {
            sum1 += p1.top();
            p1.pop();
        }

        while (!p2.empty()) {
            sum2 += p2.top();
            p2.pop();
        }

        return sum2 - sum1;
    }
};

int main() {
    long long arr[] = {1, 3, 12, 5, 15, 11};
    long long N = sizeof(arr) / sizeof(arr[0]);
    long long K1 = 3, K2 = 6;

    Solution sol;
    long long result = sol.sumBetweenTwoKth(arr, N, K1, K2);
    cout << "Sum between " << K1 << "-th and " << K2 << "-th smallest elements is: " << result << endl;

    return 0;
}
