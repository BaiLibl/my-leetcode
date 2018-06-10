#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	if(amount<0)return -1;
	if(amount==0)return 0;	
	//用贪心不行
	vector<int> dp(amount+1,0);
	int i,j;
	for(i=1;i<=amount;i++){
		dp[i]=0x7fffffff;//最大值 
		for(j=0;j<coins.size();j++){
			if(i>=coins[j]&&dp[i-coins[j]]!=0x7fffffff){
				dp[i]=min(dp[i],dp[i-coins[j]]+1);
			}
		}
	} 
	if(dp[amount]==0x7fffffff){
		return -1;
	}else{
		return dp[amount];
	}
	/*
	if(amount<0)return -1;
	if(amount==0)return 0;
	int res=0;
	sort(coins.begin(),coins.end());//sort
	int sum=amount;
	int k=coins.size()-1;
	while(sum>0&&k>=0){
		int c=sum/coins[k];
		sum=sum-c*coins[k];
		cout<<c<<' '<<coins[k]<<endl;
		res+=c;
		k--;
	}
	
	if(sum==0){
		return res;
	}else{
		return -1;
	}
	*/
}

int main(){
	vector<int> c;
	c.push_back(186);
	c.push_back(419);
	c.push_back(83);
	c.push_back(408);
	cout<<coinChange(c,6249);
	return 0;
}
