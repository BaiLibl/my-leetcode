#include<iostream>
#include<vector>
using namespace std;

bool isugly(int n){
	while(n%2==0){
		n=n/2;
	}
	while(n%3==0){
		n=n/3;
	}
	while(n%5==0){
		n=n/5;
	}
	if(n==1)return true;
	return false;
}
int nthUglyNumber(int n) {
	if(n<=0)return 0;
	if(n==1)return 1;
	int u=1;
	int i;
	vector<int> dp(n+1,0);
	dp[1]=1;
	int v2=1,v3=1,v5=1;
	for(i=2;i<=n;i++){
		u=min(dp[v2]*2,dp[v3]*3);
		u=min(u,dp[v5]*5);
		dp[i]=u;
		if(u==dp[v2]*2)v2++;
		if(u==dp[v3]*3)v3++;
		if(u==dp[v5]*5)v5++;
	}
	return dp[n];
}
/*
        int u = 0;  
        vector<int> l1,l2,l3;   
        l1.push_back(1);  
        l2.push_back(1);  
        l3.push_back(1);  
          
        for(int i=0; i<n; i++) {  
            u = min(min(l1[0], l2[0]), l3[0]);  
              
            if(l1[0] == u) l1.erase(l1.begin());  
            if(l2[0] == u) l2.erase(l2.begin());  
            if(l3[0] == u) l3.erase(l3.begin());  
              
            l1.push_back(u*2);  
            l2.push_back(u*3);  
            l3.push_back(u*5);  
        }  
        return u; 
*/
int main(){
	int n=1;
	while(n<40){
		//int n;
		//cin>>n;
		
		cout<<nthUglyNumber(n)<<' ';
		//cout<<isugly(n)<<endl;
		n++;
	}
	return 0;
}
