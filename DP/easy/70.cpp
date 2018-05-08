#include<iostream>
#include<vector>
using namespace std;

/*
ì³²¨ÄÇÆõÊý×é£ºS(n)=S(n-1)+S(n-2)
S(1)=1 S(2)=2 
*/

int climbStairs(int n) {
	if(n<=2)return n;
	vector<int> dp(n+1,0);
	int i;
	dp[1]=1;
	dp[2]=2;
	for(i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}        
	return dp[n];
}

int main(){
	while(true){
		int n;
		cin>>n;
		cout<<climbStairs(n)<<endl;
	}
	return 0;
}
