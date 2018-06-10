#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//dp[i][j]记录ij的最大边长 
int maximalSquare(vector< vector<char> >& matrix) {
	if(matrix.size()==0)return 0;
	int m=matrix.size(),n=matrix[0].size();
	vector< vector<int> > dp(m,vector<int>(n,0));
	int i,j,res=0;
	for(i=0;i<n;i++){
		dp[0][i]=matrix[0][i]-'0';
		res=max(res,dp[0][i]);	
	}
	for(j=0;j<m;j++){
		dp[j][0]=matrix[j][0]-'0';
		res=max(res,dp[j][0]);
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(matrix[i][j]=='1'){
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
			res=max(res,dp[i][j]);
		}
	}
    return res*res;
}

int main(){
	vector<char> a;
	a.push_back('1');
	a.push_back('1');
	a.push_back('1');
	a.push_back('1');
	vector< vector<char> > b;
	b.push_back(a);
	b.push_back(a);
	b.push_back(a);
	cout<<maximalSquare(b)<<endl;
	return 0;
}
