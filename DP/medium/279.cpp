#include<iostream>
#include<vector>
using namespace std;

int numSquares(int n) {
	if(n==0)return 0;
	if(n==1)return 1;
	vector<int> num;
	int i,j;
	//for(i=1;i*i<=n;i++)num.push_back(i*i);
	//��֣�����num����Ͳ����ԣ��ڱ�����ʵ��Ҳ�ǿ��Եģ��������ύʱ�Ͳ�����
	vector<int> dp(n+1,n);
	dp[0]=0;
	dp[1]=1;
	for(i=2;i<=n;i++){
		//for(j=0;j<num.size();j++){
		for(j=1;j*j<=i;j++)
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
	}        
  	return dp[n];
}

int main(){
	cout<<numSquares(11)<<endl;
	return 0;
}
