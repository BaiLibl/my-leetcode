#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
	int m=obstacleGrid.size();
	if(m==0)return 0;
	int n=obstacleGrid[0].size();
	int i,j;
	if(obstacleGrid[0][0]==1)return 0;
	vector< vector<int> > dp(m+1,vector<int>(n+1,0));
	dp[0][0]=1;
	for(i=1;i<n;i++){
		dp[0][i]=dp[0][i-1];
		if(obstacleGrid[0][i]==1)dp[0][i]=0;
	}
	for(j=1;j<m;j++){
		dp[j][0]=dp[j-1][0];
		if(obstacleGrid[j][0]==1)dp[j][0]=0;
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(obstacleGrid[i][j]==1){
				dp[i][j]=0;
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
			}
		}
	}
	return dp[m-1][n-1];
}

int main(){
	return 0;
}
