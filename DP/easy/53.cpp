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
