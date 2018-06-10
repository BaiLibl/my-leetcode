#include<iostream>
using namespace std;

//当K是质数时，只能用k步粘贴完成 
//转化成质数分解 
//能分尽量分解
// 2+f(n/2) 3+f(n/3).... 

int minSteps(int n) {
    if(n<=1)return 0;
	int res = 0;
	int i;
	int k =n;
	for(i=2;i<=n&&k!=1;i++){
		while(k%i==0){ //9=3*3
			res+=i;//已经分解了，多次除以 
			k=k/i;
		} 
	}	       
	return res;
}
/*
2*i是i基础上粘贴复制2个动作，2*i+i是在 i基础上粘贴复制2个动作再加上1个复制动作
dp[j]=min(dp[j],dp[i]+k) j=2*i+(k-2)*i 
*/ 
 int minSteps(int n)
    {   if(n==1)return 0;
        if(n<=3)return n;
        vector<int> dp(1002,0);
        int i,j;
        dp[1]=0;
        for(i=2;i<1002;i++)dp[i]=i;
        for(i=1;i<1002;i++){
            int k=2;
            for(j=2*i;j<1002;j+=i){
                dp[j]=min(dp[j],dp[i]+k);
                k++;//j+i 拷贝一次
            }
        }
        return dp[n];
    }
int main(){
	int a=2;
	cout<<minSteps(a)<<endl;
	return 0;
}
