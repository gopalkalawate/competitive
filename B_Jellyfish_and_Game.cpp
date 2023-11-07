#include<bits/stdc++.h>
using namespace std;
void heapify(vector <int> &nums){
        int n = nums.size();
        for(int i=n-1;i>0;i--){
        if(i==1){
            if(nums[0]<nums[1]){
                swap(nums[1],nums[0]);
                continue;
            }
        }
        if(i&1){
            if(nums[i]>nums[(i-2)/2]){
                swap(nums[i],nums[(i-2)/2]);
            }
        }
        else{
            if(nums[i]>nums[(i-1)/2]){
                swap(nums[i],nums[(i-1)/2]);
            }
        }
    }
}

int main(){
    vector <int> a = {15,5,20,1,17,10};
    heapify(a);
    for(auto it : a){
        cout<<it<<' ';
    }
}