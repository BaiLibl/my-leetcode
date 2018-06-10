#include<iostream>
#include<vector> 
#include<climits>
using namespace std;

//动态规划题
//保证能赢的最少的钱 


int cost(vector< vector<int> > dp, int start, int end){
	// = INT_MAX;
	if(start>=end){
		return 0;
	}else if(dp[start][end]!=0){
		return dp[start][end];
	}else{
		int i;
		//int res=0;
		dp[start][end] =INT_MAX;
		for(i=start;i<=end;i++){
			dp[start][end] =min(dp[start][end],i+max(cost(dp,start,i-1),cost(dp,i+1,end)));
		}
	}
	return dp[start][end];
}

int getMoneyAmount(int n) {
	 vector< vector<int> > dp(n+1,vector<int>(n+1,0));
	 return cost(dp,1,n); 
}

int main(){
	int a=10;
	cout<<getMoneyAmount(a)<<endl;
	return 0;
}
