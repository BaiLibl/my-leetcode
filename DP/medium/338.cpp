#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int num) {
	vector<int> dp(num+1,0);
	if(num==0)return dp;
	if(num==1){
		dp[1]=1;
		return dp;
	}
	int i;
	for(i=1;i<=num;i++){
		if((i-1)%2!=0){
			dp[i]=dp[(i-1)/2+1];
			//cout<<i<<endl;
		}else{
			dp[i]=dp[i-1]+1;
		}
		//cout<<i<<' '<<dp[i]<<endl;
	}        
	//for(i=0;i<dp.size();i++)cout<<dp[i]<<' ';
	return dp;
}

int main(){
	vector<int> a=countBits(8);
	return 0;
}
