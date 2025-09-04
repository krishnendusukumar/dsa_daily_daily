class Solution {
public:
int bestdiff = INT_MAX;
vector<int> bestPath;


void recurse(int n, vector<int>& divisors, vector<int>& path, int k, int j) {
    if(k == 1){
        path.push_back(n);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it : path) {
            if(mini > it) mini = it;
            if(maxi < it) maxi = it;

        }
        if(bestdiff > maxi - mini) {
            bestPath = path;
            bestdiff = maxi-mini;
        }
        path.pop_back();
        return;
    }
    for(int i = j ;i < divisors.size(); i++) {
        if(n % divisors[i] == 0) {
            path.push_back(divisors[i]);
            recurse(n/divisors[i], divisors, path, k-1, i);
            path.pop_back();
        }
    }
}

void store_divisor(int n, vector<int>& divisors) {
    for(int i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            if(i * i == n) divisors.push_back(i);
            else {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
}
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        vector<int> vec;
        store_divisor(n, divisors);
        bestdiff = INT_MAX;
        bestPath.clear();
        recurse(n, divisors, vec, k, 0);
        return bestPath;
    }
};