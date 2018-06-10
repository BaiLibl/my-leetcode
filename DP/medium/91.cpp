#include<iostream>
#include<vector>
using namespace std;

int numDecodings(string s) {
	if(s.length()<1)return s.length();
    if(s[0]=='0')return 0;
    if(s.length()==1)return 1;
	int i;
	vector<int> dp(s.length()+1,0);
	dp[0]=1;
	for(i=1;i<s.length();i++){
		if(s[i]=='0'){
			if(s[i-1]=='0'||s[i-1]>'2'){
				return 0;
			}else{
				if(i>1)dp[i]=dp[i-2];
				else{
					dp[i]=1;
				}
			}
		}else{
			if(s[i-1]=='0'||s[i-1]>'2'||(s[i-1]=='2'&&s[i]>'6'))dp[i]=dp[i-1];
			else{
				if(i==1){
					dp[i]=dp[i-1]+1;
				}else{
					dp[i]=dp[i-2]+dp[i-1];
				}
			}
		}
	}      
	return dp[s.length()-1];
}

int main(){
	while(1){
		string s;
		cin>>s;
		cout<<'*'<<numDecodings(s)<<endl;
	}
	return 0;
}
