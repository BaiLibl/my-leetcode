#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
	/*
	//只考虑正数情况 
	int i;
	int m=nums[0];
	
	for(i=1;i<nums.size();i++)m=min(nums[i],m);
	vector<int> dp(nums.size(),m);
	dp[0]=nums[0];
	for(i=1;i<nums.size();i++){
		int tmp=max(dp[i],nums[i]);
		dp[i]=max(tmp,dp[i-1]*nums[i]);
	}
	int res=dp[0];
	for(i=1;i<nums.size();i++){
		res=max(res,dp[i]);
	}
	return res;
	*/
	//考虑正数和负数情况，累乘法正数最大值，负数最小值
	if(nums.size()==0)return 0;
	int minval=nums[0];
	int maxval=nums[0];
	int i;
	int res=nums[0];
	for(i=1;i<nums.size();i++){
		int a=minval*nums[i];
		int b=maxval*nums[i];
		minval=min(min(a,b),nums[i]);//累乘最小值 
		maxval=max(max(a,b),nums[i]);//累乘最大值 
		res=max(maxval,res);
	} 
	return res;    
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(12);
	a.push_back(-5);
	a.push_back(-6);
	a.push_back(50);
	a.push_back(3);
	cout<<maxProduct(a)<<endl;
	return 0;
}
