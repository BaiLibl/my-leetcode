class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        sort(nums.begin(),nums.end());
        int i,j=0;
        for(i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>j)j=nums[i]-nums[i-1];
        }
        return j;
    }
};
