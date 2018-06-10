#include<iostream>
#include<vector>
using namespace std;
//����a�յĸ���+��a����b�ո��ʣ���һ��
//����ֵ����Χ��������4800ʱ�����ʻ�������1���ɽ��ܷ�Χ
//��N�ܴ�ʱ��b���ٱ����� 
/*
    Serve 100 ml of soup A and 0 ml of soup B ==> 1.0
    Serve 75 ml of soup A and 25 ml of soup B ==> 1.0
    Serve 50 ml of soup A and 50 ml of soup B ==>0.5
    Serve 25 ml of soup A and 75 ml of soup B ==> 0
*/
double dfs(vector< vector<double> >& dp,int i,int j){
	if(i<=0&&j<=0)return 0.5;//��3����� 
	if(i<=0)return 1.0;
	if(j<=0)return 0.0;
	if(dp[i][j])return dp[i][j];
	dp[i][j]=0.25*(dfs(dp,i-4,j)+dfs(dp,i-3,j-1)+dfs(dp,i-2,j-2)+dfs(dp,i-1,j-3));
	return dp[i][j];
}
double soupServings(int N) {
	//if(N>=4800)return 1.0;
	N=(N%25==0?N/25:N/25+1);//��25MLΪ��λ
	//cout<<N<<endl;
	vector<vector<double> > dp(N+1,vector<double>(N+1,0));
	//dp[i][j]=0.25*(dp[i-4][j]+dp[i-3][j-1]+dp[i-2][j-2]+dp[i-1][j-3]) 
	return dfs(dp,N,N);    
}

int main(){
	cout<<soupServings(5000)<<endl;
	return 0;
} 
