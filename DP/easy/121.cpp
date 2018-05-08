#include<iostream>
#include<vector>
using namespace std;

//在第i天卖出和不卖出两种情况 
int maxProfit(vector<int>& prices) {
	if(prices.size()<=1)return 0;
	vector<int> dp(prices.size(),0);
	int i,minp=prices[0];
	int res=0;
	for(i=0;i<prices.size();i++){
		minp=min(minp,prices[i]);
		dp[i]=max(dp[i],prices[i]-minp);
		res=max(res,dp[i]);
	}
	return res;
	
}

int main(){
	int x[]={7,1,5,3,6,4};
	vector<int> a(x,x + sizeof(x) / sizeof(x[0]));
	cout<<maxProfit(a)<<endl;
	return 0;
}
