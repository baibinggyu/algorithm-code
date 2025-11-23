#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<double> arr;
            for(int i = 0;i < nums1.size();i++) arr.push_back(nums1[i]);
            for(int i = 0;i < nums2.size();i++) arr.push_back(nums2[i]); 
            sort(arr.begin(),arr.end());
            if(arr.size() % 2 == 0) return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2;
            else return arr[arr.size() / 2];
        }
    };