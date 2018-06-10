#include<iostream>
#include<vector>
using namespace std;

int dirs[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
double dfs(vector<vector<vector<double> > >& dp,int N,int k,int r,int c){
	if(r<0||c<0||r>=N||c>=N)return 0; //终止条件一定得写正确 
	if(k==0)return 1.0;
	
	if(dp[k][r][c]!=-1.0)return dp[k][r][c];
	dp[k][r][c]=0.0;
	int i=0;
	for(i=0;i<8;i++){
		dp[k][r][c]+=dfs(dp,N,k-1,r-dirs[i][0],c-dirs[i][1])/8;
	}
	return dp[k][r][c];
} 
//第k步在[r,c]位置上与k-1步在其他八个位置上有关 
double knightProbability(int N, int K, int r, int c) {
	if(r<0||c<0||r>=N||c>=N)return 0; //终止条件一定得写正确 
	if(K==0)return 1.0;
	double res=0.0;
	/*int i;
	for(i=0;i<8;i++){
		double p = knightProbability(N,K-1,r+dirs[i][0],c+dirs[i][1]);
		res+= (p/8);
	}*/
	//K+1：0-K 
	vector<vector<vector<double> > > dp(K+1,vector<vector<double> >(N,vector<double>(N,-1.0)));
	res = dfs(dp,N,K,r,c);
	return res;	        
}

int main(){
	cout<<knightProbability(3,2,0,0)<<endl;
	return 0;
}
