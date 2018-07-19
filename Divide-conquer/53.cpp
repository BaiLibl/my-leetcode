#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int n=nums.size();
	if(n==0)return 0;
	vector<int> dp(n,0);
	int i;
	dp[0]=nums[0];
	int sum=dp[0];
	for(i=1;i<n;i++){
		dp[i]=max(nums[i],dp[i-1]+nums[i]);
        sum = max(sum,dp[i]);
	}       
	return sum;
}

int maxSubArray2(vector<int>& nums) {
	if(nums.size()==0)return 0;
	if(nums.size()==1)return nums[0];
	int res=nums[0];
	int pre,cur;
	int i;
	pre=nums[0];
	for(i=1;i<nums.size();i++){
		cur=max(nums[i],pre+nums[i]);
		pre=cur;
		res=max(res,pre);
	} 
	return res;
        
}
//分治
/*
最大子序列可能在a[0...n/2] ：直接递归即可 
            或者a[n/2+1...n]：直接递归即可 
			或者在同时在前后个一部分中即是 a[i...n/2] a[n/2+1...j] ：找到前面的和后面的 
*/ 
int divide(vector<int>& nums,int left,int right){
    if(left>right)return 0;
    if(left==right)return nums[left];
    int mid=left+(right-left)/2;
    int i,sum,leftmax,rightmax;
    sum=nums[mid];
    leftmax=nums[mid];
    rightmax=nums[mid+1];
    for(i=mid-1;i>=left;i--){
        sum+=nums[i];
        leftmax=max(sum,leftmax);
    }
    sum=nums[mid+1];
    for(i=mid+2;i<=right;i++){
        sum+=nums[i];
        rightmax=max(rightmax,sum);
    }
    int amax=divide(nums,left,mid);
    int bmax=divide(nums,mid+1,right);
    int cmax=leftmax+rightmax;
    return max(max(amax,bmax),cmax);
}
    
int maxSubArray(vector<int>& nums){
    return divide(nums,0,nums.size()-1);
}
int main(){
	vector<int> a;
	a.push_back(-2);
	//a.push_back(-1);
	//a.push_back(-1);
	//a.push_back(-9);
	//a.push_back(-6);
	cout<<maxSubArray(a)<<endl;
	return 0;
}
