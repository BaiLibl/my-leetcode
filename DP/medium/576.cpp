#include<iostream>
#include<vector>
using namespace std;
    //��������N������m*n��ÿһ��λ�õ�·����С����󷵻�dp[N][i][j]
    //N��ʱ���ϵģ�m*n�ǿռ��ϵ�
int findPaths(int m, int n, int N, int i, int j) {
	int dp[51][50][50];//N [0,50] m[1,50],n[1,50]
	int mi,ni,k;
	for(k=0;k<=N;k++){
		for(mi=0;mi<m;mi++){
			for(ni=0;ni<n;ni++){
				if(k==0){
					dp[k][mi][ni]=0;
					continue;
				}
				//���߽�Ļ���ֻ��1��ѡ�� 
				//������mi-1 >=0
				//������mi+1 <m
				//������ni-1 >=0
				//������ni+1 <n 
				dp[k][mi][ni]=((mi==0?1:dp[k-1][mi-1][ni])+(long)(ni==0?1:dp[k-1][mi][ni-1])+(mi==m-1?1:dp[k-1][mi+1][ni])+(ni==n-1?1:dp[k-1][mi][ni+1]))%1000000007;;	
				
			}
		}
	} 
	return dp[N][i][j];       
}
//dp[Ni][mi][ni]=((long long) (!mi?1:dp[Ni-1][mi-1][ni])+(mi==m-1?1:dp[Ni-1][mi+1][ni])+
 // (!ni?1:dp[Ni-1][mi][ni-1])+(ni==n-1?1:dp[Ni-1][mi][ni+1]))%1000000007;
int main(){
	return 0;
}
