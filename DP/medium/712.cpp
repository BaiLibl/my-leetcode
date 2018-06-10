#include<iostream>
#include<vector>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
  int m=s1.length(),n=s2.length();
	vector< vector<int> > dp(m+1,vector<int>(n+1,0));
	//���⿼��dp[0][*]��dp[*][0]
	//dp[i+1][j+1]��¼s1��i��ʼ��s2��j��ʼ����С���� 
	int i,j;
	for(i=0;i<n;i++){
		dp[0][i+1]=dp[0][i]+s2[i];
	} 
    for(i=0;i<m;i++){
		dp[i+1][0]=dp[i][0]+s1[i];
	} 
	//����i-1��j-1Խ������ 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(s1[i]==s2[j]){
				dp[i+1][j+1]=dp[i][j];//�����ȵĻ��Ͳ�ɾ 
			}else{
				dp[i+1][j+1]=min(dp[i][j+1]+s1[i],dp[i+1][j]+s2[j]);//��s1ɾ������s2��ɾ�� 
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
