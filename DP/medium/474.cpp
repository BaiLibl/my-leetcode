#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//以时间换空间
//如果是三维的就不可以 

int findMaxForm(vector<string>& strs, int m, int n) {
	if(strs.size()==0)return 0;
    vector< vector<int> > dp(m+1,vector<int>(n+1,0));
    int i,j,k,p;
    int res=0;
    for(k=0;k<strs.size();k++){
    	string str = strs[k];
    	int c0=0;
    	int c1=0;
    	for(p=0;p<str.length();p++){
    		char c=str[p];
    		if(c=='0')c0++;
    		else{
    			c1++;
    		}
    	}
    	for(i=m;i>=c0;i--){
    		for(j=n;j>=c1;j--){
    			dp[i][j]=max(dp[i][j],dp[i-c0][j-c1]+1);
    			res=max(res,dp[i][j]);
    		}
    	}
    }
    return res;
    
}

int main(){
	vector<string> a;
	a.push_back("10");
	a.push_back("0001");
	a.push_back("111001");
	a.push_back("1");
	a.push_back("0");
	cout<<findMaxForm(a,5,3)<<endl;
	return 0;
}
