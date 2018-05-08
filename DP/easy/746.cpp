#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	if(cost.size()<=1)return 0;
	int i;
	vector<int> dp(cost.size()+1,INT_MAX); 
	dp[0]=cost[0];
	dp[1]=cost[1];
	for(i=2;i<cost.size()+1;i++){
		if(i==cost.size()){
			dp[i]=min(dp[i-1],dp[i-2]);
		}else{
			dp[i]=min(dp[i-1],dp[i-2])+cost[i];
		}
	}       
	return dp[cost.size()];
}

int main(){
	//int x[] = {10,15,20};
	int x[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	vector<int> v(x, x + sizeof(x) / sizeof(x[0]));
	cout<<minCostClimbingStairs(v)<<endl;
	return 0;
}
