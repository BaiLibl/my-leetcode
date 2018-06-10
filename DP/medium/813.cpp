#include<iostream>
#include<vector>
using namespace std;

double largestSumOfAverages(vector<int>& A, int K) {
	int len=A.size();
	vector<double> pre(len,0.0);
	pre[0]=A[0]; 
	for (int i = 1; i < len; ++i) { 
		pre[i] = pre[i - 1] + A[i]; 
	} 
	vector<vector<double>> dp(K,vector<double>(A.size(),0));
 	for (int k = 0; k < K; ++k) { 
 	for (int i = 0; i < len; ++i) {
  		dp[k][i] = k == 0 ? pre[i]/(i + 1) : dp[k - 1][i]; //先用不分割进行初始化 
  		if (k > 0) { 
 			 for (int j = i - 1; j >= 0; --j) {
   				dp[k][i] = max(dp[k][i], dp[k - 1][j] + (pre[i] - pre[j]) / (i - j)); 
   				} 
   			} 
   		} 
    } 
   return dp[K - 1][len - 1];         
}

int main(){
	return 0;
}
 
