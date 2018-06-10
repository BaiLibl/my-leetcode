#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {
   if(m<=0||n<=0)return 0;
   if(m==1&&n==1)return 1;
   int i,j;
   vector< vector<int> > dp(m+1,vector<int>(n+1,0));
   dp[0][0]=1;
   for(i=1;i<m;i++)dp[i][0]=1;
   for(j=1;j<n;j++)dp[0][j]=1;
   for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
   }
   return dp[m-1][n-1];
   /*
   //���ٿռ临�Ӷȣ��ռ��ظ����ã��ռ���ת���� 
   int s[n];
    // ��һ��ȫΪ1
	for(int i = 0;i < n;++i){s[i] = 1;}//for
    // �ӵڶ��п�ʼ
    for(int i = 1;i < m;++i){
    // ��i�е�j����
        for(int j = 1;j < n;++j){
           s[j] = s[j] + s[j-1];
         }//for
     }//for
     return s[n-1];
   
   */
       
	    
}

int main(){
	cout<<uniquePaths(2,2)<<endl;
	return 0;
}
