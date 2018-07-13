#include<iostream>
#include<vector>
#include<map> 
using namespace std;

int res=0;
void dfs(vector<int> &nums,int index,int sum){
	if(index==nums.size()){
		if(sum==0)res++;
		return;
	}else{
		dfs(nums,index+1,sum-nums[index]);
		dfs(nums,index+1,sum+nums[index]);
	}
}
int findTargetSumWays(vector<int>& nums, int S) {
    dfs(nums,0,S);
	return res;        
}

/*
DP:sum=s1+s2 sum的种数由count(s1)*count(s2) 
*/ 
int findTargetSumWays2(vector<int>& nums, int S) {
    
	map<int,int> dp;//记录sum-count
	dp[0]=1;//等于0只有1种，非负数
	int i,j;
	for(i=0;i<nums.size();i++){
		map<int,int> t;
		for(auto a:dp){
			int sum=a.first,count=a.second;
			t[sum+nums[i]]+=count*1;//nums[i]只是一个数字
			t[sum-nums[i]]+=count*1; 
		}
		dp=t;
	} 
	 return dp[S];
}


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	cout<<findTargetSumWays(a,3)<<endl;
	return 0;
}
