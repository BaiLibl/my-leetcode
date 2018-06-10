#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector< vector<int> >& grid) {
	if(grid.size()==0)return 0;
	int m=grid.size();
	int n=grid[0].size();
	vector< vector<int> > dp(m+1,vector<int>(n+1,0));
	int i,j;
	dp[0][0]=grid[0][0];
	for(i=1;i<n;i++)dp[0][i]=dp[0][i-1]+grid[0][i];       
	for(j=1;j<m;j++)dp[j][0]=dp[j-1][0]+grid[j][0];
	//cout<<m<<' '<<n<<endl;
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
		//cout<<i<<' '<<j<<endl;
		}
	}
	return dp[m-1][n-1];
}

int main(){
	vector<int> a;
	vector< vector<int> > b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	b.push_back(a);
	//a[1]=5;
	a[0]=3;
	a[1]=2;
	a[2]=1;
	b.push_back(a);
	//a[0]=4;
	//a[1]=2;
	//b.push_back(a);
	cout<<minPathSum(b)<<endl;
	return 0;
}
