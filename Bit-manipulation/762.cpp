#include<iostream>
#include<vector>
#include<map>
using namespace std;

//求素数的算法很赞 
bool isprime(int n){
 		if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
}
int countPrimeSetBits(int L, int R) {
	int i,res=0;
    vector<int> dp(R+1,0);
    map<int,int> mp;
	dp[0]=0;
	dp[1]=1;
	for(i=2;i<=R;i++){
		if(i%2==0){
			dp[i]=dp[i/2];
		}else{
			dp[i]=dp[i/2]+1;
		}
	}      
	for(i=L;i<=R;i++){
		if(mp.find(dp[i])==mp.end()){
			if(isprime(dp[i])){
				res++;
				mp[dp[i]]=1;
			}
		}else{
			res++;
		}
	}
	return res;
} 

int main(){
	while(1){
		int a,b;
		cin>>a>>b;
		cout<<countPrimeSetBits(a,b)<<endl;
	}
	return 0;
} 
