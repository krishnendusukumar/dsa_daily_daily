class Solution {
public:

    int findInd(vector<int> arr, int left, int right, int target) {
        if(left > right) return -1;
        int mid = left + (right- left) / 2;

        if(arr[mid] == target) return mid;
        int ans1 = findInd(arr, left, mid-1, target);
        int ans2 = findInd(arr, mid+1, right, target);

        if(ans1 == -1 && ans2 == -1) return -1;
        else if(ans1 != -1) return ans1;
        else return ans2;
    }

    int search(vector<int>& nums, int target) {
        return findInd(nums, 0, nums.size() - 1, target);
    
    }
};