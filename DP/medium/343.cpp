#include<iostream>
#include<vector>
using namespace std;

int integerBreak(int n) {
	if(n<2)return 0;
	vector<int> dp(n+1,0);
	dp[1]=1;
	dp[2]=1;
	int i,j;
	for(i=3;i<=n;i++){
		for(j=1;i-j>=1;j++){
			dp[i]=max(dp[i],dp[i-j]*j);
			dp[i]=max(dp[i],(i-j)*j);
		}
	//	cout<<i<<' '<<dp[i]<<endl;
	}        
	return dp[n];
}

int main(){
	cout<<integerBreak(10)<<endl;
	return 0;
}
