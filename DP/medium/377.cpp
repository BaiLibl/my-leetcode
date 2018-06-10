#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	if(target<0||nums.size()==0)return 0;
	vector<int> dp(target+1);
	dp[0]=1;
	int i,j;
	for(i=1;i<=target;i++){
		for(j=0;j<nums.size();j++){
			int tmp=i-nums[j];
			if(tmp>=0){
				dp[i]+=dp[tmp];
			}
		}
	}
	return dp[target];
	        
}

int main(){
	return 0;
}
