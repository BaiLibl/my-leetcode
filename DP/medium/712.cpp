#include<iostream>
#include<vector>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
  int m=s1.length(),n=s2.length();
	vector< vector<int> > dp(m+1,vector<int>(n+1,0));
	//特殊考虑dp[0][*]和dp[*][0]
	//dp[i+1][j+1]记录s1从i开始，s2从j开始的最小花费 
	int i,j;
	for(i=0;i<n;i++){
		dp[0][i+1]=dp[0][i]+s2[i];
	} 
    for(i=0;i<m;i++){
		dp[i+1][0]=dp[i][0]+s1[i];
	} 
	//避免i-1和j-1越界的情况 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(s1[i]==s2[j]){
				dp[i+1][j+1]=dp[i][j];//如果相等的话就不删 
			}else{
				dp[i+1][j+1]=min(dp[i][j+1]+s1[i],dp[i+1][j]+s2[j]);//从s1删除或者s2中删除 
			}
		}
	}      
	return dp[m][n];  
    
}

int main(){
	string a="delete",b="leet";
	cout<<minimumDeleteSum(a,b)<<endl;
	return 0;
}
