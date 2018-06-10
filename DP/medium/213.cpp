#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
	if(nums.size()==0)return 0;
	if(nums.size()==1)return nums[0];
	int i,res;
	vector<int> dp(nums.size()+1,0);
	int v0,v1,v2;
	//偷第一家
	dp[0]=nums[0];
	dp[1]=nums[0];
	for(i=2;i<nums.size()-1;i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
	}
	res=dp[nums.size()-2];
	//不偷第一家        
	dp[0]=0;
	dp[1]=nums[1];
	for(i=2;i<nums.size();i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
	}
	res=max(res,dp[nums.size()-1]);
	return res;
}

int main(){
	return 0;
}
