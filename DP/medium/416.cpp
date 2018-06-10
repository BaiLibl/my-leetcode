#include<iostream>
#include<vector>
#include<map>
using namespace std;

//变形的背包问题 
bool canPartition(vector<int>& nums) {
	if(nums.size()==0)return false;
	int i,j,sum=0;
	for(i=0;i<nums.size();i++)sum+=nums[i];
	if(sum%2!=0)return false;
	vector< vector<int> > dp(nums.size()+1,vector<int>(sum/2+1,0));
	//dp[i][j]在背包容量为j的情况下，放入前i个物品，所得到的最大收益 
	sum=sum/2;
	for(i=nums[0];i<=sum;i++){
		dp[0][i]=nums[0];//只能放入nums[0] 
	}
	for(i=1;i<nums.size();i++){
		for(j=nums[i];j<=sum;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
			//前i件物品组合在容量为j的背包的最优解。
		}
	}
	if(dp[nums.size()-1][sum]==sum)return true;
	return false;
}

int main(){
	return 0;
} 
