#include<iostream>
#include<vector>
#include<map>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
	if(nums.size()==0)return 0;
	if(nums.size()==1)return nums[0];
	int mmax=nums[0];
	int i,j;
	for(i=0;i<nums.size();i++)mmax=max(mmax,nums[i]);
	vector<int> dp(mmax+1,0);
	vector<int> cnt(mmax+1,0);
	for(i=0;i<nums.size();i++)cnt[nums[i]]++;
	dp[0]=0;
	dp[1]=cnt[1];
	for(i=2;i<=mmax;i++){
		dp[i]=max(dp[i-1],cnt[i]*(i)+dp[i-2]);
	}
	//cout<<mmax<<endl;
	return dp[mmax];
}

int main(){
	int x[]={3,1};
	vector<int> v(x,x+sizeof(x)/sizeof(x[0]));
	cout<<deleteAndEarn(v)<<endl;
	return 0;
}
