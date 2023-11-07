#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums, int ash, int babe, int kanak, int& reversePairsCount){
        int j = babe+1;
        for(int i=ash; i<=babe; i++){
            while(j<=kanak && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(babe+1);
        }
        int size = kanak-ash+1;
        vector<int> temp(size, 0);
        int left = ash, right = babe+1, k=0;
        while(left<=babe && right<=kanak){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=babe){
            temp[k++] = nums[left++]; 
        }
        while(right<=kanak){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=ash; i<=kanak; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

    int reversePairs(vector<int>& nums,int n) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
