class Solution {
public:
    int bestdiff;
    vector<int> bestPath;

    void recurse(int n, vector<int>& divisors, vector<int>& path, int k, int j) {
        if (k == 1) {
            if (n < divisors[j]) return;  // enforce non-decreasing
            path.push_back(n);

            int mini = INT_MAX, maxi = INT_MIN;
            for (int it : path) {
                mini = min(mini, it);
                maxi = max(maxi, it);
            }

            if (bestdiff > maxi - mini) {
                bestdiff = maxi - mini;
                bestPath = path;
            }

            path.pop_back(); // ✅ always pop
            return;          // ✅ stop recursion
        }

        for (int i = j; i < (int)divisors.size(); i++) {
            if (n % divisors[i] == 0) {
                path.push_back(divisors[i]);
                recurse(n / divisors[i], divisors, path, k - 1, i);
                path.pop_back();
            }
        }
    }

    void store_divisor(int n, vector<int>& divisors) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) divisors.push_back(n / i);
            }
        }
        sort(divisors.begin(), divisors.end()); // ✅ sort for order
    }

    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        vector<int> path;
        store_divisor(n, divisors);

        bestdiff = INT_MAX; // ✅ reset
        bestPath.clear();   // ✅ reset

        recurse(n, divisors, path, k, 0);
        return bestPath;
    }
};
