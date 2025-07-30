#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int totalLength = n + m;
        
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge the two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements of nums1 if any
        while (i < n) {
            merged.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements of nums2 if any
        while (j < m) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        // Calculate median
        if (totalLength % 2 == 1) {
            return merged[totalLength / 2];  // Odd length, middle element
        } else {
            // Even length, average of two middle elements
            return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
        }
    }
};
