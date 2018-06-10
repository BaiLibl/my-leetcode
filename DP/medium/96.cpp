#include<iostream>
#include<vector>
using namespace std;

int numTrees(int n) {
	if(n<=0)return 0;
	if(n==1)return 1;
	if(n==2)return 2;
	vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    int i,j;
    for(i=2;i<=n;i++){
    	int sum=0;
    	for(j=1;j<=i;j++){
    		sum+=dp[j-1]*dp[i-j];//以J为根结点
    	}
    	dp[i]=sum;
    }
    return dp[n]; 
	        
}

int main(){
	int i;
	while(1){
		cin>>i;
		cout<<numTrees(i)<<endl;
	}
	return 0;
}
